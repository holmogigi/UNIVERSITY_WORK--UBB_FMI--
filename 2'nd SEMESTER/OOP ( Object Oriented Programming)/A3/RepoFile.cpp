#include "RepoFile.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Event.h"

RepoFile::RepoFile(std::vector<Event>& adminrepoo, std::string& filenamee)
{
    this->adminrepo=adminrepoo;
    this->filename=filenamee;
}

void RepoFile::read_from_file()
{
    Event filevent;
    std::ifstream fin {this->filename};
    while (fin>>filevent)
    {
        this->adminrepo.push_back(filevent);
    }
    fin.close();
}

void RepoFile::write_to_file()
{
    std::ofstream fout(this->filename);
    for (const Event &event: this->adminrepo)
    {
        fout<<event<<'\n';
    }
    fout.close();
}

void RepoFile::initRepo()
{
    this->read_from_file();
}

std::vector<Event>& RepoFile::getAll()
{
    return this->adminrepo;
}

Event RepoFile::get_elem(int pos)
{
    return this->adminrepo.at(pos);
}

int RepoFile::getSize()
{
    return this->adminrepo.size();
}

void RepoFile::store_event(Event& event)
{
    this->adminrepo.push_back(event);
    this->write_to_file();
}

int RepoFile::find_pos(std::basic_string<char> name)
{
    int pos=-1;
    std::vector<Event>::iterator it;
    it= std::find_if(this->adminrepo.begin(), this->adminrepo.end(), [&name](Event& event) {return event.get_title()==name;});
    if (it!=this->adminrepo.end())
        pos= it - this->adminrepo.begin();
    return pos;
}

void RepoFile::delete_event(Event event)
{
    this->adminrepo.erase(this->adminrepo.begin() + find_pos(event.get_title()));
    this->write_to_file();
}

void RepoFile::update_event(Event &event, int pos)
{
    this->adminrepo[pos]=event;
    this->write_to_file();
}

RepoFile::~RepoFile()
{
    adminrepo.clear();
}