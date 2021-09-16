#include "edit.h"
#include "ui_edit.h"

#include <QMessageBox>
#include <QSqlError>


Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);  
    con = new Connection("admin", "1234");
    ui->comboBox->addItem("Аудитории");
    ui->comboBox->addItem("Группы");
    ui->comboBox->addItem("Расписание");
    ui->comboBox->addItem("Преподаватели");


}

Edit::~Edit()
{
    delete ui;
}

void Edit::on_pushButton_Auditoriums_clicked()
{
    ui->tableView_Edit->setModel(con->SetQuery("select capacity as \"Вместимость\", "
                                                                    "number_auditorium as \"Номер аудитории\", "
                                                                    "equipment_available as \"Наличие оборудования\" , "
                                                                    "name_of_auditorium as \"Название аудитории\" from \"Auditoriums\""));
}

void Edit::on_pushButton_Groups_clicked()
{
    ui->tableView_Edit->setModel(con->SetQuery("select amount_of_students as \"Количество студентов\", "
                                                                    "group_name as \"Название группы\", "
                                                                    "specialization as \"Специальность\" from \"Groups\""));
}

void Edit::on_pushButton_Schedule_clicked()
{
    ui->tableView_Edit->setModel(con->SetQuery("select id_teacher as \"Номер преподавателя\", "
                                                                    "pair_number as \"Номер пары\", "
                                                                    "id_auditorium as \"Номер аудитории\", "
                                                                    "type_of_work as \"Вид занятия\", "
                                                                    "discipline as \"Дисциплина\" from \"Schedule\""));
}

void Edit::on_pushButton_Teachers_clicked()
{
    ui->tableView_Edit->setModel(con->SetQuery("select last_name as \"Фамилия\", "
                                                                    "first_name as \"Имя\", "
                                                                    "middle_name as \"Отчество\", "
                                                                    "id_group as \"Номер группы\", "
                                                                    "faculty as \"Факультет\" from \"Teachers\""));
}

void Edit::on_pushButton_TriggerList_clicked()
{

    con = new Connection("admin", "1234");
    ui->tableView_Edit->setModel(con->SetQuery("select someInfo as \"Инфомация об изменении таблицы\" from trigger_list"));
}

void Edit::on_pushButton_openToEdit_clicked()
{
    tables<<"Аудитории"<<"Группы"<<"Расписание"<<"Преподаватели";
    switch (tables.indexOf(ui->comboBox->currentText())) {
        case 0:{
            audi.show();
            break;
        }
        case 1:{
            group.show();
            break;
        }
        case 2:{
            sche.show();
            break;
        }
        case 3:{
            teach.show();
            break;
        }
    }
}
