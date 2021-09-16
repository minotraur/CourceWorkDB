#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QDialog>
#include "connection.h"

namespace Ui {
class Schedule;
}

class Schedule : public QDialog
{
    Q_OBJECT

public:
    explicit Schedule(QWidget *parent = nullptr);
    ~Schedule();

private slots:
    void on_pushButton_insert_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::Schedule *ui;
    Connection *con;
    QSqlDatabase database;
};

#endif // SCHEDULE_H
