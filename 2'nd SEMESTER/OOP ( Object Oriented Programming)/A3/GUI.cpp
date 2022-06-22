#include "GUI.h"
#include "QVBoxLayout"
#include "QFormLayout"
#include "QErrorMessage"
#include "QMessageBox"
#include <windows.h>

EventTableModel::EventTableModel(UserRepository *newRepository) {
    this->repository = newRepository;
}
int EventTableModel::rowCount(const QModelIndex &parent) const {
    return this->repository->getSize();
}
int EventTableModel::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant EventTableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    Event currentEvent = this->repository->getAllUsersRepo()[row];
    int column = index.column();
    if(role == Qt::DisplayRole || role == Qt::EditRole){
        switch(column){
            case 0:
                return QString::fromStdString(currentEvent.get_title());
            case 1:
                return QString::fromStdString(currentEvent.get_description());
            case 2:
                return QString::fromStdString(currentEvent.get_date_time());
            case 3:
                return QString::fromStdString(std::to_string(currentEvent.get_number_people()));
            case 4:
                return QString::fromStdString(currentEvent.get_link());
            default:
                break;
        }
    }
    return QVariant();
}

QVariant EventTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole){
        if(orientation == Qt::Horizontal){
            switch(section){
                case 0:
                    return QString("Title");
                case 1:
                    return QString("Description");
                case 2:
                    return QString("Date and time");
                case 3:
                    return QString("Number of people");
                case 4:
                    return QString("Link");
                default:
                    break;
            }
        }
    }
    return QVariant();
}

void EventTableModel::update() {
    QModelIndex topLeft = this->index(1, 1);
    QModelIndex bottomRight = this->index(this->rowCount(), this->columnCount());
    emit layoutChanged();
    emit dataChanged(topLeft, bottomRight);
}

GUI::GUI(Service& serv, UserService& userserv, EventValidator& validator1, Repository& repository): service{serv}, userService{userserv}, validator{validator1}, repository{repository}{
    this->titleWidget = new QLabel(this);
    this->adminButton = new QPushButton(this);
    this->userButton = new QPushButton(this);
    this->initGUI();
    this->connectSignalsAndSlots();
}

void GUI::initGUI() {
    auto* layout = new QVBoxLayout(this);
    QFont titleFont = this->titleWidget->font();
    this->titleWidget->setText("<p style='text-align:center'><font color=#4D2D52>Select your mode</font></p>");
    titleFont.setPointSize(12);
    titleFont.setStyleHint(QFont::System);
    this->titleWidget->setFont(titleFont);
    layout->addWidget(this->titleWidget);
    this->adminButton->setText("Admin mode");
    layout->addWidget(this->adminButton);
    this->userButton->setText("User mode");
    layout->addWidget(this->userButton);
    this->setLayout(layout);
}

GUI::~GUI() = default;

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->adminButton, &QPushButton::clicked, this, &GUI::showAdmin);
    QObject::connect(this->userButton, &QPushButton::clicked, this, &GUI::showUser);
}

void GUI::showAdmin() {
    //this->service.clearUndoRedo();
    auto* admin = new AdminGUI(this, this->service, this->validator, this->repository);
    admin->show();
}

AdminGUI::AdminGUI(QWidget *parent, Service &serv, EventValidator &validator1, Repository &repo):service{serv}, validator{validator1}, repository{repo} {
    this->titleWidget = new QLabel(this);
    this->eventsListWidget = new QListWidget{};
    this->titleLineEdit = new QLineEdit{};
    this->descriptionLineEdit = new QLineEdit{};
    this->dateLineEdit = new QLineEdit{};
    this->numberLineEdit = new QLineEdit{};
    this->linkLineEdit = new QLineEdit{};
    this->addButton = new QPushButton("Add");
    this->deleteButton = new QPushButton("Remove");
    this->updateButton = new QPushButton("Update");
    this->undoButton = new QPushButton("Undo");
    this->redoButton = new QPushButton("Redo");
    this->shortcutUndo = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
    this->shortcutRedo = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this);
    this->filterEvents = new QLineEdit{};
    setParent(parent);
    setWindowFlag(Qt::Window);
    this->initAdminGUI();
    this->populateList();
    this->connectSignalsAndSlots();
}

