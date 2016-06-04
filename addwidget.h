#ifndef ADDWIDGET_H
#define ADDWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "contact.h"
#include <QLineEdit>
#include <QLabel>

class addWidget : QWidget
{
private:
    QPushButton *okButton;
    QLineEdit *nameLineEdit;
    QLineEdit *addressLineEdit;
    QLineEdit *skypeLoginLineEdit;
    QLabel *nameLabel;
    QLabel *addressLabel;
    QLabel *skypeLoginLabel;
public:
    addWidget();

    contact getInfo();

public slots:

    void okPressed();
};

#endif // ADDWIDGET_H
