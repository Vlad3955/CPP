#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QDialog>

namespace Ui {
class Triangle;
}

class Triangle : public QDialog
{
    Q_OBJECT

public:
    explicit Triangle(QWidget *parent = nullptr);
    ~Triangle();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Triangle *ui;
};

#endif // TRIANGLE_H
