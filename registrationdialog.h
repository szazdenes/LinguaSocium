#ifndef REGISTRATIONDIALOG_H
#define REGISTRATIONDIALOG_H

#include <QDialog>

namespace Ui {
class RegistrationDialog;
}

class RegistrationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationDialog(QWidget *parent = 0);
    ~RegistrationDialog();

signals:
    void signalRegistrationOk(bool regOK);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::RegistrationDialog *ui;
};

#endif // REGISTRATIONDIALOG_H