void AdminGUI::initAdminGUI() {
    auto* layout = new QVBoxLayout(this);
    QFont titleFont = this->titleWidget->font();
    this->titleWidget->setText("<p style='text-align:center'><font color=#4D2D52>ADMIN MODE</font></p>");
    titleFont.setPointSize(12);
    titleFont.setStyleHint(QFont::System);
    this->titleWidget->setFont(titleFont);
    layout->addWidget(this->titleWidget);
    layout->addWidget(this->eventsListWidget);
    auto* eventDetailsLayout = new QFormLayout{};
    eventDetailsLayout->addRow("Title", this->titleLineEdit);
    eventDetailsLayout->addRow("Description", this->descriptionLineEdit);
    eventDetailsLayout->addRow("Date and Time", this->dateLineEdit);
    eventDetailsLayout->addRow("Number of people", this->numberLineEdit);
    eventDetailsLayout->addRow("Link", this->linkLineEdit);
    layout->addWidget(filterEvents);
    layout->addLayout(eventDetailsLayout);
    auto* buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->addButton, 0, 0);
    buttonsLayout->addWidget(this->deleteButton, 0, 1);
    buttonsLayout->addWidget(this->updateButton, 0, 2);
    buttonsLayout->addWidget(this->undoButton, 1, 0);
    buttonsLayout->addWidget(this->redoButton, 1, 1);
    layout->addLayout(buttonsLayout);

    QLinearGradient listGradient(0, 0, 0, this->eventsListWidget->height());
    listGradient.setColorAt(0, Qt::white);
    listGradient.setColorAt(1, Qt::gray);
    QPalette palette = this->eventsListWidget->palette();
    palette.setBrush(QPalette::ColorRole::Base, QBrush(listGradient));
    this->eventsListWidget->setPalette(palette);
}

void AdminGUI::populateList(std::string filter) {
    this->eventsListWidget->clear();
    std::vector<Event> allEvents = this->service.getAllService();
    for(auto &event:allEvents){
        if(event.get_link().find(filter) != event.get_link().npos)
            this->eventsListWidget->addItem(QString::fromStdString(event.get_link()));
    }
}
void AdminGUI::filterFunction() {
    std::string filter = this->filterEvents->text().toStdString();
    populateList(filter);
}

void AdminGUI::undoGUI() {
    try{
        this->service.undoLastAction();
        this->populateList();
    }catch(RepositoryException& re){
        QMessageBox::critical(this, "Error", re.what());
    }
}

void AdminGUI::redoGUI() {
    try{
        this->service.redoLastAction();
        this->populateList();
    }catch(RepositoryException& re){
        QMessageBox::critical(this, "Error", re.what());
    }
}


void AdminGUI::connectSignalsAndSlots() {
    QObject::connect(this->filterEvents, &QLineEdit::textChanged, this, &AdminGUI::filterFunction);
    QObject::connect(this->eventsListWidget, &QListWidget::itemSelectionChanged, [this](){
        int selectedIndex = this->getSelectedIndex();
        if(selectedIndex < 0)
            return;
        Event event = this->service.getAllService()[selectedIndex];
        this->titleLineEdit->setText(QString::fromStdString(event.get_title()));
        this->descriptionLineEdit->setText(QString::fromStdString(event.get_description()));
        this->dateLineEdit->setText(QString::fromStdString(event.get_date_time()));
        this->numberLineEdit->setText(QString::fromStdString(std::to_string(event.get_number_people())));
        this->linkLineEdit->setText(QString::fromStdString(event.get_link()));
    });
    QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminGUI::addEvent);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminGUI::deleteEvent);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &AdminGUI::updateEvent);
    QObject::connect(this->undoButton, &QPushButton::clicked, this, &AdminGUI::undoGUI);
    QObject::connect(this->redoButton, &QPushButton::clicked, this, &AdminGUI::redoGUI);
}

void AdminGUI::addEvent() {
    std::string title = this->titleLineEdit->text().toStdString();
    std::string description = this->titleLineEdit->text().toStdString();
    std::string date_time = this->dateLineEdit->text().toStdString();
    std::string number_s = this->numberLineEdit->text().toStdString();
    std::string link = this->linkLineEdit->text().toStdString();
    int number;
    try{
        this->validator.validateTitle(title);
        this->validator.validateDescription(description);
        this->validator.validateDateTime(date_time);
        this->validator.validatePeopleString(number_s);
        number = std::stoi(number_s);
        this->validator.validatePeople(number);
        this->validator.validateLink(link);
        this->service.add_service(title, description, date_time, number, link);
        this->populateList();
    }catch(ValidatorException& exc){
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(exc.what());
        error->setWindowTitle("Invalid input");
        error->exec();
    }catch (RepositoryException& re){
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(re.what());
        error->setWindowTitle("Couldn't add event");
        error->exec();
    }
}

