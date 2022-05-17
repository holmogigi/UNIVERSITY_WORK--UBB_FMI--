#pragma once
#include "domain.h"

class ValidatorException: public std::exception{
private:
    std::string message;
public:
    explicit ValidatorException(std::string& _message);
    const char *what() const noexcept override;
};

class EventValidator{
public:
    EventValidator();
    bool validateString(const std::string& string);
    void validateTitle(const std::string& title);
    void validateDescription(const std::string& description);
    void validateDateTime(const std::string& datetime);
    void validatePeople(int number_people);
    void validatePeopleString(const std::string& number_people);
    void validateLink(const std::string& link);

    ~EventValidator();
};