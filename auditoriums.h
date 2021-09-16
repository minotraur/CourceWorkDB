#ifndef AUDITORIUMS_H
#define AUDITORIUMS_H

#include <QDialog>
#include "connection.h"

namespace Ui {
class Auditoriums;
}

class Auditoriums : public QDialog
{
    Q_OBJECT

public:
    explicit Auditoriums(QWidget *parent = nullptr);
    ~Auditoriums();


private slots:

    void on_pushButton_insert_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::Auditoriums *ui;
    Connection *con;
    QSqlDatabase database;
};

#endif // AUDITORIUMS_H