void AdminGUI::deleteEvent() {
    try{
        std::string link = this->linkLineEdit->text().toStdString();
        this->validator.validateLink(link);
        this->service.remove_service(link);
        this->populateList();
    }catch(ValidatorException& exc){
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(exc.what());
        error->setWindowTitle("Invalid input");
        error->exec();
    }catch (RepositoryException& re){
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(re.what());
        error->setWindowTitle("Couldn't delete event");
        error->exec();
    }
}

void AdminGUI::updateEvent() {
    int index = this->getSelectedIndex();
    try{
        if(index < 0){
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Critical);
            error->setText("No event selected");
            error->setWindowTitle("Selection error");
            error->exec();
        }else {
            std::string old_link = this->service.getAllService()[index].get_link();
            std::string new_link = this->linkLineEdit->text().toStdString();
            std::string new_description = this->descriptionLineEdit->text().toStdString();
            std::string new_date_time = this->dateLineEdit->text().toStdString();
            std::string number_s = this->numberLineEdit->text().toStdString();
            int number;
            std::string new_title = this->titleLineEdit->text().toStdString();
            this->validator.validateLink(old_link);
            this->validator.validateLink(new_link);
            this->validator.validateTitle(new_title);
            this->validator.validateDescription(new_description);
            this->validator.validateDateTime(new_date_time);
            this->validator.validatePeopleString(number_s);
            number = stoi(number_s);
            this->validator.validatePeople(number);
            this->service.update_service(new_title, new_description, new_date_time, number, old_link, new_link);
            this->populateList();
        }
    }catch (ValidatorException& exc) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(exc.what());
        error->setWindowTitle("Invalid input");
        error->exec();
    }catch (RepositoryException& re) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(re.what());
        error->setWindowTitle("Couldn't update event");
        error->exec();
    }
}

