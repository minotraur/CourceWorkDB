#ifndef GROUPS_H
#define GROUPS_H

#include <QDialog>
#include "connection.h"

namespace Ui {
class Groups;
}

class Groups : public QDialog
{
    Q_OBJECT

public:
    explicit Groups(QWidget *parent = nullptr);
    ~Groups();

private slots:
    void on_pushButton_insert_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::Groups *ui;
    Connection *con;
    QSqlDatabase database;
};

#endif // GROUPS_H
