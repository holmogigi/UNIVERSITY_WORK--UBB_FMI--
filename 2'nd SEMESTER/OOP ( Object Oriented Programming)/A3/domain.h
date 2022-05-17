#pragma once
#include <string>
#include <vector>

class Event{
private:
    std::string title;
    std::string description;
    std::string date_time;
    std::string link;
    unsigned int number_people{};

public:

    Event() : title{""}, description{""}, date_time{""}, number_people{0 }, link{""}{};

    Event(const std::string& title, const std::string& description,
         const std::string& date_time, unsigned int number_people,const std::string& link);

    std::string get_title() const { return this->title; }

    std::string get_description() const { return this->description; }

    std::string get_date_time() const {return this->date_time; }

    std::string get_link() const {return this->link; }

    unsigned int get_month();

    std::string get_month_string();

    unsigned int get_number_people() const {return this->number_people; }

    void set_number_people(unsigned int new_number_people);

    bool operator==(const Event& event);

    std::string toString() const;

    friend std::istream& operator>>(std::istream& inputStream, Event& event);

    friend std::ostream& operator<<(std::ostream& outputStream, const Event& event);
};
