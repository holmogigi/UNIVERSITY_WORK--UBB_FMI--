#pragma once
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class GUI_UI; }
QT_END_NAMESPACE

class GUI_UI : public QWidget {
Q_OBJECT

public:
    explicit GUI_UI(QWidget *parent = nullptr);

    ~GUI_UI() override;

private:
    Ui::GUI_UI *ui;
};



