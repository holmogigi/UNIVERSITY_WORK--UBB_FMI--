#pragma once
#include "Repo.h"

class RepoFile
{
private:
    std::string filename;
    std::vector<Event> adminrepo;
public:
    explicit RepoFile(std::vector<Event>& adminrepo, std::string& filename);
    void store_event(Event& event);
    void delete_event(Event event);
    void update_event(Event& event, int pos);
    void read_from_file();
    void write_to_file();
    void initRepo();
    std::vector<Event>& getAll();
    int getSize();
    int find_pos(std::basic_string<char> name);
    Event get_elem(int pos);
    ~RepoFile();
};

