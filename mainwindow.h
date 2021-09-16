#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>

#include "edit.h"
#include "connection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_editDB_clicked();

    void on_pushButton_JoinCase_clicked();

    void on_pushButton_View_clicked();

    void on_pushButton_Corel_clicked();

    void on_pushButton_Group_clicked();

    void on_pushButton_Any_clicked();

    void on_pushButton_Delete_clicked();

    void on_pushButton_Scalar_clicked();

    void on_pushButton_Vector_clicked();

    void on_pushButton_checkDB_clicked();

private:
    Ui::MainWindow *ui;
    Edit editor;
    QSqlTableModel * model = new QSqlTableModel;
    Connection *connector;
    QStringList tables;
};
#endif // MAINWINDOW_H
