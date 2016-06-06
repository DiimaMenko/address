#include "addwidget.h"

addWidget::addWidget(QWidget *parent) : QWidget(parent)
{
    this->nameLineEdit = new QLineEdit(this);
    this->addressLineEdit = new QLineEdit(this);
    this->skypeLoginLineEdit = new QLineEdit(this);
    this->raidCallLineEdit = new QLineEdit(this);
    this->nameLabel = new QLabel("Name", this);
    this->addressLabel = new QLabel("Address", this);
    this->skypeLoginLabel = new QLabel("Skype login", this);
    this->raidCallLabel = new QLabel("RaidCall", this);

    this->nameLabel->move(10,10);
    this->addressLabel->move(120, 10);
    this->skypeLoginLabel->move(230, 10);
    this->raidCallLabel->move(340, 10);
    this->nameLineEdit->move(10, 40);
    this->addressLineEdit->move(120, 40);
    this->skypeLoginLineEdit->move(230, 40);
    this->raidCallLineEdit->move(340, 40);

    this->nameLabel->resize(100, 30);
    this->addressLabel->resize(100, 30);
    this->skypeLoginLabel-> resize(100, 30);
    this->raidCallLabel-> resize(100, 30);
    this->nameLineEdit->resize(100, 30);
    this->addressLineEdit->resize(100, 30);
    this->skypeLoginLineEdit->resize(100, 30);
    this->raidCallLineEdit-> resize(100, 30);
}

contact *addWidget::getInfo(){
    contact *tempContact = new contact();
    tempContact->setName(this->nameLineEdit->text());
    tempContact->setAddress(this->addressLineEdit->text());
    tempContact->setRaidCallNumber(this->raidCallLineEdit->text());
    tempContact->setSkypeLogin(this->skypeLoginLineEdit->text());
    return tempContact;
}

void addWidget::okPressed(){
    this->hide();
}
