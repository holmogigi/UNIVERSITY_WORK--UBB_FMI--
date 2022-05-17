#pragma once
#include "repository.h"
#include <string>

class Service{
    Repository& repository;
public:

    explicit Service(Repository& repo);

    std::vector<Event>& getAllService();

    unsigned int getSizeService();

    void add_service(std::string title, std::string description, std::string date_time, unsigned int number_people, std::string link);

    void remove_service(const std::string link);

    void update_service(const std::string newTitle, const std::string newDescription, const std::string newDate_Time, int new_number_people, const std::string oldLink, const std::string newLink);

    ~Service();

    void writeToFileService();

    int searchService(const std::string &link);
};
