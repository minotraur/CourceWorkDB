#ifndef TEACHERS_H
#define TEACHERS_H

#include <QDialog>
#include "connection.h"

namespace Ui {
class Teachers;
}

class Teachers : public QDialog
{
    Q_OBJECT

public:
    explicit Teachers(QWidget *parent = nullptr);
    ~Teachers();

private slots:

    void on_pushButton_insert_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::Teachers *ui;
    Connection *con;
    QSqlDatabase database;
};

#endif // TEACHERS_H
