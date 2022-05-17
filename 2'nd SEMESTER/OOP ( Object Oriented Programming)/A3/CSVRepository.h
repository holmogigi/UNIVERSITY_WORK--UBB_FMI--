#include "userRepo.h"

class CSVRepo: public UserRepository{
public:
    CSVRepo(const std::vector<Event>& list, const std::string& userFilename);

    std::vector<Event>& getAllUsersRepo() override;

    unsigned int getSize() override;

    unsigned int getCapacity() override;

    void addUserRepo(const Event& event) override;

    void removeUserRepo(unsigned int index) override;

    int search(const std::string& link) override;

    void writeToFile() override;

    std::string& getFilename() override;

    ~CSVRepo();
};