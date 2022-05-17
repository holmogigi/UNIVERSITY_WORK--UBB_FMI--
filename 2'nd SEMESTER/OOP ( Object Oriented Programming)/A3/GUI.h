#pragma once
#include <qwidget.h>
#include "domain.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "service.h"
#include "repository.h"

class GUI: public QWidget{
    Q_OBJECT
public:
    GUI(Service& serv, Repository& repo, QWidget *parent = 0);
    ~GUI();

private:
    Service& service;
    Repository& repository;
    std::vector<Event> events;

    QListWidget* eventsList;
    QListWidget* list;

    QLineEdit* filter_type;
    QLineEdit* titleEdit;
    QLineEdit* descriptionEdit;
    QLineEdit* datetimeEdit;
    QLineEdit* numberOfPeopleEdit;
    QLineEdit* linkEdit;
    QPushButton* addEventButton;
    QPushButton* deleteEventButton;
    QPushButton* updateEventButton;
    QPushButton* filterEventButton;
    QPushButton* listButton;
    QPushButton* playButton;
    QPushButton* nextButton;

    void initGUI();
    void populateEventsList(std::string partial="");
    void filter_event();
    void connect();
};