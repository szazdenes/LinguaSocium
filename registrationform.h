#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QWidget>
#include <QDebug>

#include "registrationdialog.h"

namespace Ui {
class RegistrationForm;
}

class RegistrationForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationForm(QWidget *parent = 0);
    ~RegistrationForm();

signals:
    void signalWarning(QString warn);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void slotDeleteForm();
    void slotProcessRegistration(QStringList regData);
    void slotSendWarning(QString warn);

private:
    Ui::RegistrationForm *ui;
    RegistrationDialog *reg;
};

#endif // REGISTRATIONFORM_H
