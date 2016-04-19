#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_tutorPushButton_clicked()
{
    emit signalLogin("tutor");
    emit signalRegistrationOk(false);
    emit signalWarning("Registration required");
}

void LoginForm::on_studentPushButton_clicked()
{
    emit signalLogin("student");
    emit signalRegistrationOk(false);
    emit signalWarning("Registration required");
}

void LoginForm::on_registrationpushButton_clicked()
{
    emit signalRegistration();
}
