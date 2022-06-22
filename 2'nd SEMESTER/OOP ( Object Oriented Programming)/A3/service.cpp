#include "service.h"
#include "domain.h"
#include <algorithm>
#include <exception>

Service::Service(Repository &repo): repository(repo) {}

std::vector<Event>& Service::getAllService() {
    return this->repository.getRepo();
}

unsigned int Service::getSizeService() {
    return this->repository.getSize();
}

void Service::add_service(std::string title, std::string description, std::string date_time, unsigned int number_people, std::string link){
    Event event = Event(title, description, date_time, number_people, link);
    this->repository.add_repo(event);
}

void Service::remove_service(const std::string link) {
    int index = this->repository.search(link);
    this->repository.remove_repo(index);
}

void Service::update_service(const std::string newTitle, const std::string newDescription, const std::string newDate_Time, int new_number_people, const std::string oldLink, const std::string newLink) {
    int index = this->repository.search(oldLink);
    Event event = Event(newTitle, newDescription, newDate_Time, new_number_people, newLink);
    this->repository.update_repo(index, event);
}

void Service::writeToFileService() {
    this->repository.writeToFileRepo();
}

int Service::searchService(const std::string &link) {
    int index = repository.search(link);
    return index;
}

void Service::undoLastAction()
{
    if(this->undoAdmin.empty()){
        std::string error;
        error += std::string("Can't undo anymore");
        if(!error.empty())
            throw RepositoryException(error);
    }
    this->undoAdmin.back()->undo();
    this->redoAdmin.push_back(this->undoAdmin.back());
    this->undoAdmin.pop_back();
}

void Service::redoLastAction() {
    if(this->redoAdmin.empty()){
        std::string error;
        error += std::string("Can't redo anymore");
        if(!error.empty())
            throw RepositoryException(error);
    }
    this->redoAdmin.back()->redo();
    this->undoAdmin.push_back(this->redoAdmin.back());
    this->redoAdmin.pop_back();
}

void Service::clearUndoRedo() {
    this->undoAdmin.clear();
    this->redoAdmin.clear();
}

Service::~Service() =default;