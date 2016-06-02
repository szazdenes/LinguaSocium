#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    regDataMap.clear();
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::slotGetRegDataMap(QMap<QString, QMap<QString, QString> > regdataMap)
{
    regDataMap = regdataMap;
}

void LoginForm::on_tutorPushButton_clicked()
{
    if(regDataMap.isEmpty()){
        emit signalRegistrationOk(false);
        emit signalWarning("Registration required");
    }
    else
        emit signalLogin("tutor");
}

void LoginForm::on_studentPushButton_clicked()
{
    if(regDataMap.isEmpty()){
        emit signalRegistrationOk(false);
        emit signalWarning("Registration required");
    }
    else
        emit signalLogin("student");
}

void LoginForm::on_registrationpushButton_clicked()
{
    emit signalRegistration();
}
