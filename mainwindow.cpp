#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"

#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connector = new Connection("admin", "1234");
    ui->comboBox->addItem("Аудитории");
    ui->comboBox->addItem("Группы");
    ui->comboBox->addItem("Расписание");
    ui->comboBox->addItem("Преподаватели");

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_editDB_clicked()
{
    editor.show();
}

void MainWindow::on_pushButton_JoinCase_clicked()
{
    ui->tableView_MainWindow->setModel(connector->SetQuery("SELECT g.group_name AS \"Название группы\","
                                                            "g.amount_of_students AS \"Количество студентов\","
                                                            "g.specialization AS \"Специальность\","
                                                            "CASE WHEN g.specialization = 'Программист' "
                                                            "THEN (SELECT last_name AS \"Имя учителя\" "
                                                            "FROM \"Teachers\" t1 INNER JOIN \"Groups\" g2 "
                                                            "ON g2.id_group = t1.id_group WHERE "
                                                            "(faculty = 'Прикладные информационные технологии' "
                                                            "OR faculty = 'Интеллектуальные системы информационной безопасности' "
                                                            "OR faculty = 'Компьютерная и информационная безопасность' "
                                                            "OR faculty = 'Кафедра систем связи и телекоммуникаций') "
                                                            "AND g.id_group = t1.id_teacher ) WHEN g.specialization <> 'Программист' "
                                                            "THEN 'Эта группа не относится к программистам' "
                                                            "WHEN g.specialization IS NULL THEN 'Эта группа не закреплена за преподавателем' "
                                                            "END \"Преподватель для группы\" FROM \"Groups\" g"));
}

void MainWindow::on_pushButton_View_clicked()
{
    connector = new Connection("admin", "1234");
    ui->tableView_MainWindow->setModel(connector->SetQuery("select * from upd_view"));
}

void MainWindow::on_pushButton_Corel_clicked()
{
    ui->tableView_MainWindow->setModel(connector->SetQuery("SELECT t.last_name AS \"Фамилия\", t.first_name AS \"Имя\", "
                                                            "(SELECT group_name FROM \"Groups\" g WHERE g.id_group = t.id_group ) AS \"Название группы\" FROM (SELECT * FROM \"Teachers\") t, "
                                                            "\"Auditoriums\" a WHERE t.id_teacher in (SELECT id_group FROM \"Groups\" WHERE group_name != 'БСБО-03-19') AND (t.id_teacher = a.id_auditorium);"));
}

void MainWindow::on_pushButton_Group_clicked()
{
    ui->tableView_MainWindow->setModel(connector->SetQuery("SELECT s.pair_number AS \"Номер пары\","
                                                            " a.number_auditorium AS \"Номер аудитории\", "
                                                            "s.type_of_work AS \"Вид занятия\", "
                                                            "max(a.capacity) AS \"Вместимость\" FROM \"Auditoriums\" a, "
                                                            "\"Schedule\" s WHERE s.id_auditorium = a.number_auditorium "
                                                            "GROUP BY s.pair_number, a.number_auditorium, s.type_of_work, "
                                                            "a.capacity HAVING max(a.capacity) >= 30"));
}

void MainWindow::on_pushButton_Any_clicked()
{
    ui->tableView_MainWindow->setModel(connector->SetQuery("SELECT g.amount_of_students AS \"Количество студентов\", "
                                                            "g.group_name AS \"Название группы\", "
                                                            "g.specialization AS \"Специализация\" FROM \"Groups\" g "
                                                            "WHERE specialization = ANY (SELECT specialization "
                                                            "FROM \"Groups\" g1 WHERE g1.id_group<>g.id_group )"));
}

void MainWindow::on_pushButton_Delete_clicked()
{
    QMessageBox msgBox(QMessageBox::Information,
                   "Не правильный ввод",
                   "Поле нельзя оставлять пустым, введите число",QMessageBox::Ok);
    if(ui->lineEdit_id->text() == ""){
        msgBox.exec();
    } else{
        ui->tableView_MainWindow->setModel(connector->SetQuery(QString("call delete_rows(%1)").arg(ui->lineEdit_id->text())));
    }
}

void MainWindow::on_pushButton_Scalar_clicked()
{
    QMessageBox msgBox(QMessageBox::Information,
                   "Не правильный ввод",
                   "Поле нельзя оставлять пустым, введите имя преподавателя",QMessageBox::Ok);
    if(ui->lineEdit_name->text() == ""){
        msgBox.exec();
    } else{
        ui->tableView_MainWindow->setModel(connector->SetQuery(QString("select TeacherId('%1') as \"Номер преподавателя\"").arg(ui->lineEdit_name->text())));
    }
}

void MainWindow::on_pushButton_Vector_clicked()
{
    QMessageBox msgBox(QMessageBox::Information,
                   "Не правильный ввод",
                   "Поле нельзя оставлять пустым, введите специальность",QMessageBox::Ok);
    if(ui->lineEdit_vector->text() == ""){
        msgBox.exec();
    } else{
        ui->tableView_MainWindow->setModel(connector->SetQuery(QString("select GroupsName('%1') as \"Информация о группах и количестве студентов\"").arg(ui->lineEdit_vector->text())));
    }
}

void MainWindow::on_pushButton_checkDB_clicked()
{
    tables<<"Аудитории"<<"Группы"<<"Расписание"<<"Преподаватели";
    switch (tables.indexOf(ui->comboBox->currentText())) {
        case 0:{
            ui->tableView_MainWindow->setModel(connector->SetQuery("select capacity as \"Вместимость\", "
                                                                    "number_auditorium as \"Номер аудитории\", "
                                                                    "equipment_available as \"Наличие оборудования\" , "
                                                                    "name_of_auditorium as \"Название аудитории\" from \"Auditoriums\""));
            break;
        }
        case 1:{
            ui->tableView_MainWindow->setModel(connector->SetQuery("select amount_of_students as \"Количество студентов\", "
                                                                    "group_name as \"Название группы\", "
                                                                    "specialization as \"Специальность\" from \"Groups\""));
            break;
        }
        case 2:{
            ui->tableView_MainWindow->setModel(connector->SetQuery("select id_teacher as \"Номер преподавателя\", "
                                                                    "pair_number as \"Номер пары\", "
                                                                    "id_auditorium as \"Номер аудитории\", "
                                                                    "type_of_work as \"Вид занятия\", "
                                                                    "discipline as \"Дисциплина\" from \"Schedule\""));
            break;
        }
        case 3:{
            ui->tableView_MainWindow->setModel(connector->SetQuery("select last_name as \"Фамилия\", "
                                                                    "first_name as \"Имя\", "
                                                                    "middle_name as \"Отчество\", "
                                                                    "id_group as \"Номер группы\", "
                                                                    "faculty as \"Факультет\" from \"Teachers\""));
            break;
        }
    }
}