int AdminGUI::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->eventsListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.empty()){
        this->titleLineEdit->clear();
        this->descriptionLineEdit->clear();
        this->dateLineEdit->clear();
        this->numberLineEdit->clear();
        this->linkLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

AdminGUI::~AdminGUI() = default;

void GUI::showUser() {
    auto* user = new UserGUI(this, this->service, this->userService, this->validator);
    user->show();
}

UserGUI::UserGUI(QWidget *parent, Service &serv, UserService &userserv, EventValidator &validator1):service{serv}, userService{userserv}, validator{validator1} {
    this->titleWidget = new QLabel(this);
    this->eventsListWidget = new QListWidget{};
    this->userListWidget = new QListWidget{};
    this->titleLineEdit = new QLineEdit{};
    this->descriptionLineEdit = new QLineEdit{};
    this->dateLineEdit = new QLineEdit{};
    this->numberLineEdit = new QLineEdit{};
    this->linkLineEdit = new QLineEdit{};
    this->monthFilterLineEdit = new QLineEdit{};
    this->addButton = new QPushButton("Add to your list");
    this->filterButton = new QPushButton("Filter");
    this->removeButton = new QPushButton("Remove");
    this->openListButton = new QPushButton("Open file");
    this->csvButton = new QRadioButton("CSV");
    this->htmlButton = new QRadioButton("HTML");
    this->openUserListButton = new QPushButton("View list");
    this->repoTypeSelected = false;
    this->filtered = false;
    setParent(parent);
    setWindowFlag(Qt::Window);
    this->initUserGUI();
    this->populateEventList();
    this->connectSignalsAndSlots();
}

void UserGUI::initUserGUI() {
    auto* layout = new QVBoxLayout(this);
    QFont titleFont = this->titleWidget->font();
    this->titleWidget->setText("<p style='text-align:center'><font color=#4D2D52>User Mode <br> Select the type of file you want to save your list in</font></p>");
    titleFont.setPointSize(12);
    titleFont.setStyleHint(QFont::System);
    this->titleWidget->setFont(titleFont);
    layout->addWidget(this->titleWidget);

    auto* radioButtonsLayout = new QGridLayout(this);
    radioButtonsLayout->addWidget(this->csvButton, 0, 0);
    radioButtonsLayout->addWidget(this->htmlButton, 1, 0);
    radioButtonsLayout->addWidget(this->openListButton, 0, 1);
    layout->addLayout(radioButtonsLayout);
    this->userListTable = new QTableView{};
    this->listAndTableLayout = new QGridLayout(this);
    this->listAndTableLayout->addWidget(this->eventsListWidget, 0, 0);
    this->listAndTableLayout->addWidget(this->userListWidget, 0, 1);
    layout->addLayout(this->listAndTableLayout);

    auto* eventDetailsLayout = new QFormLayout{};
    eventDetailsLayout->addRow("Title", this->titleLineEdit);
    eventDetailsLayout->addRow("Description", this->descriptionLineEdit);
    eventDetailsLayout->addRow("Date and Time", this->dateLineEdit);
    eventDetailsLayout->addRow("Number of people", this->numberLineEdit);
    eventDetailsLayout->addRow("Link", this->linkLineEdit);
    eventDetailsLayout->addRow(this->addButton);
    eventDetailsLayout->addRow(this->removeButton);
    eventDetailsLayout->addRow(this->openUserListButton);
    layout->addLayout(eventDetailsLayout);

    auto* filterLink = new QLabel("<p style='text-align:center'><font color=#4D2D52><br>Filter the events by month</font></p>");
    QFont filterFont = filterLink->font();
    filterFont.setPointSize(12);
    filterFont.setStyleHint(QFont::System);
    filterLink->setFont(filterFont);
    layout->addWidget(filterLink);
    auto* filterDetailsLayout = new QFormLayout{};
    filterDetailsLayout->addRow("Month", this->monthFilterLineEdit);
    filterDetailsLayout->addRow(this->filterButton);
    layout->addLayout(filterDetailsLayout);


}

void UserGUI::populateUserList() {

}

void UserGUI::populateEventList() {
    this->eventsListWidget->clear();
    std::vector<Event> allEvents = this->service.getAllService();
    for(Event& event: allEvents)
        this->eventsListWidget->addItem(QString::fromStdString(event.get_link()));
}

void UserGUI::connectSignalsAndSlots() {
    QObject::connect(this->eventsListWidget, &QListWidget::itemClicked, [this]() {
        std::string link = this->eventsListWidget->selectedItems().at(0)->text().toStdString();
        int index = this->service.searchService(link);
        Event event = this->service.getAllService()[index];
        this->titleLineEdit->setText(QString::fromStdString(event.get_title()));
        this->descriptionLineEdit->setText(QString::fromStdString(event.get_description()));
        this->dateLineEdit->setText(QString::fromStdString(event.get_date_time()));
        this->numberLineEdit->setText(QString::fromStdString(std::to_string(event.get_number_people())));
        this->linkLineEdit->setText(QString::fromStdString(event.get_link()));
        std::string openLink = std::string("start ").append(event.get_link());
        system(openLink.c_str());
    });
    QObject::connect(this->userListWidget, &QListWidget::itemClicked, [this]() {
        std::string link = this->userListWidget->selectedItems().at(0)->text().toStdString();
        int index = this->service.searchService(link);
        Event event = this->service.getAllService()[index];
        this->titleLineEdit->setText(QString::fromStdString(event.get_title()));
        this->descriptionLineEdit->setText(QString::fromStdString(event.get_description()));
        this->dateLineEdit->setText(QString::fromStdString(event.get_date_time()));
        this->numberLineEdit->setText(QString::fromStdString(std::to_string(event.get_number_people())));
        this->linkLineEdit->setText(QString::fromStdString(event.get_link()));
        std::string openLink = std::string("start ").append(event.get_link());
        system(openLink.c_str());
    });
    QObject::connect(this->csvButton, &QRadioButton::clicked, [this](){
        this->userService.RepositoryType("csv");
        this->repoTypeSelected = true;
    });
    QObject::connect(this->htmlButton, &QRadioButton::clicked, [this](){
        this->userService.RepositoryType("html");
        this->repoTypeSelected = true;
    });
    QObject::connect(this->openListButton, &QPushButton::clicked, [this](){
        if(!this->repoTypeSelected){
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Critical);
            error->setText("Select the type of file");
            error->setWindowTitle("File warning");
            error->exec();
        }else{
            std::string link = std::string("start ").append(this->userService.getFileService());
            if (this->userService.getFileService()!="C:\\Users\\USER\\OneDrive\\Desktop\\UBB FMI\\SEM 2\\OOP_ ASSIG\\a5-6-holmogigi\\List.csv")
                ShellExecute(nullptr,L"open",L"C:\\Users\\USER\\OneDrive\\Desktop\\UBB FMI\\SEM 2\\OOP_ ASSIG\\a5-6-holmogigi\\List.html",
                             nullptr, nullptr,SW_SHOWNORMAL);
            else
                system("notepad.exe C:\\Users\\USER\\OneDrive\\Desktop\\UBB FMI\\SEM 2\\OOP_ ASSIG\\a5-6-holmogigi\\List.csv");
        }
    });
    QObject::connect(this->addButton, &QPushButton::clicked, this, &UserGUI::addEvent);
    QObject::connect(this->filterButton, &QPushButton::clicked, this, &UserGUI::filterEvents);
    QObject::connect(this->removeButton, &QPushButton::clicked, this, &UserGUI::removeEvent);
}

