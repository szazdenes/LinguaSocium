#ifndef REGISTRATIONDIALOG_H
#define REGISTRATIONDIALOG_H

#include <QDialog>

#include "warningdialog.h"

namespace Ui {
class RegistrationDialog;
}

class RegistrationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationDialog(QWidget *parent = 0, QString mode = "");
    ~RegistrationDialog();

signals:
    void signalRegistrationOk(bool regOK);
    void signalClose();
    void signalSendRegData(QStringList regData);
    void signalWarning(QString warning);

private slots:
    void on_calcelPushButton_clicked();
    void on_okPushButton_clicked();

private:
    Ui::RegistrationDialog *ui;
    QStringList regdata;
};

#endif // REGISTRATIONDIALOG_H
