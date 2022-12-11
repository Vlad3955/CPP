#include "triangle.h"
#include "ui_triangle.h"

Triangle::Triangle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Triangle)
{
    ui->setupUi(this);
}

Triangle::~Triangle()
{
    delete ui;
}

void Triangle::on_pushButton_clicked()
{
    double b = ui ->side_1->text().toDouble();
    double c = ui ->side_2->text().toDouble();
    double ang = ui ->angle->text().toDouble();
    double tmp = ((qPow(b, 2) + qPow(c, 2)) + (-2 * b * c * qCos(ang)));
    double res = qSqrt(tmp);
    if (ui->degrees->isChecked())
    {
        QString answ = QString::number(qRadiansToDegrees(res));
        ui->answ->setText(answ);
    }
    else
    {
        QString answ = QString::number(res);
        ui->answ->setText(answ);
    }
}

