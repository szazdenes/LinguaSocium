#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QMap>

#include "logindialog.h"

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = 0);
    ~LoginForm();

signals:
    void signalRegistration();
    void signalLogin(QString loginMode);
    void signalRegistrationOk(bool regOK);
    void signalWarning(QString warning);

public slots:
    void slotGetRegDataMap(QMap<QString, QMap<QString, QString> > regdataMap);

private slots:
    void on_tutorPushButton_clicked();
    void on_studentPushButton_clicked();
    void on_registrationpushButton_clicked();

private:
    Ui::LoginForm *ui;
    QMap<QString, QMap<QString, QString> > regDataMap;
};

#endif // LOGINFORM_H
