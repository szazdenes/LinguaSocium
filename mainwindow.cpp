#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->registrationWidget->hide();
    registered = false;

    connect(ui->loginWidget, &LoginForm::signalLogin, this, &MainWindow::slotLogin);
    connect(ui->loginWidget, &LoginForm::signalRegistration, this, &MainWindow::slotRegistration);
    connect(this, &MainWindow::signalChangeForm, ui->loginWidget, &LoginForm::hide);
    connect(ui->loginWidget, &LoginForm::signalRegistrationOk, this, &MainWindow::slotRegistrationOK);
    connect(ui->loginWidget, &LoginForm::signalWarning, this, &MainWindow::slotWarningDialogOpen);
    connect(ui->registrationWidget, &RegistrationForm::signalWarning, this, &MainWindow::slotWarningDialogOpen);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotRegistration()
{
    emit signalChangeForm();
    ui->registrationWidget->show();

}

void MainWindow::slotLogin(QString loginMode)
{
    qDebug() << loginMode;
}

void MainWindow::slotRegDelete()
{
    qDebug("alma");
}

void MainWindow::slotRegistrationOK(bool regOK)
{
    registered = regOK;
}

void MainWindow::slotWarningDialogOpen(QString warning)
{
        warn = new WarningDialog(this, warning);
        connect(warn, &WarningDialog::signalDeleteDialog, this, &MainWindow::slotDeleteWarning);
        warn->exec();
}

void MainWindow::slotDeleteWarning()
{
    delete warn;
}
