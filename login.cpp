#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

#include <QMessageBox>


Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_auth_clicked()
{
    QMessageBox msgBox(QMessageBox::Information,
                   "Incorrect data",
                   "Wrong login or password!",QMessageBox::Ok);
    msgBox.button(QMessageBox::Ok)->setObjectName(QStringLiteral("okButton"));
    msgBox.setStyleSheet(QStringLiteral("#okButton {"
                                            "width: 80px;"
                                            "height: 30px;"
                                            "background-color:rgb(41, 143, 204);"
                                            "color:white;"
                                            "font-family: 'Alegreya Sans', sans-serif;text-align:center;"
                                            "font-size:18px;"
                                            "text-decoration: none;"
                                            "text-align:center;"
                                            "border: none;}"));
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_pass->text();
    if(login == "admin" && password == "1234"){
        this->close();
        m.show();
    } else if(login == "mainuser" && password == "1234"){
        this->close();
        mainuser.show();
    } else {
        msgBox.exec();
        return;
    }
}
