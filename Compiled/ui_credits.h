/********************************************************************************
** Form generated from reading UI file 'credits.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITS_H
#define UI_CREDITS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Credits
{
public:
    QPlainTextEdit *creditsDisplay;
    QPushButton *pushButton;

    void setupUi(QDialog *Credits)
    {
        if (Credits->objectName().isEmpty())
            Credits->setObjectName(QString::fromUtf8("Credits"));
        Credits->resize(505, 471);
        creditsDisplay = new QPlainTextEdit(Credits);
        creditsDisplay->setObjectName(QString::fromUtf8("creditsDisplay"));
        creditsDisplay->setGeometry(QRect(60, 30, 381, 371));
        QFont font;
        font.setPointSize(11);
        creditsDisplay->setFont(font);
        creditsDisplay->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(Credits);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 420, 81, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #FFFFFF;\n"
"color: black;\n"
"border-width: 5px;\n"
"border-color: #FFFFFF;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: gray;\n"
"color: black;\n"
"border-width: 5px;\n"
"border-color: #FFFFFF;\n"
"\n"
"}"));

        retranslateUi(Credits);

        QMetaObject::connectSlotsByName(Credits);
    } // setupUi

    void retranslateUi(QDialog *Credits)
    {
        Credits->setWindowTitle(QCoreApplication::translate("Credits", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Credits", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Credits: public Ui_Credits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITS_H
