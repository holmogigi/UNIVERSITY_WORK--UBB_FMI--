#include "userRepo.h"
#include <algorithm>

UserException::UserException(std::string &_message):message(_message) {}

const char* UserException::what() const noexcept {
    return message.c_str();
}

UserRepository::UserRepository() =default;

UserRepository::UserRepository(std::vector<Event>& list1){
    this->list = list1;
}

std::vector<Event>& UserRepository::getAllUsersRepo() {
    return this->list;
}

UserRepository::~UserRepository() =default;