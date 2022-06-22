#include "repository.h"
#include "service.h"
#include "ui.h"
#include "domain.h"
#include "validators.h"
#include <vector>
#include <QApplication>
#include "GUI.h"

int main(int argc, char **argv)
{
    QApplication gui(argc, argv);
    std::vector<Event> AdminRepo;
    AdminRepo.reserve(10);
    std::string filename = R"(C:\Users\USER\OneDrive\Desktop\UBB FMI\SEM 2\OOP_ ASSIG\a5-6-holmogigi\events.txt)";
    Repository repo{AdminRepo, filename};
    repo.initialiseRepo();
    Service service{repo};
    std::vector<Event> UserRepo;
    UserService userService{repo};
    EventValidator validator{};
    GUI GUI{service,userService, validator, repo};
    GUI.show();
    gui.exec();
    return 0;
}
