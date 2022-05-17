#include "userRepo.h"

class HTMLRepo: public UserRepository{
public:
    HTMLRepo(const std::vector<Event>& list, const std::string& userFilename);

    std::vector<Event>& getAllUsersRepo() override;

    unsigned int getCapacity() override;

    unsigned int getSize() override;

    void addUserRepo(const Event& event) override;

    void removeUserRepo(unsigned int index) override;

    int search(const std::string& link) override;

    void writeToFile() override;

    std::string& getFilename() override;

    ~HTMLRepo();
};