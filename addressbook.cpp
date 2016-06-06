#include "addressbook.h"

addressbook::addressbook()
{

}

void addressbook::addContact(QString name, QString address, QString skypeLogin, QString rc){
    contact *tempContact = new contact(name, address, skypeLogin, rc);
    this->_book.push_back(tempContact);
}

void addressbook::addContact(contact *some){
    contact *tempContact = some;
    this->_book.push_back(tempContact);
}

int addressbook::deleteContact(QString name){
    if(name.isEmpty()){
        return 2;//пустое имя
    }
    for(int i = 0; i < this->_book.size(); i++){
        if(this->_book[i]->name() == name){
            this->_book.erase(this->_book.begin() + i);
            return 0;//успех
        }
    }
    return 1;//обьект не найден
}

int addressbook::editContact(QString name, QString address, QString skypeLogin, QString rc){
    if(name.isEmpty()){
        return 2; //пустое имя
    }
    for(int i = 0; i < this->_book.size(); i++){
        if(this->_book[i]->name() == name){
            this->_book[i]->setAddress(address);
            this->_book[i]->setSkypeLogin(skypeLogin);
            this->_book[i]->setRaidCallNumber(rc);
            return 0;//успех
        }
    }
    return 1;
}

contact addressbook::getContact(int i){
    if(i < this->_book.size()){
        return *this->_book[i];
    }
}

int addressbook::size(){
    return this->_book.size();
}

int addressbook::saveBook(){

}

int addressbook::loadBook(){

}
