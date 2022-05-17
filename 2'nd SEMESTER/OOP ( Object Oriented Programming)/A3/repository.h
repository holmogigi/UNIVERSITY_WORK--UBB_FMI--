#pragma once
#include "vector"
#include "domain.h"

class Repository{
private:
    std::vector<Event> database;
    std::string eventFile;

public:

    void loadEventsFromFile();

    void writeEventsToFile();

    int search(const std::string& link);

    explicit Repository(std::vector<Event>& repo_vector, std::string& eventFile);

    void initialiseRepo();

    std::vector<Event>& getRepo();

    unsigned int getSize();

    void add_repo(Event &event);

    void remove_repo(int index);

    void update_repo(int index, Event& event);

    ~Repository();

    void writeToFileRepo();
};

class RepositoryException: public std::exception{
private:
    std::string message;
public:
    explicit RepositoryException(std::string& _message);

    const char* what() const noexcept override;
};