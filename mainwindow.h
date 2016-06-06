#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QVector>

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include "addressbook.h"
#include "addwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addContact(int i);
    void addContactPressed();
    void deleteContact();
    void editContact();
    void callSkype();
    void callRC();
    void okAddPressed();
    void clearAll(int i);

private:
    Ui::MainWindow *ui;

    addressbook *someBook;
    QVector<QLabel *> nameLabels;
    QVector<QPushButton *> skypeLoginButtons;
    QVector<QLabel *> addressLabels;
    QVector<QPushButton *> deleteContactButtons;
    QVector<QPushButton *> rcButtons;
    QPushButton *addContactButton;
    QLabel *nameLabel;
    QLabel *addressLabel;
    QLabel *skypeLoginLabel;
    QLabel *rcLabel;
    addWidget *widget;
    QPushButton *okAddButton;
};

#endif // MAINWINDOW_H
