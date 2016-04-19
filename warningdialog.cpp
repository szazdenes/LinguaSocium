#include "warningdialog.h"
#include "ui_warningdialog.h"

WarningDialog::WarningDialog(QWidget *parent, QString warning) :
    QDialog(parent),
    ui(new Ui::WarningDialog)
{
    ui->setupUi(this);
    ui->label->setText(warning);
}

WarningDialog::~WarningDialog()
{
    delete ui;
}

void WarningDialog::on_pushButton_clicked()
{
    emit accepted();
    this->close();
}
