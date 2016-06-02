#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0, QString loginMode = "");
    ~LoginDialog();

signals:
    void signalDeleteLogin();
    void signalSwitchToRegistration();

private slots:
    void on_loginPushButton_clicked();

    void on_registerPushButton_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
