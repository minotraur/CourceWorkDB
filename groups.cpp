#include "groups.h"
#include "ui_groups.h"

#include "connection.h"

Groups::Groups(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Groups)
{
    ui->setupUi(this);



    con = new Connection("admin", "1234");
    QSqlQueryModel *ModelForUpdate = new QSqlQueryModel(ui->comboBox_update);
    ModelForUpdate->setQuery("SELECT id_group FROM \"Groups\"");
    ui->comboBox_update->setModel(ModelForUpdate);

    QSqlQueryModel *ModelForDelete = new QSqlQueryModel(ui->comboBox_delete);
    ModelForDelete->setQuery("SELECT id_group FROM \"Groups\"");
    ui->comboBox_delete->setModel(ModelForDelete);
}

Groups::~Groups()
{
    delete ui;
}

void Groups::on_pushButton_insert_clicked()
{
    QSqlQuery query(database);
    query.exec(QString("call insert_groups( %1, '%2', '%3' )").
               arg(ui->lineEdit_amount_insert->text()).
               arg(ui->lineEdit_group_insert->text()).
               arg(ui->lineEdit_special_insert->text()));

    ui->tableView->setModel(con->SetQuery("select amount_of_students as \"Количество студентов\", "
                                                                    "group_name as \"Название группы\", "
                                                                    "specialization as \"Специальность\" from \"Groups\""));
}

void Groups::on_pushButton_update_clicked()
{
    QSqlQuery query(database);
    query.exec(QString("call update_groups( %1, '%2', '%3', '%4' )").
               arg(ui->comboBox_update->currentIndex()).
               arg(ui->lineEdit_amount_update->text()).
               arg(ui->lineEdit_group_update->text()).
               arg(ui->lineEdit_special_update->text()));

    ui->tableView->setModel(con->SetQuery("select amount_of_students as \"Количество студентов\", "
                                                                    "group_name as \"Название группы\", "
                                                                    "specialization as \"Специальность\" from \"Groups\""));
}

void Groups::on_pushButton_delete_clicked()
{
    QSqlQuery query(database);
    query.exec(QString("call delete_groups('%1')").arg(ui->comboBox_delete->currentText()));
    ui->tableView->setModel(con->SetQuery("select amount_of_students as \"Количество студентов\", "
                                                                    "group_name as \"Название группы\", "
                                                                    "specialization as \"Специальность\" from \"Groups\""));
}
