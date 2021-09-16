#include "auditoriums.h"
#include "ui_auditoriums.h"
#include "connection.h"

Auditoriums::Auditoriums(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Auditoriums)
{
    ui->setupUi(this);

    con = new Connection("admin", "1234");
    QSqlQueryModel *ModelForUpdate = new QSqlQueryModel(ui->comboBox_update);
    ModelForUpdate->setQuery("SELECT id_auditorium FROM \"Auditoriums\"");
    ui->comboBox_update->setModel(ModelForUpdate);


    QSqlQueryModel *ModelForDelete = new QSqlQueryModel(ui->comboBox_delete);
    ModelForDelete->setQuery("SELECT id_auditorium FROM \"Auditoriums\"");
    ui->comboBox_delete->setModel(ModelForDelete);


    QSqlQueryModel *ModelForUpdateNumber = new QSqlQueryModel(ui->comboBox_numberaudi_update);
    ModelForUpdateNumber->setQuery("SELECT id_auditorium FROM \"Auditoriums\"");
    ui->comboBox_numberaudi_update->setModel(ModelForUpdateNumber);


}

Auditoriums::~Auditoriums()
{
    delete ui;
}

void Auditoriums::on_pushButton_insert_clicked()
{
    QSqlQuery query(database);
    query.exec(QString("call insert_auditoriums(%1,%2,%3,'%4','%5')").
               arg(ui->lineEdit_id_insert->text()).
               arg(ui->lineEdit_capacity_insert->text()).
               arg(ui->lineEdit_numberaudi_insert->text()).
               arg(ui->lineEdit_equipment_insert->text()).
               arg(ui->lineEdit_namesudi_insert->text()));

    ui->tableView->setModel(con->SetQuery("select capacity as \"Вместимость\", "
                                                                    "number_auditorium as \"Номер аудитории\", "
                                                                    "equipment_available as \"Наличие оборудования\" , "
                                                                    "name_of_auditorium as \"Название аудитории\" from \"Auditoriums\""));

    ui->comboBox_update->update();
    ui->comboBox_numberaudi_update->update();
    ui->comboBox_delete->update();

}

void Auditoriums::on_pushButton_update_clicked()
{
    QSqlQuery query(database);
    query.exec(QString("call update_auditoriums(%1,%2,%3,'%4','%5')").
               arg(ui->comboBox_update->currentIndex()).
               arg(ui->lineEdit_capacity_update->text()).
               arg(ui->comboBox_numberaudi_update->currentIndex()).
               arg(ui->lineEdit_equipment_update->text()).
               arg(ui->lineEdit_namesudi_update->text()));

    ui->tableView->setModel(con->SetQuery("select capacity as \"Вместимость\", "
                                                                    "number_auditorium as \"Номер аудитории\", "
                                                                    "equipment_available as \"Наличие оборудования\" , "
                                                                    "name_of_auditorium as \"Название аудитории\" from \"Auditoriums\""));
    ui->comboBox_update->update();
    ui->comboBox_numberaudi_update->update();
    ui->comboBox_delete->update();
}

void Auditoriums::on_pushButton_delete_clicked()
{
    QSqlQuery query(database);
    query.exec(QString("call delete_auditoriums(%1)").arg(ui->comboBox_delete->currentText()));
    ui->tableView->setModel(con->SetQuery("select capacity as \"Вместимость\", "
                                                                    "number_auditorium as \"Номер аудитории\", "
                                                                    "equipment_available as \"Наличие оборудования\" , "
                                                                    "name_of_auditorium as \"Название аудитории\" from \"Auditoriums\""));
    ui->comboBox_update->update();
    ui->comboBox_numberaudi_update->update();
    ui->comboBox_delete->update();
}
