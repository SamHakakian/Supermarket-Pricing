/********************************************************************************
** Form generated from reading UI file 'SupermarketPricing.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPERMARKETPRICING_H
#define UI_SUPERMARKETPRICING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SupermarketPricing
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SupermarketPricing)
    {
        if (SupermarketPricing->objectName().isEmpty())
            SupermarketPricing->setObjectName(QString::fromUtf8("SupermarketPricing"));
        SupermarketPricing->resize(800, 600);
        centralwidget = new QWidget(SupermarketPricing);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SupermarketPricing->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SupermarketPricing);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        SupermarketPricing->setMenuBar(menubar);
        statusbar = new QStatusBar(SupermarketPricing);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SupermarketPricing->setStatusBar(statusbar);

        retranslateUi(SupermarketPricing);

        QMetaObject::connectSlotsByName(SupermarketPricing);
    } // setupUi

    void retranslateUi(QMainWindow *SupermarketPricing)
    {
        SupermarketPricing->setWindowTitle(QCoreApplication::translate("SupermarketPricing", "SupermarketPricing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupermarketPricing: public Ui_SupermarketPricing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPERMARKETPRICING_H
