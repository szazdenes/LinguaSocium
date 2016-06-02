#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QTextStream>

#include "loginform.h"
#include "logindialog.h"
#include "registrationform.h"
#include "registrationdialog.h"
#include "warningdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void signalChangeForm();
    void signalSendRegDataMap(QMap<QString, QMap<QString, QString> > regdataMap);

private slots:
    void slotRegistration();
    void slotLogin(QString loginMode);
    void slotRegDelete();
    void slotRegistrationOK(bool regOK);
    void slotWarningDialogOpen(QString warning);
    void slotDeleteWarning();
    void slotDeleteLoginDialog();
    void slotChangeToLoginForm();
    void slotsaveRegData(QStringList regdata);

private:
    Ui::MainWindow *ui;
    RegistrationForm *reg;
    WarningDialog *warn;
    LoginDialog *login;
    bool registered;


    void loadRegData();
};

#endif // MAINWINDOW_H
