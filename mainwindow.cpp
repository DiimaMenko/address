#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1240, 700);

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

    this->widget = new addWidget(this);
    this->widget->resize(450, 200);
    this->widget->move(710, 10);
    this->widget->hide();

    this->addContactButton = new QPushButton("Add contact", this);
    this->addContactButton->resize(150, 30);
    this->addContactButton->move(570, 50);
    this->addContactButton->show();
    connect(this->addContactButton, SIGNAL(clicked(bool)), this, SLOT(addContactPressed()));

    this->okAddButton = new QPushButton("Finish adding", this);
    this->okAddButton->move(570, 50);
    this->okAddButton->resize(150, 30);
    this->okAddButton->hide();
    connect(this->okAddButton, SIGNAL(clicked(bool)), this, SLOT(okAddPressed()));


    for(int i = 0; i < someBook->size(); i++){
        addContact(i);
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

void MainWindow::callRC(){
    QString link = "raidcall:" + QObject::sender()->objectName() + "?go";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::deleteContact(){
    for(int i = 0; i < this->someBook->size(); i++){
        clearAll(i);
    }
    this->someBook->deleteContact(QObject::sender()->objectName());
    this->nameLabels.resize(0);
    this->addressLabels.resize(0);
    this->skypeLoginButtons.resize(0);
    this->rcButtons.resize(0);
    this->deleteContactButtons.resize(0);
    for(int i = 0; i < this->someBook->size(); i++){
        addContact(i);
    }
}

void MainWindow::addContactPressed(){
    this->addContactButton->hide();
    this->okAddButton->show();
    this->widget->clear();
    this->widget->show();
}

void MainWindow::editContact(){

}

void MainWindow::clearAll(int i){
    this->nameLabels[i]->hide();//names
    this->skypeLoginButtons[i]->hide();//skype
    this->addressLabels[i]->hide();//address
    this->deleteContactButtons[i]->hide();//delete
    this->rcButtons[i]->hide();//raid call
}

void MainWindow::okAddPressed(){
    contact *tempContact = this->widget->getInfo();
    this->someBook->addContact(tempContact);
    addContact(this->someBook->size() - 1);
    this->widget->hide();
    this->okAddButton->hide();
    this->addContactButton->show();
}

void MainWindow::addContact(int i){
    QLabel *tempNameLabel = new QLabel(this->someBook->getContact(i).name(), this);
    QPushButton *tempSkypeButton = new QPushButton(this);
    QPushButton *tempDeleteButton = new QPushButton(this);
    QPushButton *tempRCButton = new QPushButton(this);
    QLabel *tempAddressLabel = new QLabel(this->someBook->getContact(i).address(), this);

    tempNameLabel->move(20, 40 * i + 50);
    tempNameLabel->resize(100, 30);
    tempNameLabel->show();

    tempAddressLabel->move(130, 40 * i + 50);
    tempAddressLabel->resize(200, 30);
    tempAddressLabel->show();

    tempSkypeButton->move(340, 40 * i + 50);
    tempSkypeButton->resize(100, 30);
    tempSkypeButton->setText(this->someBook->getContact(i).skypeLogin());
    tempSkypeButton->show();
    tempSkypeButton->setObjectName(this->someBook->getContact(i).skypeLogin());

    tempRCButton->move(450, 40 * i + 50);
    tempRCButton->resize(50,30);
    tempRCButton->setText(this->someBook->getContact(i).rc());
    tempRCButton->show();
    tempRCButton->setObjectName(this->someBook->getContact(i).rc());

    tempDeleteButton->move(510, 40 * i + 50);
    tempDeleteButton->resize(50, 30);
    tempDeleteButton->setText("Delete");
    tempDeleteButton->show();
    tempDeleteButton->setObjectName(this->someBook->getContact(i).name());

    this->nameLabels.push_back(tempNameLabel);
    this->addressLabels.push_back(tempAddressLabel);
    this->skypeLoginButtons.push_back(tempSkypeButton);
    this->deleteContactButtons.push_back(tempDeleteButton);
    this->rcButtons.push_back(tempRCButton);

    connect(this->skypeLoginButtons[i], SIGNAL(clicked(bool)), this, SLOT(callSkype()));
    connect(this->rcButtons[i], SIGNAL(clicked(bool)), this,SLOT(callRC()));
    connect(this->deleteContactButtons[i], SIGNAL(clicked(bool)), this, SLOT(deleteContact()));
}
