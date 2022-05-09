#include "Event.h"
#include <sstream>
#include <vector>

Event::Event(const std::string& title, const std::string& description, const int date, const int time, const int people_nr, const std::string& link)
    :title { title }, description { description }, date {date}, time {time}, people_nr { people_nr }, link { link } {}

void Event::set_people_nr(int people)
{
    Event::people_nr=people;
}

std::string Event::toString() const
{
    auto str_date= std::to_string(this->date);
    auto str_time=std::to_string(this->time);
    auto str_people_nr=std::to_string(this->people_nr);
    return "Title: "+ this->title + "  ||  " + "Description: "+ this->description + "  ||  " + "Day: "+ str_date+ "  ||  "+ "Time: "+ str_time+ "  ||  "+  "Number of people: "+ str_people_nr+ "  ||  "+ "Link: " +
            this->link;
}

std::vector<std::string> tokensize(std::string str, char delim)
{
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while(getline(ss,token,delim))
        result.push_back(token);
    return result;
}

std::istream& operator>>(std::istream& stream, Event& event)
{
    std::string line;
    std::getline(stream,line);
    std::vector<std::string> tokens= tokensize(line, ',');
    if (tokens.size()!=6)
        return stream;
    event.title=tokens[0];
    event.description=tokens[1];
    event.date=std::stoi(tokens[2]);
    event.time=std::stoi(tokens[3]);
    event.people_nr=std::stoi(tokens[4]);
    event.link=tokens[5];

    return stream;

}

std::ostream& operator<<(std::ostream& stream, const Event& event)
{
    stream << event.title << "," <<event.description << ","<< std::to_string(event.date) << ","<< std::to_string(event.time) << ","<< std::to_string(event.people_nr) << "," << event.link;
    return stream;
}
