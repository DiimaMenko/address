#include "addwidget.h"

addWidget::addWidget()
{
    this->okButton = new QPushButton("Ok", this);
    this->nameLineEdit = new QLineEdit(this);
    this->addressLineEdit = new QLineEdit(this);
    this->skypeLoginLineEdit = new QLineEdit(this);
    this->raidCallLineEdit = new QLineEdit(this);
    this->nameLabel = new QLabel("Name", this);
    this->addressLabel = new QLabel("Address", this);
    this->skypeLoginLabel = new QLabel("Skype login", this);
    this->raidCallLabel = new QLabel("RaidCall", this);
}

contact addWidget::getInfo(){

}

void addWidget::okPressed(){

}
