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
    connect(ui->registrationWidget, &RegistrationForm::signalChangeToLoginForm, this, &MainWindow::slotChangeToLoginForm);
    connect(ui->registrationWidget, &RegistrationForm::signalSendRegDataWithCode, this, &MainWindow::slotsaveRegData);
    connect(this, &MainWindow::signalSendRegDataMap, ui->loginWidget, &LoginForm::slotGetRegDataMap);

    loadRegData();
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
    login = new LoginDialog(this, loginMode);
    connect(login, &LoginDialog::signalDeleteLogin, this, &MainWindow::slotDeleteLoginDialog);
    connect(login, &LoginDialog::signalSwitchToRegistration, this, &MainWindow::slotRegistration);
    login->exec();
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

void MainWindow::slotDeleteLoginDialog()
{
    delete login;
}

void MainWindow::slotChangeToLoginForm()
{
    ui->loginWidget->show();
}

void MainWindow::slotsaveRegData(QStringList regdata)
{
    QFile regFile("regfile.csv");
    if(regFile.exists("regfile.csv"))
        regFile.open(QIODevice::Append | QIODevice::Text);
    if(!regFile.exists("regfile.csv"))
        regFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream regstream(&regFile);
    foreach(QString currData, regdata){
        if(currData != regdata.last())
            regstream << currData + "\t";
        if(currData == regdata.last())
            regstream << currData + "\n";
    }
    regFile.close();
}

void MainWindow::loadRegData()
{
    QMap<QString, QMap<QString, QString> > regDataMap;
    QFile regfile("regfile.csv");
    QString mode, name, pwd, code;
    if(regfile.exists("regfile.csv")){
        regfile.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream stream(&regfile);
        while(!stream.atEnd()){
            QString line = stream.readLine();
            QTextStream linestream(&line);
            linestream >> mode >> name >> pwd >> code;
            regDataMap[code].insert("mode", mode);
            regDataMap[code].insert("name", name);
            regDataMap[code].insert("pwd", pwd);
        }
    }
    regfile.close();
    emit signalSendRegDataMap(regDataMap);
}
