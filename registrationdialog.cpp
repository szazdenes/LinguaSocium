#include "registrationdialog.h"
#include "ui_registrationdialog.h"

RegistrationDialog::RegistrationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationDialog)
{
    ui->setupUi(this);
}

RegistrationDialog::~RegistrationDialog()
{
    delete ui;
}

void RegistrationDialog::on_buttonBox_accepted()
{
    emit signalRegistrationOk(true);
}

void RegistrationDialog::on_buttonBox_rejected()
{
    emit signalRegistrationOk(false);
}
