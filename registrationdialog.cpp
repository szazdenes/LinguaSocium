#include "registrationdialog.h"
#include "ui_registrationdialog.h"

RegistrationDialog::RegistrationDialog(QWidget *parent, QString mode) :
    QDialog(parent),
    ui(new Ui::RegistrationDialog)
{
    ui->setupUi(this);
    ui->modeLabel->setText(mode + " registration");
    regdata.clear();
    regdata.append(mode);
    ui->okPushButton->setFocus();
}

RegistrationDialog::~RegistrationDialog()
{
    delete ui;
}


void RegistrationDialog::on_calcelPushButton_clicked()
{
    this->close();
    emit signalClose();
}

void RegistrationDialog::on_okPushButton_clicked()
{
    if(ui->nameLineEdit->text().isEmpty())
        emit signalWarning("Empty name line");

    if(ui->pwdLineEdit->text().isEmpty())
        emit signalWarning("Empty password line");

    if(ui->confPwdLineEdit->text().isEmpty())
        emit signalWarning("Empty confirm password line");

    if(ui->pwdLineEdit->text() != ui->confPwdLineEdit->text() && !ui->pwdLineEdit->text().isEmpty() && !ui->confPwdLineEdit->text().isEmpty())
        emit signalWarning("Confirmed password different from password");

    if(!ui->nameLineEdit->text().isEmpty() && !ui->pwdLineEdit->text().isEmpty() && !ui->confPwdLineEdit->text().isEmpty() && ui->pwdLineEdit->text() == ui->confPwdLineEdit->text()){
        regdata.append(ui->nameLineEdit->text());
        regdata.append(ui->pwdLineEdit->text());
        emit signalSendRegData(regdata);
        this->close();
        emit signalSwitchToLoginForm();
        emit signalClose();
    }

}
