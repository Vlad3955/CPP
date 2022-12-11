#ifndef CHOISE_H
#define CHOISE_H

#include <QDialog>
#include "mainwindow.h"
#include "triangle.h"
#include "text_replacement.h"

namespace Ui {
class Choise;
}

class Choise : public QDialog
{
    Q_OBJECT

public:
    explicit Choise(QWidget *parent = nullptr);
    ~Choise();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Choise *ui;
    MainWindow w;
    Triangle t;
    Text_Replacement t_repl;
};

#endif // CHOISE_H
