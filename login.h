#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"
#include "mainuser.h"
#include <QMessageBox>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_auth_clicked();

private:
    Ui::Login *ui;
    MainWindow m;
    Mainuser mainuser;
};

#endif // LOGIN_H
