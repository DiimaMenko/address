#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QString>
#include <QFile>
#include <QVector>
#include <contact.h>

class addressbook
{
private:
    QVector<contact *> _book;
public:
    addressbook();

    void addContact(QString name, QString address, QString skypeLogin);
    int deleteContact(QString name);
    int editContact(QString name, QString address, QString skypeLogin);
    int saveBook();
    int loadBook();
    contact getContact(int i);
    int size();
};

#endif // ADDRESSBOOK_H
