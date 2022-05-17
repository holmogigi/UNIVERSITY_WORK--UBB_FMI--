#include "repository.h"
#include "service.h"
#include "ui.h"
#include "domain.h"
#include "validators.h"
#include <vector>
#include <QApplication>
#include "GUI.h"
#include <iostream>

int main(int argc, char **argv)
{
    //std::cout<<"1.GUI\n2.Console\n>> ";
    //int input;
    //std::cin>>input;

    std::vector<Event> AdminRepo;
    AdminRepo.reserve(10);
    std::string filename = R"(C:\Users\USER\OneDrive\Desktop\UBB FMI\SEM 2\OOP_ ASSIG\a5-6-holmogigi\events.txt)";
    Repository repo{AdminRepo, filename};
    repo.initialiseRepo();
    Service service{repo};
    std::vector<Event> UserRepo;
    UserService userService{repo};
    EventValidator validator{};
    UI ui{service, userService, validator};
    QApplication gui(argc, argv);
    GUI GUI{service,repo};

    //if (input==2)
    //{
        //ui.run();
    //}
    //else
    //{
        GUI.show();
        gui.exec();
    //}
    return 0;
}
