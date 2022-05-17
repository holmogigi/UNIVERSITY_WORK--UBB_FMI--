#pragma once
#include "repository.h"
#include "userRepo.h"

class UserService{
private:
    Repository& repository;
    UserRepository* userRepository;

public:

    UserService(Repository& repository1, UserRepository& userRepository1);

    explicit UserService(Repository& repository1);

    std::vector<Event> getAllUsersService();

    unsigned int getSizeService();

    void addUserService(Event& event);

    std::string& getFileService();

    void RepositoryType(const std::string& fileType);

    ~UserService();

    void removeUserService(std::string &link);

    int filterByMonth(std::vector<Event>& events, std::string& filter_month);
};