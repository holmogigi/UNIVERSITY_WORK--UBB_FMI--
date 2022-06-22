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
#include "userService.h"
#include "validators.h"
#include "QGridLayout"
#include "QTableView"
#include "QHeaderView"
#include "QShortcut"
#include "QRadioButton"

class EventTableModel: public QAbstractTableModel{
private:
    UserRepository* repository;
public:
    explicit EventTableModel(UserRepository* newRepository);
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    void update();
};

class GUI: public QWidget{
private:
    Service& service;
    UserService& userService;
    EventValidator& validator;
    Repository& repository;
    void initGUI();
    QLabel* titleWidget;
    QPushButton* adminButton;
    QPushButton* userButton;
    void showAdmin();
    void showUser();
    void connectSignalsAndSlots();
public:
    explicit GUI(Service& serv, UserService& userserv, EventValidator& validator1, Repository& repository1);
    ~GUI() override;

};

class AdminGUI: public QWidget{
private:
    Service& service;
    EventValidator& validator;
    Repository& repository;
    void initAdminGUI();
    QLabel* titleWidget;
    QListWidget* eventsListWidget;
    QLineEdit* titleLineEdit, *descriptionLineEdit, *dateLineEdit, *numberLineEdit, *linkLineEdit;
    QLineEdit* filterEvents;
    QPushButton* addButton, *deleteButton, *updateButton;
    QPushButton* undoButton, *redoButton;
    QShortcut* shortcutUndo, *shortcutRedo;
    void populateList(std::string filter = "");
    void filterFunction();
    void connectSignalsAndSlots();
    int getSelectedIndex() const;
    void addEvent();
    void deleteEvent();
    void updateEvent();
    void undoGUI();
    void redoGUI();
public:
    explicit AdminGUI(QWidget* parent, Service& serv, EventValidator& validator1, Repository& repo);
    ~AdminGUI() override;
};

class UserGUI: public QWidget{
private:
    Service& service;
    UserService& userService;
    EventValidator& validator;
    void initUserGUI();
    QLabel* titleWidget;
    QListWidget* eventsListWidget, *userListWidget;
    QLineEdit* titleLineEdit, *descriptionLineEdit, *dateLineEdit, *numberLineEdit, *linkLineEdit, *monthFilterLineEdit;
    QPushButton* addButton, *filterButton, *openListButton, *removeButton, *openUserListButton;
    QRadioButton* csvButton, *htmlButton;
    QTableView* userListTable;
    QGridLayout* listAndTableLayout, *userListLayout;
    bool repoTypeSelected;
    bool filtered;
    void createTable();
    void populateEventList();
    int getSelectedIndex() const;
    void populateUserList();
    void connectSignalsAndSlots();
    void addEvent();
    void removeEvent();
    void filterEvents();
public:
    explicit UserGUI(QWidget* parent, Service& serv, UserService& userserv, EventValidator& validator1);
    ~UserGUI() override;

};