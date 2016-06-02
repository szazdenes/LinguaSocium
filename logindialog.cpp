#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent, QString loginMode) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->titleLabel->setText("Log in as " + loginMode);
    ui->loginPushButton->setFocus();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginPushButton_clicked()
{
    this->close();
    emit signalDeleteLogin();
}

void LoginDialog::on_registerPushButton_clicked()
{
    this->close();
    emit signalSwitchToRegistration();
}