int UserGUI::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->eventsListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.empty()){
        this->titleLineEdit->clear();
        this->descriptionLineEdit->clear();
        this->dateLineEdit->clear();
        this->numberLineEdit->clear();
        this->linkLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void UserGUI::addEvent() {
    if(!this->repoTypeSelected){
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText("Select the type of file");
        error->setWindowTitle("File warning");
        error->exec();
    }else
    {
        std::string title = this->titleLineEdit->text().toStdString();
        std::string description = this->descriptionLineEdit->text().toStdString();
        std::string date_time = this->dateLineEdit->text().toStdString();
        std::string number_s = this->numberLineEdit->text().toStdString();
        std::string link = this->linkLineEdit->text().toStdString();
        int number;
        try{
            this->validator.validateTitle(title);
            this->validator.validateDescription(description);
            this->validator.validateDateTime(date_time);
            this->validator.validatePeopleString(number_s);
            number = stoi(number_s);
            this->validator.validatePeople(number);
            this->validator.validateLink(link);
            Event event = Event(title, description, date_time, number, link);
            event.set_number_people(event.get_number_people() + 1);
            this->userService.addUserService(event);
            //if(!this->filtered)
            //  this->populateEventList();
            //else
            this->userListWidget->addItem(this->eventsListWidget->takeItem(this->getSelectedIndex()));

            //this->populateUserList();
        }catch(ValidatorException& exc){
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Critical);
            error->setText(exc.what());
            error->setWindowTitle("Invalid input");
            error->exec();
        }catch(RepositoryException& re){
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Critical);
            error->setText(re.what());
            error->setWindowTitle("Couldn't add event");
            error->exec();
        }
    }
}

void UserGUI::filterEvents() {

    std::string month_filter = this->monthFilterLineEdit->text().toStdString();
    int month;
    if(month_filter.empty()){
        this->filtered = false;
        this->eventsListWidget->clear();
        this->populateEventList();
    }else{
        month = stoi(month_filter);
        std::vector<Event> validEvents;
        this->userService.filterByMonth(validEvents, month_filter);
        if(validEvents.empty()){
            std::string error;
            error += std::string("There are no available events");
            if(!error.empty())
                throw UserException(error);
        }else{
            this->filtered = true;
            this->eventsListWidget->clear();
            for(Event& event: validEvents)
                this->eventsListWidget->addItem(QString::fromStdString(event.get_link()));
        }
    }

}

void UserGUI::removeEvent() {
    if(!this->repoTypeSelected){
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText("Select the type of file");
        error->setWindowTitle("File warning");
        error->exec();
    }else{
        std::string link = this->linkLineEdit->text().toStdString();
        try{
            this->validator.validateLink(link);
            int index = this->service.searchService(link);
            Event event = this->service.getAllService()[index];
            this->userService.removeUserService(link);
            //event.set_number_people(event.get_number_people() - 1);
            this->eventsListWidget->addItem(this->userListWidget->takeItem(this->getSelectedIndex()));
            if(this->userService.getUserRepo()->getSize() == 0)
                this->userListWidget->clear();
            if(this->userService.getUserRepo()->getSize() == 1)
                this->eventsListWidget->addItem(this->userListWidget->takeItem(0));
            //if(!this->filtered)
            //  this->populateEventList();
            //else
            //this->userListWidget->addItem(this->eventsListWidget->takeItem(this->getSelectedIndex()));
            //this->populateUserList();
        }catch(ValidatorException& exc){
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Critical);
            error->setText(exc.what());
            error->setWindowTitle("Invalid input");
            error->exec();
        }catch(RepositoryException& re){
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Critical);
            error->setText(re.what());
            error->setWindowTitle("Couldn't remove event");
            error->exec();
        }
    }
}

UserGUI::~UserGUI() = default;