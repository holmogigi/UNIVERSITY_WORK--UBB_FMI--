#include "GUI.h"
#include <string>

GUI::GUI(Service &serv, Repository &repo, QWidget *parent):service(serv), repository(repo)
{
    this->initGUI();
    this->populateEventsList("");
    this->connect();
}

GUI::~GUI(){}

void GUI::initGUI() {
    //Window layout
    QHBoxLayout* layout = new QHBoxLayout{this};

    //Leftpart of the window
    //events list
    this->filter_type=new QLineEdit{};
    QString filter_text=this->filter_type->text();
    this->eventsList = new QListWidget{};
    this->eventsList->setSelectionMode(QAbstractItemView::SingleSelection);
    QLabel* allEventsLabel = new QLabel{"All events"};
    QWidget* leftSide = new QWidget{};
    QVBoxLayout* leftLayout = new QVBoxLayout{leftSide};
    leftLayout->addWidget(this->filter_type);
    leftLayout->addWidget(allEventsLabel);
    leftLayout->addWidget(this->eventsList);

    //events data
    QWidget* formLayout = new QWidget{};
    QFormLayout* eventLayout = new QFormLayout{formLayout};
    this->titleEdit = new QLineEdit{};
    this->descriptionEdit = new QLineEdit{};
    this->datetimeEdit = new QLineEdit{};
    this->numberOfPeopleEdit = new QLineEdit{};
    this->linkEdit = new QLineEdit{};
    QFont f{"Helvetica", 10};
    QLabel* titleLabel = new QLabel{"&Title: "};
    titleLabel->setBuddy(this->titleEdit);
    QLabel* descriptionLabel = new QLabel{"&Description: "};
    descriptionLabel->setBuddy(this->descriptionEdit);
    QLabel* datetimeLabel = new QLabel{"&Date: "};
    datetimeLabel->setBuddy(this->datetimeEdit);
    QLabel* numberOfPeopleLabel = new QLabel{"&Number of people: "};
    numberOfPeopleLabel->setBuddy(this->numberOfPeopleEdit);
    QLabel* linkLabel = new QLabel{"&Link: "};
    linkLabel->setBuddy(this->linkEdit);
    titleLabel->setFont(f);
    descriptionLabel->setFont(f);
    datetimeLabel->setFont(f);
    numberOfPeopleLabel->setFont(f);
    linkLabel->setFont(f);
    this->titleEdit->setFont(f);
    this->descriptionEdit->setFont(f);
    this->datetimeEdit->setFont(f);
    this->numberOfPeopleEdit->setFont(f);
    this->linkEdit->setFont(f);
    eventLayout->addRow(titleLabel, this->titleEdit);
    eventLayout->addRow(descriptionLabel, this->descriptionEdit);
    eventLayout->addRow(datetimeLabel, this->datetimeEdit);
    eventLayout->addRow(numberOfPeopleLabel, this->numberOfPeopleEdit);
    eventLayout->addRow(linkLabel, this->linkEdit);
    leftLayout->addWidget(formLayout);

    //Buttons
    QWidget* buttonsWidget = new QWidget{};
    QGridLayout* gridLayout = new QGridLayout{buttonsWidget};
    this->addEventButton = new QPushButton("Add");
    this->addEventButton->setFont(f);
    this->deleteEventButton = new QPushButton("Remove");
    this->deleteEventButton->setFont(f);
    this->updateEventButton = new QPushButton("Update");
    this->updateEventButton->setFont(f);
    //this->filterEventButton = new QPushButton("Filter");
    //this->filterEventButton->setFont(f);
    gridLayout->addWidget(this->addEventButton, 0, 0);
    gridLayout->addWidget(this->deleteEventButton, 0, 1);
    gridLayout->addWidget(this->updateEventButton, 0, 2);
    //gridLayout->addWidget(this->filterEventButton, 1, 1);
    leftLayout->addWidget(buttonsWidget);

    //Middle part
    QWidget* midPart = new QWidget{};
    QVBoxLayout* midLayout = new QVBoxLayout{midPart};
    this->listButton = new QPushButton(">>>");
    this->listButton->setFont(f);
    midLayout->addWidget(this->listButton);

    //Right part
    QWidget* rightSide = new QWidget{};
    QVBoxLayout* rightLayout = new QVBoxLayout{rightSide};
    this->list = new QListWidget{};
    this->list->setSelectionMode(QAbstractItemView::SingleSelection);
    QLabel* listLabel = new QLabel{"Your Events"};
    rightLayout->addWidget(listLabel);
    rightLayout->addWidget(this->list);
    QWidget* buttonslist = new QWidget{};
    QGridLayout* gridList = new QGridLayout{buttonslist};
    this->nextButton = new QPushButton("Next");
    this->nextButton->setFont(f);

    gridList->addWidget(this->nextButton, 0, 0);
    rightLayout->addWidget(buttonslist);

    //add sides to layout
    layout->addWidget(leftSide);
    layout->addWidget(midPart);
    layout->addWidget(rightSide);
}

void GUI::populateEventsList(std::string partial)
{
    this->eventsList->clear();
    std::vector<Event> allEvents = this->service.getAllService();
    for(auto &event: allEvents)
    {
        if (event.toString().find(partial)!=event.toString().npos)
            this->eventsList->addItem(QString::fromStdString(event.toString()));
    }
}

void GUI::filter_event()
{
    std::string filter=this->filter_type->text().toStdString();
    populateEventsList(filter);
}

void GUI::connect()
{
    QObject::connect(this->filter_type, &QLineEdit::textChanged, this, &GUI::filter_event);
}
