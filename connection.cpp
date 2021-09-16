#include "connection.h"

Connection::Connection() {

}

Connection::Connection(QString login, QString password){
    Connecting(login, password);
}

QSqlQueryModel *Connection::SetQuery(QString someQuery){
    QSqlQueryModel *queryModel = new QSqlQueryModel(nullptr);
    if(!ok){
        QMessageBox::critical(NULL,QObject::tr("Соединение"), QObject::tr("Ошибка подключения"));
    } else {
        QSqlQuery query(database);
        if(!query.exec(someQuery)){
            QMessageBox::critical(NULL,QObject::tr("Соединение"), query.lastError().text());
        } else {
            queryModel->setQuery(query);
        }
    }
    return queryModel;
}

void Connection::close() {
    if(ok){
        database.close();
    }
}

void Connection::Connecting(QString login, QString password) {
    database = QSqlDatabase::addDatabase("QPSQL");
    database.setHostName("localhost");
    database.setDatabaseName("postgres");
    database.setUserName(login);
    database.setPassword(password);
    database.setPort(5432);
    ok = database.open();
}
