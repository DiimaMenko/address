#ifndef ADDWIDGET_H
#define ADDWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "contact.h"
#include <QLineEdit>
#include <QLabel>

class addWidget : public QWidget
{
    Q_OBJECT
public:
    explicit addWidget(QWidget *parent = 0);
public slots:
    void okPressed();
    contact *getInfo();
    void clear();

private:
    QLineEdit *nameLineEdit;
    QLineEdit *addressLineEdit;
    QLineEdit *skypeLoginLineEdit;
    QLineEdit *raidCallLineEdit;
    QLabel *nameLabel;
    QLabel *addressLabel;
    QLabel *skypeLoginLabel;
    QLabel *raidCallLabel;
};

#endif // ADDWIDGET_H
