#include "domain.h"
#include <sstream>
#include <vector>
#include <iostream>

Event::Event(const std::string& title,const std::string& description,
             const std::string& date_time, unsigned int number_people,const std::string& link):title{title}, description{description},
             date_time{date_time}, number_people{number_people}, link{link}{}

unsigned int Event::get_month() {
    std::string month_format;

    char first_part, second_part;
    first_part = date_time[3];
    second_part = date_time[4];

    if(first_part == '0')
        return second_part - '0';

    month_format[0] = first_part;
    month_format[1] = second_part;

    return stoi(month_format);
}

std::string Event::get_month_string() {
    std::string month_format;

    char first_part, second_part;
    first_part = date_time[3];
    second_part = date_time[4];

    month_format[0] = first_part;
    month_format[1] = second_part;
    return month_format;
}

bool Event :: operator==(const Event& event)
{
    if(event.title != this->title) return false;
    if(event.description != this->description) return false;
    if(event.date_time != this->date_time) return false;
    if(event.number_people != this->number_people) return false;
    if(event.link != this->link) return false;
    return true;
}

std::string Event::toString() const{
    auto str_Number_People= std::to_string(this->number_people);
    return "Title: " + this->title + " || Description: " + this->description + " || Date: " + this->date_time +
    " || Number of people: " + str_Number_People + " || Link: " + this->link;
}

std::vector<std::string> tokenize(const std::string& str, char delimiter){
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);
    return result;
}

std::istream &operator>>(std::istream &inputStream, Event &event) {
    std::string line;
    std::getline(inputStream, line);
    std::vector<std::string> tokens;
    if(line.empty())
        return inputStream;
    tokens = tokenize(line, ',');
    event.title = tokens[0];
    event.description = tokens[1];
    event.date_time = tokens[2];
    event.number_people = std::stoi(tokens[3]);
    event.link = tokens[4];
    return inputStream;
}

std::ostream &operator<<(std::ostream &outputStream, const Event &eventOutput){
    outputStream << eventOutput.title << "," << eventOutput.description << "," << eventOutput.date_time << "," <<
    eventOutput.number_people << "," << eventOutput.link;
    return outputStream;
}

void Event::set_number_people(unsigned int new_number_people) {
    this->number_people = new_number_people;
}
