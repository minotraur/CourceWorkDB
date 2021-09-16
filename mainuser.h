#ifndef MAINUSER_H
#define MAINUSER_H

#include <QDialog>
#include "connection.h"

namespace Ui {
class Mainuser;
}

class Mainuser : public QDialog
{
    Q_OBJECT

public:
    explicit Mainuser(QWidget *parent = nullptr);
    ~Mainuser();

private slots:

    void on_pushButton_audi_clicked();

    void on_pushButton_group_clicked();

    void on_pushButton_sche_clicked();

    void on_pushButton_teach_clicked();

private:
    Ui::Mainuser *ui;
    Connection *con;
};

#endif // MAINUSER_H
