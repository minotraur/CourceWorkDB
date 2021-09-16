#include "schedule.h"
#include "ui_schedule.h"

Schedule::Schedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Schedule)
{
    ui->setupUi(this);



    con = new Connection("admin", "1234");

    //------------------------------------------------------------------------------------------

    // для insert
    QSqlQueryModel *ModelForUpdate = new QSqlQueryModel(ui->comboBox_update);
    ModelForUpdate->setQuery("SELECT id_schedule FROM \"Schedule\"");
    ui->comboBox_update->setModel(ModelForUpdate);

    // для update
    QSqlQueryModel *ModelForDelete = new QSqlQueryModel(ui->comboBox_delete);
    ModelForDelete->setQuery("SELECT id_schedule FROM \"Schedule\"");
    ui->comboBox_delete->setModel(ModelForDelete);

    //------------------------------------------------------------------------------------------


    //------------------------------------------------------------------------------------------

    // Для comboBox_teacher insert
    QSqlQueryModel *ModelForInsertIdTeacher = new QSqlQueryModel(ui->comboBox_idteacher);
    ModelForInsertIdTeacher->setQuery("SELECT id_teacher FROM \"Teachers\"");
    ui->comboBox_idteacher->setModel(ModelForInsertIdTeacher);

    // Для comboBox_teacher update
    QSqlQueryModel *ModelForUpdateIdTeacher = new QSqlQueryModel(ui->comboBox_idteacher_update);
    ModelForUpdateIdTeacher->setQuery("SELECT id_teacher FROM \"Teachers\"");
    ui->comboBox_idteacher_update->setModel(ModelForUpdateIdTeacher);

    //------------------------------------------------------------------------------------------


    //------------------------------------------------------------------------------------------

    // Для comboBox_idaudi insert
    QSqlQueryModel *ModelForInsertIdAuditorium = new QSqlQueryModel(ui->comboBox_idaudi);
    ModelForInsertIdAuditorium->setQuery("SELECT id_auditorium FROM \"Auditoriums\"");
    ui->comboBox_idaudi->setModel(ModelForInsertIdAuditorium);

    // Для comboBox_idaudi_update update
    QSqlQueryModel *ModelForUpdateIdAuditorium = new QSqlQueryModel(ui->comboBox_idaudi_update);
    ModelForUpdateIdAuditorium->setQuery("SELECT id_auditorium FROM \"Auditoriums\"");
    ui->comboBox_idaudi_update->setModel(ModelForUpdateIdAuditorium);

    //------------------------------------------------------------------------------------------



}

Schedule::~Schedule()
{
    delete ui;
}

void Schedule::on_pushButton_insert_clicked()
{
    QSqlQuery query(database);
    query.exec(QString("call insert_schedule(%1,%2,%3,'%4','%5')").
                                           arg(ui->comboBox_idteacher->currentText()).
                                           arg(ui->lineEdit_pairnum_insert->text()).
                                           arg(ui->comboBox_idaudi->currentText()).
                                           arg(ui->lineEdit_typeofwork_insert->text()).
                                           arg(ui->lineEdit_discipline_insert->text()));

    ui->tableView->setModel(con->SetQuery("select id_teacher as \"Номер преподавателя\", "
                                                                    "pair_number as \"Номер пары\", "
                                                                    "id_auditorium as \"Номер аудитории\", "
                                                                    "type_of_work as \"Вид занятия\", "
                                                                    "discipline as \"Дисциплина\" from \"Schedule\""));
}

void Schedule::on_pushButton_update_clicked()
{
    QSqlQuery query(database);
    query.exec(QString("call update_schedule(%1,%2,'%3',%4,'%5','%6')").
                                               arg(ui->comboBox_update->currentText()).
                                               arg(ui->comboBox_idteacher_update->currentText()).
                                               arg(ui->lineEdit_pairnum_update->text()).
                                               arg(ui->comboBox_idaudi_update->currentText()).
                                               arg(ui->lineEdit_typeofwork_update->text()).
                                               arg(ui->lineEdit_discipline_update->text()));

    ui->tableView->setModel(con->SetQuery("select id_teacher as \"Номер преподавателя\", "
                                                                    "pair_number as \"Номер пары\", "
                                                                    "id_auditorium as \"Номер аудитории\", "
                                                                    "type_of_work as \"Вид занятия\", "
                                                                    "discipline as \"Дисциплина\" from \"Schedule\""));
}

void Schedule::on_pushButton_delete_clicked()
{
    QSqlQuery query(database);
    query.exec(QString("call delete_schedule(%1)").arg(ui->comboBox_delete->currentText()));
    ui->tableView->setModel(con->SetQuery("select id_teacher as \"Номер преподавателя\", "
                                                                    "pair_number as \"Номер пары\", "
                                                                    "id_auditorium as \"Номер аудитории\", "
                                                                    "type_of_work as \"Вид занятия\", "
                                                                    "discipline as \"Дисциплина\" from \"Schedule\""));
}
