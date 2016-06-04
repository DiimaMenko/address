#include "addressbook.h"

addressbook::addressbook()
{
    for(int i = 0; i < 10; i++){
        contact *tempContact = new contact("person" + QString::number(i), "asdf", "asdffdsa" + QString::number(i));
        this->_book.push_back(tempContact);
    }
}

void addressbook::addContact(QString name, QString address, QString skypeLogin){
    contact *tempContact = new contact(name, address, skypeLogin);
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

int addressbook::editContact(QString name, QString address, QString skypeLogin){
    if(name.isEmpty()){
        return 2; //пустое имя
    }
    for(int i = 0; i < this->_book.size(); i++){
        if(this->_book[i]->name() == name){
            this->_book[i]->setAddress(address);
            this->_book[i]->setSkypeLogin(skypeLogin);
            return 0;//успех
        }
    }
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
