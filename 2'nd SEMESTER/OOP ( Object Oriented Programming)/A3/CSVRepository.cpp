#include "CSVRepository.h"
#include <fstream>
#include <algorithm>

CSVRepo::CSVRepo(const std::vector<Event> &list, const std::string &userFilename) {
    this->list = list;
    this->userFilename = userFilename;
}

std::vector<Event> &CSVRepo::getAllUsersRepo() {
    return this->list;

}

unsigned int CSVRepo::getSize() {
    return this->list.size();
}

unsigned int CSVRepo::getCapacity() {
    return this->list.capacity();
}

void CSVRepo::addUserRepo(const Event &event) {
    this->list.push_back(event);
    this->writeToFile();
}

void CSVRepo::removeUserRepo(unsigned int index){
    this->list.erase(this->list.begin() + index);
    this->writeToFile();
}

int CSVRepo::search(const std::string &link) {
    int index = -1;
    std::vector<Event>:: iterator iter;
    iter = std::find_if(this->list.begin(), this->list.end(), [&link](Event& event) {return event.get_link() == link;});
    if(iter != this->list.end())
        index = iter - this->list.begin();
    return index;
}

void CSVRepo::writeToFile() {
    std::ofstream fout(this->userFilename);
    if(!this->list.empty()){
        for(const Event& event: this->list){
            fout<<event<<"\n";
        }
    }
    fout.close();
}

std::string &CSVRepo::getFilename() {
    return this->userFilename;
}

CSVRepo::~CSVRepo() = default;