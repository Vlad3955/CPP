#ifndef TEXT_REPLACEMENT_H
#define TEXT_REPLACEMENT_H

#include <QDialog>

namespace Ui {
class Text_Replacement;
}

class Text_Replacement : public QDialog
{
    Q_OBJECT

public:
    explicit Text_Replacement(QWidget *parent = nullptr);
    ~Text_Replacement();

private slots:
    void on_b_add_clicked();

    void on_b_replace_clicked();

    void on_b_insert_clicked();

private:
    Ui::Text_Replacement *ui;
};

#endif // TEXT_REPLACEMENT_H
