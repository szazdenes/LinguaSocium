/********************************************************************************
** Form generated from reading UI file 'lingua.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINGUA_H
#define UI_LINGUA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lingua
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QListWidget *listWidget;

    void setupUi(QMainWindow *Lingua)
    {
        if (Lingua->objectName().isEmpty())
            Lingua->setObjectName(QStringLiteral("Lingua"));
        Lingua->resize(800, 480);
        centralWidget = new QWidget(Lingua);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        Lingua->setCentralWidget(centralWidget);

        retranslateUi(Lingua);

        QMetaObject::connectSlotsByName(Lingua);
    } // setupUi

    void retranslateUi(QMainWindow *Lingua)
    {
        Lingua->setWindowTitle(QApplication::translate("Lingua", "Lingua", 0));
        pushButton->setText(QApplication::translate("Lingua", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class Lingua: public Ui_Lingua {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINGUA_H
