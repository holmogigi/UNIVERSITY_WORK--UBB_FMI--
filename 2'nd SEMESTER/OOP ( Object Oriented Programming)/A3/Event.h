#pragma once
#include <string>

class Event
{
private:
    std::string title;
    std::string description;
    int date;
    int time;
    int people_nr;
    std::string link;

public:
    Event() {}
    std::string toString() const;
    Event(const std::string& title, const std::string& description, const int date, const int time, const int people_nr, const std::string& link);
    std::string get_title() const { return this->title; }
    std::string get_description() const { return this->description; }
    int get_date() const { return this->date; }
    int get_time() const { return this->time; }
    int get_people_nr() const { return this->people_nr; }
    std::string get_link() const { return this->link; }
    void set_people_nr(int people);
    friend std::istream& operator>>(std::istream& stream, Event& event);
    friend std::ostream& operator<<(std::ostream& stream, const Event& event);
};
