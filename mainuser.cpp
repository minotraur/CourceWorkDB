#include "mainuser.h"
#include "ui_mainuser.h"
#include "connection.h"

Mainuser::Mainuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mainuser)
{
    ui->setupUi(this);
    con = new Connection("mainuser", "1234");
}

Mainuser::~Mainuser()
{
    delete ui;
}

void Mainuser::on_pushButton_audi_clicked()
{
    ui->tableView->setModel(con->SetQuery("select capacity as \"Вместимость\", "
                                                                    "number_auditorium as \"Номер аудитории\", "
                                                                    "equipment_available as \"Наличие оборудования\" , "
                                                                    "name_of_auditorium as \"Название аудитории\" from \"Auditoriums\""));
}

void Mainuser::on_pushButton_group_clicked()
{
    ui->tableView->setModel(con->SetQuery("select amount_of_students as \"Количество студентов\", "
                                                                    "group_name as \"Название группы\", "
                                                                    "specialization as \"Специальность\" from \"Groups\""));
}

void Mainuser::on_pushButton_sche_clicked()
{
    ui->tableView->setModel(con->SetQuery("select id_teacher as \"Номер преподавателя\", "
                                                                    "pair_number as \"Номер пары\", "
                                                                    "id_auditorium as \"Номер аудитории\", "
                                                                    "type_of_work as \"Вид занятия\", "
                                                                    "discipline as \"Дисциплина\" from \"Schedule\""));
}

void Mainuser::on_pushButton_teach_clicked()
{
    ui->tableView->setModel(con->SetQuery("select last_name as \"Фамилия\", "
                                                                    "first_name as \"Имя\", "
                                                                    "middle_name as \"Отчество\", "
                                                                    "id_group as \"Номер группы\", "
                                                                    "faculty as \"Факультет\" from \"Teachers\""));
}
