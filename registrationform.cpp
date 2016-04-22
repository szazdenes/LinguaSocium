#include "registrationform.h"
#include "ui_registrationform.h"

RegistrationForm::RegistrationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistrationForm)
{
    ui->setupUi(this);
}

RegistrationForm::~RegistrationForm()
{
    delete ui;
}

void RegistrationForm::on_pushButton_clicked()
{
    reg = new RegistrationDialog(this, "Tutor");
    connect(reg, &RegistrationDialog::signalClose, this, &RegistrationForm::slotDeleteForm);
    connect(reg, &RegistrationDialog::signalSendRegData, this, &RegistrationForm::slotProcessRegistration);
    connect(reg, &RegistrationDialog::signalWarning, this, &RegistrationForm::slotSendWarning);
    reg->exec();
}

void RegistrationForm::on_pushButton_2_clicked()
{
    reg = new RegistrationDialog(this, "Student");
    connect(reg, &RegistrationDialog::signalClose, this, &RegistrationForm::slotDeleteForm);
    connect(reg, &RegistrationDialog::signalSendRegData, this, &RegistrationForm::slotProcessRegistration);
    connect(reg, &RegistrationDialog::signalWarning, this, &RegistrationForm::slotSendWarning);
    reg->exec();
}

void RegistrationForm::slotDeleteForm()
{
    delete reg;
}

void RegistrationForm::slotProcessRegistration(QStringList regData)
{
    QString randCode;
    randCode.resize(6);
    for (int s = 0; s < 6 ; ++s)
        randCode[s] = QChar('A' + char(qrand() % ('Z' - 'A')));
    qDebug() << randCode;
}

void RegistrationForm::slotSendWarning(QString warn)
{
    emit signalWarning(warn);
}

