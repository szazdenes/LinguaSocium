#include "lingua.h"
#include "ui_lingua.h"

Lingua::Lingua(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Lingua)
{
    ui->setupUi(this);
}

Lingua::~Lingua()
{
    delete ui;
}

void Lingua::on_pushButton_clicked()
{
    ui->listWidget->addItem("Hello");
    ui->listWidget->scrollToBottom();
}
