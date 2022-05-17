#pragma once
#include <vector>
#include "domain.h"

class UserRepository{
protected:
    std::vector<Event> list;
    std::string userFilename;

public:
    explicit UserRepository(std::vector<Event>& list1);

    UserRepository();

    virtual std::vector<Event>& getAllUsersRepo() = 0;

    virtual unsigned int getSize() = 0;

    virtual unsigned int getCapacity() = 0;

    virtual void addUserRepo(const Event& event) = 0;

    virtual void removeUserRepo(unsigned int index) = 0;

    virtual int search(const std::string &link) = 0;

    ~UserRepository();

    virtual void writeToFile() = 0;
    virtual std::string& getFilename() = 0;
};

class UserException: public std::exception{
private:
    std::string message;
public:
    explicit UserException(std::string& _message);
    const char *what() const noexcept override;
};