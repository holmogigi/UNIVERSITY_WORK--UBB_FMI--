#include "repository.h"
#include <string>
#include <algorithm>
#include <fstream>

RepositoryException::RepositoryException(std::string &_message): message(_message) {}

const char* RepositoryException::what() const noexcept {
    return message.c_str();
}

Repository::Repository(std::vector<Event> &repo_vector, std::string &eventFile) {
    this->database = repo_vector;
    this->eventFile = eventFile;
}

void Repository::loadEventsFromFile() {
    if(!this->eventFile.empty()){
        Event eventFromFile;
        std::ifstream fin(this->eventFile);
        while(fin >> eventFromFile){
            if(std::find(this->database.begin(), this->database.end(), eventFromFile) == this->database.end())
                this->database.push_back(eventFromFile);
        }
        fin.close();
    }
}

void Repository::writeEventsToFile() {
    if(!this->eventFile.empty()){
        std::ofstream fout(this->eventFile);
        for(const Event& event: this->database){
            fout<<event<<"\n";
        }
        fout.close();
    }
}

void Repository::initialiseRepo() {
    this->loadEventsFromFile();
}

std::vector<Event>& Repository::getRepo() {
    if(this->database.empty()){
        std::string errors;
        errors += std::string("The database is currently empty");
        if(!errors.empty())
            throw RepositoryException(errors);
    }
    return this->database;
}

unsigned int Repository::getSize() {
    if(this->database.empty()){
        std::string errors;
        errors+= std::string("The database is currently empty");
        if(!errors.empty())
            throw RepositoryException(errors);
    }
    return this->database.size();
}

int Repository::search(const std::string &link) {
    int Index = -1;
    std::vector<Event>::iterator iter;
    iter = std::find_if(this->database.begin(), this->database.end(), [&link](Event& event) {return event.get_link() == link;});
    if(iter != this->database.end())
        Index = iter - this->database.begin();
    return Index;
}

void Repository::add_repo(Event& event) {
    int exists = this->search(event.get_link());
    if(exists != -1){
        std::string errors;
        errors += std::string("The event already exists in the database");
        if(!errors.empty())
            throw RepositoryException(errors);
    }
    this->database.push_back(event);
    this -> writeEventsToFile();
}

void Repository::remove_repo(int index) {
    if(index == -1){
        std::string errors;
        errors += std::string("The event does not exist");
        if(!errors.empty())
            throw RepositoryException(errors);
    }
    this->database.erase(this->database.begin() + index);
    this->writeEventsToFile();
}

void Repository::update_repo(int index, Event& event) {
    if(index == -1){
        std::string errors;
        errors+= std::string("The event does not exist");
        if(!errors.empty())
            throw RepositoryException(errors);
    }
    this->database[index] = event;
    this->writeEventsToFile();
}

void Repository::writeToFileRepo() {
    this->writeEventsToFile();
}

Repository::~Repository() = default;