#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include "connection.h"
#include "auditoriums.h"
#include "groups.h"
#include "schedule.h"
#include "teachers.h"

namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = nullptr);
    ~Edit();

private slots:
    void on_pushButton_Auditoriums_clicked();

    void on_pushButton_Groups_clicked();

    void on_pushButton_Schedule_clicked();

    void on_pushButton_Teachers_clicked();

    void on_pushButton_TriggerList_clicked();

    void on_pushButton_openToEdit_clicked();

private:
    Ui::Edit *ui;
    Connection *con;
    QStringList tables;
    Auditoriums audi;
    Groups group;
    Schedule sche;
    Teachers teach;
};

#endif // EDIT_H
