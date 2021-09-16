#include "teachers.h"
#include "ui_teachers.h"

Teachers::Teachers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Teachers)
{
    ui->setupUi(this);


    con = new Connection("admin", "1234");
    QSqlQueryModel *ModelForUpdate = new QSqlQueryModel(ui->comboBox_update);
    ModelForUpdate->setQuery("SELECT id_teacher FROM \"Teachers\"");
    ui->comboBox_update->setModel(ModelForUpdate);

    QSqlQueryModel *ModelForDelete = new QSqlQueryModel(ui->comboBox_delete);
    ModelForDelete->setQuery("SELECT id_teacher FROM \"Teachers\"");
    ui->comboBox_delete->setModel(ModelForDelete);




    QSqlQueryModel *ModelForComboBox_idgroup_update = new QSqlQueryModel(ui->comboBox_delete);
    ModelForComboBox_idgroup_update->setQuery("SELECT id_group FROM \"Groups\"");
    ui->comboBox_idgroup_update->setModel(ModelForComboBox_idgroup_update);


    QSqlQueryModel *ModelForIdgroup_insert = new QSqlQueryModel(ui->comboBox_delete);
    ModelForIdgroup_insert->setQuery("SELECT id_group FROM \"Groups\"");
    ui->comboBox_idgroup_insert->setModel(ModelForIdgroup_insert);


}

Teachers::~Teachers()
{
    delete ui;
}

void Teachers::on_pushButton_insert_clicked()
{

    QSqlQuery query(database);
    query.exec(QString("call insert_teacher('%1', '%2', '%3', %4, '%5')").
               arg(ui->lineEdit_lastname_insert->text()).
               arg(ui->lineEdit_firstname_insert->text()).
               arg(ui->lineEdit_middlename_insert->text()).
               arg(ui->comboBox_idgroup_insert->currentText()).
               arg(ui->lineEdit_facility_insert->text()));

    ui->tableView->setModel(con->SetQuery("select last_name as \"Фамилия\", "
                                                                    "first_name as \"Имя\", "
                                                                    "middle_name as \"Отчество\", "
                                                                    "id_group as \"Номер группы\", "
                                                                    "faculty as \"Факультет\" from \"Teachers\""));
}

void Teachers::on_pushButton_update_clicked()
{
    QSqlQuery query(database);
    query.exec(QString("call update_teacher(%1 ,'%2', '%3', '%4', %5, '%6')").
               arg(ui->comboBox_update->currentText()).
               arg(ui->lineEdit_lastname_update->text()).
               arg(ui->lineEdit_firstname_update->text()).
               arg(ui->lineEdit_middlename_update->text()).
               arg(ui->comboBox_idgroup_update->currentText()).
               arg(ui->lineEdit_facility_update->text()));
    ui->tableView->setModel(con->SetQuery("select last_name as \"Фамилия\", "
                                                                    "first_name as \"Имя\", "
                                                                    "middle_name as \"Отчество\", "
                                                                    "id_group as \"Номер группы\", "
                                                                    "faculty as \"Факультет\" from \"Teachers\""));
}

void Teachers::on_pushButton_delete_clicked()
{
    QSqlQuery query(database);
    query.exec(QString("call delete_teacher(%1)").arg(ui->comboBox_delete->currentText()));
    ui->tableView->setModel(con->SetQuery("select last_name as \"Фамилия\", "
                                                                    "first_name as \"Имя\", "
                                                                    "middle_name as \"Отчество\", "
                                                                    "id_group as \"Номер группы\", "
                                                                    "faculty as \"Факультет\" from \"Teachers\""));
}
