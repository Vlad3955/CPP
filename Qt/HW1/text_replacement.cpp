#include "text_replacement.h"
#include "ui_text_replacement.h"

Text_Replacement::Text_Replacement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Text_Replacement)
{
    ui->setupUi(this);
}

Text_Replacement::~Text_Replacement()
{
    delete ui;
}

void Text_Replacement::on_b_add_clicked()
{
    QString txt = ui->pte_1->toPlainText();
    ui->pte_2->insertPlainText(txt);
}


void Text_Replacement::on_b_replace_clicked()
{
    QString txt = ui->pte_1->toPlainText();
    ui->pte_2->setPlainText(txt);
}


void Text_Replacement::on_b_insert_clicked()
{
    QString txt = "<font color='red'>Hello</font>";
    ui->pte_2->appendHtml(txt);
}

