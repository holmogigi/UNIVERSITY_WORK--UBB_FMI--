#include "HTMLRepository.h"
#include <algorithm>
#include <fstream>

HTMLRepo::HTMLRepo(const std::vector<Event> &list, const std::string &userFilename) {
    this->list = list;
    this->userFilename = userFilename;
}

std::vector<Event>& HTMLRepo::getAllUsersRepo() {
    return this->list;
}

unsigned int HTMLRepo::getCapacity() {
    return this->list.capacity();
}

unsigned int HTMLRepo::getSize() {
    return this->list.size();
}

void HTMLRepo::addUserRepo(const Event &event) {
    this->list.push_back(event);
    this->writeToFile();
}

void HTMLRepo::removeUserRepo(unsigned int index) {
    this->list.erase(this->list.begin() + index);
    this->writeToFile();
}

int HTMLRepo::search(const std::string &link) {
    int index = -1;
    std::vector<Event>::iterator iter;
    iter = std::find_if(this->list.begin(), this->list.end(), [&link](Event& event) {return event.get_link() == link;});
    if(iter != this->list.end())
        index = iter - this->list.begin();
    return index;
}

void HTMLRepo::writeToFile() {
    std::ofstream fout(this->userFilename);
    fout << "<!DOCTYPE html>\n<html><head><title>List</title></head><body>\n";
    fout << "<table border=\"1\">\n";
    fout << "<tr><td>Title</td><td>Description</td><td>Date</td><td>Number of people</td><td>Link</td></tr>\n";
    for(const Event& event: this->list){
        fout<< "<tr><td>" << event.get_title() << "</td>"
            << "<td>" << event.get_description() <<"</td>"
            << "<td>" << event.get_date_time() <<"</td>"
            << "<td>" << std::to_string(event.get_number_people()) << "</td>"
            << "<td><a href=\"" << event.get_link() << "\">" << event.get_link() << "</a></td>" << '\n';
    }
    fout << "</table></body></html>";
    fout.close();
}

std::string &HTMLRepo::getFilename() {
    return this->userFilename;
}

HTMLRepo::~HTMLRepo() = default;