#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(740, 480);

    this->someBook = new addressbook();

    this->nameLabel = new QLabel("Name", this);
    this->addressLabel = new QLabel("Address", this);
    this->skypeLoginLabel = new QLabel("Skype login", this);

    this->nameLabel->move(20, 10);
    this->nameLabel->resize(100, 30);
    this->nameLabel->show();

    this->addressLabel->move(130, 10);
    this->addressLabel->resize(100, 30);
    this->addressLabel->show();

    this->skypeLoginLabel->move(340, 10);
    this->skypeLoginLabel->resize(100, 30);
    this->skypeLoginLabel->show();

    this->addContactButton = new QPushButton("Add contact", this);
    this->addContactButton->resize(150, 30);
    this->addContactButton->move(570, 50);
    this->addContactButton->show();

    connect(this->addContactButton, SIGNAL(clicked(bool)), this, SLOT(addContact()));

    for(int i = 0; i < someBook->size(); i++){
        QLabel *tempNameLabel = new QLabel(this->someBook->getContact(i).name(), this);
        QPushButton *tempSkypeButton = new QPushButton(this);
        QPushButton *tempDeleteButton = new QPushButton(this);
        QLabel *tempAddressLabel = new QLabel(this->someBook->getContact(i).address(), this);
        QLabel *tempSkypeLabel = new QLabel(this->someBook->getContact(i).skypeLogin(), this);

        tempNameLabel->move(20, 40 * i + 50);
        tempNameLabel->resize(100, 30);
        tempNameLabel->show();

        tempAddressLabel->move(130, 40 * i + 50);
        tempAddressLabel->resize(200, 30);
        tempAddressLabel->show();

        tempSkypeLabel->move(340, 40 * i + 50);
        tempSkypeLabel->resize(100, 30);
        tempSkypeLabel->show();

        tempSkypeButton->move(450, 40 * i + 50);
        tempSkypeButton->resize(50, 30);
        tempSkypeButton->setText("Call");
        tempSkypeButton->show();
        tempSkypeButton->setObjectName(this->someBook->getContact(i).skypeLogin());

        tempDeleteButton->move(510, 40 * i + 50);
        tempDeleteButton->resize(50, 30);
        tempDeleteButton->setText("Delete");
        tempDeleteButton->show();

        this->nameLabels.push_back(tempNameLabel);
        this->addressLineEdits.push_back(tempAddressLabel);
        this->skypeLoginButtons.push_back(tempSkypeButton);
        this->deleteContactButtons.push_back(tempDeleteButton);
        this->skypeLoginLineEdits.push_back(tempSkypeLabel);

        connect(this->skypeLoginButtons[i], SIGNAL(clicked(bool)), this, SLOT(callSkype()));
        connect(this->deleteContactButtons[i], SIGNAL(clicked(bool)), this, SLOT(deleteContact()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::callSkype(){

    QString link = "skype:" + QObject::sender()->objectName() + "?call";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::deleteContact(){

}

void MainWindow::addContact(){

}

void MainWindow::editContact(){

}
