#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "loginform.h"
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

private slots:
    void slotRegistration();
    void slotLogin(QString loginMode);
    void slotRegDelete();
    void slotRegistrationOK(bool regOK);
    void slotWarningDialogOpen(QString warning);


private:
    Ui::MainWindow *ui;
    RegistrationForm *reg;

    bool registered;
};

#endif // MAINWINDOW_H
