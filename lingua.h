#ifndef LINGUA_H
#define LINGUA_H

#include <QMainWindow>

namespace Ui {
class Lingua;
}

class Lingua : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lingua(QWidget *parent = 0);
    ~Lingua();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Lingua *ui;
};

#endif // LINGUA_H
