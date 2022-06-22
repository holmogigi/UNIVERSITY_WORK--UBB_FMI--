
#include "gui_ui.h"
#include "ui_GUI_UI.h"


GUI_UI::GUI_UI(QWidget *parent) :
        QWidget(parent), ui(new Ui::GUI_UI) {
    ui->setupUi(this);
}

GUI_UI::~GUI_UI() {
    delete ui;
}

