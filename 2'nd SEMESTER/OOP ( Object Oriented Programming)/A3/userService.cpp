#include "userService.h"
#include "HTMLRepository.h"
#include "CSVRepository.h"
#include <algorithm>


UserService::UserService(Repository &repository1, UserRepository& userRepository1): repository(repository1){
    this->userRepository = userRepository;
}

std::vector<Event> UserService::getAllUsersService() {
    return this->userRepository->getAllUsersRepo();
}

unsigned int UserService::getSizeService() {
    return this->userRepository->getSize();
}

void UserService::addUserService(Event &event) {
    this->userRepository->addUserRepo(event);
}

void UserService::removeUserService(std::string &link) {
    int index = this ->userRepository->search(link);
    this->userRepository->removeUserRepo(index);
}

std::string& UserService::getFileService() {
    return this->userRepository->getFilename();
}

void UserService::RepositoryType(const std::string &fileType) {
    if(fileType == "csv"){
        std::vector<Event> userVector;
        std::string userFile = R"(C:\Users\USER\OneDrive\Desktop\UBB FMI\SEM 2\OOP_ ASSIG\a5-6-holmogigi\List.csv)";
        auto* repo = new CSVRepo{userVector, userFile};
        this->userRepository = repo;
    }
    else if(fileType == "html"){
        std::vector<Event> userVector;
        std::string userFile = R"(C:\Users\USER\OneDrive\Desktop\UBB FMI\SEM 2\OOP_ ASSIG\a5-6-holmogigi\List.html)";
        auto* repo = new HTMLRepo{userVector, userFile};
        this->userRepository = repo;
    }
    else{
        std::string error;
        error += std::string("Invalid filetype");
        if(!error.empty())
            throw UserException(error);
    }
}

int UserService::filterByMonth(std::vector<Event> &events, std::string &filter_month) {
    std::vector<Event> result;
    int int_month;
    result.resize(this->repository.getSize());
    result = this->repository.getRepo();
    if(filter_month[0] == '\0'){
        std::copy_if(result.begin(), result.end(), std::back_inserter(events), [](Event& event) {return true;});
    }
    else{

        std::copy_if(result.begin(), result.end(), std::back_inserter(events), [&filter_month](Event& event){return event.get_month() == stoi(filter_month);});
    }
    return events.size();
}

UserService::UserService(Repository &repository1): repository{repository1}{}

UserService::~UserService() =default;