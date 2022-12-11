#include "choise.h"
#include "ui_choise.h"



Choise::Choise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Choise)
{
    ui->setupUi(this);
}

Choise::~Choise()
{
    delete ui;
}

void Choise::on_pushButton_clicked()
{
    if (ui->rb_task_1->isChecked())
    {
        w.show();
    }
    else if (ui->rb_task_2->isChecked())
    {
        t.show();
    }
    else
    {
        t_repl.show();
    }
}

