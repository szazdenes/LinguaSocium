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
    if(ui->nameLineEdit->text().isEmpty()){
        warn = new WarningDialog(this, "Empty name line");
        connect(warn, &WarningDialog::signalDeleteDialog, this, &RegistrationDialog::slotDeleteWarning);
        warn->exec();
    }
    if(ui->pwdLineEdit->text().isEmpty()){
        warn = new WarningDialog(this, "Empty password line");
        connect(warn, &WarningDialog::signalDeleteDialog, this, &RegistrationDialog::slotDeleteWarning);
        warn->exec();
    }
    if(ui->confPwdLineEdit->text().isEmpty())
    {
        warn = new WarningDialog(this, "Empty confirm password line");
        connect(warn, &WarningDialog::signalDeleteDialog, this, &RegistrationDialog::slotDeleteWarning);
        warn->exec();
    }
    if(ui->pwdLineEdit->text() != ui->confPwdLineEdit->text() && !ui->pwdLineEdit->text().isEmpty() && !ui->confPwdLineEdit->text().isEmpty()){
        warn = new WarningDialog(this, "Confirmed password different from password");
        connect(warn, &WarningDialog::signalDeleteDialog, this, &RegistrationDialog::slotDeleteWarning);
        warn->exec();
    }
    if(!ui->nameLineEdit->text().isEmpty() && !ui->pwdLineEdit->text().isEmpty() && !ui->confPwdLineEdit->text().isEmpty() && ui->pwdLineEdit->text() == ui->confPwdLineEdit->text()){
        regdata.append(ui->nameLineEdit->text());
        regdata.append(ui->pwdLineEdit->text());
        emit signalSendRegData(regdata);
        this->close();
        emit signalClose();
    }

}

void RegistrationDialog::slotDeleteWarning()
{
    delete warn;
}
