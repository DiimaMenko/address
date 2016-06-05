#include "contact.h"

contact::contact()
{

}

contact::contact(QString name, QString address, QString skypeLogin, QString rc){
    this->_name = name;
    this->_address = address;
    this->_skypeLogin = skypeLogin;
    this->_rc = rc;
}

QString contact::name(){
    return this->_name;
}

QString contact::skypeLogin(){
    return this->_skypeLogin;
}

QString contact::address(){
    return this->_address;
}

QString contact::rc(){
    return this->_rc;
}

void contact::setName(QString name){
    this->_name = name;
}

void contact::setAddress(QString address){
    this->_address = address;
}

void contact::setSkypeLogin(QString skypeLogin){
    this->_skypeLogin = skypeLogin;
}

void contact::setRaidCallNumber(QString rc){
    this->_rc = rc;
}
