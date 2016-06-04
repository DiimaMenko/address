#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class contact
{
private:
    QString _name;
    QString _address;
    QString _skypeLogin;
public:
    contact();
    contact(QString name, QString address, QString skypeLogin);

    QString name();
    QString skypeLogin();
    QString address();

    void setName(QString name);
    void setAddress(QString address);
    void setSkypeLogin(QString skypeLogin);
};

#endif // CONTACT_H
