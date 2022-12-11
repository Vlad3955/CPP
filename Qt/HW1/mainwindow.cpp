#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   int a = ui->line_a->text().toInt();
   int b = ui->line_b->text().toInt();
   int c = ui->line_c->text().toInt();
   int tmp = qPow(b, 2) + (-4 * a * c);
   int D = qSqrt(tmp);
   if (a != 0)
   {
       if (D < 0)
       {
           QString answ = "Нет корней";
           ui->line_answ->setText(answ);
       }
       else if (D == 0)
       {
           QString answ = QString::number(((-b) / (2 * a)));
           ui->line_answ->setText(answ);
       }
       else if (D > 0)
       {
            QString answ = QString::number((((-b) - D) / (2 * a)));
            QString answ1 = QString::number((((-b) + D) / (2 * a)));
            ui->line_answ->setText("x1=" + answ + "," + "x2=" + answ1);
       }
   }
   else
   {
       QString answ = QString::number(((-b) - D));
       ui->line_answ->setText(answ);
   }
}

