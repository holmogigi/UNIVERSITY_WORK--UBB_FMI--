#include "validators.h"

ValidatorException::ValidatorException(std::string &_message): message(_message) {}

const char* ValidatorException::what() const noexcept {
    return message.c_str();
}

EventValidator::EventValidator() =default;

bool EventValidator::validateString(const std::string &string) {
    for(auto i: string)
        if(std::isdigit(i) != false)
            return false;
    return true;
}

void EventValidator::validateTitle(const std::string &title) {
    std::string errors;
    if(title.length() == 0)
        errors += std::string("Empty title");
    if(!errors.empty())
        throw ValidatorException(errors);
}

void EventValidator::validateDescription(const std::string &description) {
    std::string errors;
    if(description.length() == 0)
        errors += std::string("Empty description");
    if(!errors.empty())
        throw ValidatorException(errors);
}

void EventValidator::validateDateTime(const std::string &datetime) {
    std::string errors;
    if(datetime.empty())
        errors += std::string("Empty Date");
    if(datetime.find_first_not_of("0123456789/: ") != std::string::npos)
        errors += std::string("The date has invalid characters");
    if(!errors.empty())
        throw ValidatorException(errors);
}

void EventValidator::validatePeople(int number_people) {
    std::string errors;
    if(number_people < 0)
        errors += std::string("There can't be a negative number of people attending");
    if(!errors.empty())
        throw ValidatorException(errors);
}

void EventValidator::validatePeopleString(const std::string &number_people) {
    std::string errors;
    if(number_people.empty())
        errors+= std::string("Empty number of people");
    if(number_people.find_first_not_of("0123456789") != std::string::npos)
        errors += std::string("The number of people has invalid characters");
    if(!errors.empty())
        throw ValidatorException(errors);
}

void EventValidator::validateLink(const std::string &link) {
    std::string errors;
    if(link.length() == 0)
        errors += std::string("Empty link");
    if(link.find("www") == std::string::npos)
        errors+= std::string("Invalid link");
    if(!errors.empty())
        throw ValidatorException(errors);
}

EventValidator::~EventValidator() = default;