#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QVector>

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include "addressbook.h"

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
    void addContact();
    void deleteContact();
    void editContact();
    void callSkype();

private:
    Ui::MainWindow *ui;

    addressbook *someBook;
    QVector<QLabel *> nameLabels;
    QVector<QPushButton *> skypeLoginButtons;
    QVector<QLabel *> addressLineEdits;
    QVector<QLabel *> skypeLoginLineEdits;
    QVector<QPushButton *> deleteContactButtons;
    QPushButton *addContactButton;
    QLabel *nameLabel;
    QLabel *addressLabel;
    QLabel *skypeLoginLabel;
};

#endif // MAINWINDOW_H
