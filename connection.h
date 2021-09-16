#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDebug>
#include <QApplication>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlError>
#include <QMessageBox>

class Connection
{
public:
    Connection();
    Connection(QString login, QString password);
    QSqlQueryModel* SetQuery(QString someQuery);
    void close();
    bool isOk();


private:
    void Connecting(QString login, QString password);
    QSqlDatabase database;
    bool ok;

};

#endif // CONNECTION_H
