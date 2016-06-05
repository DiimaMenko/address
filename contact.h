#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class contact
{
private:
    QString _name;
    QString _address;
    QString _skypeLogin;
    QString _rc;
public:
    contact();
    contact(QString name, QString address, QString skypeLogin, QString rc);

    QString name();
    QString skypeLogin();
    QString address();
    QString rc();

    void setName(QString name);
    void setAddress(QString address);
    void setSkypeLogin(QString skypeLogin);
    void setRaidCallNumber(QString rc);
};

#endif // CONTACT_H
