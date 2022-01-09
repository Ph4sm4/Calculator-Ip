/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QPushButton *okAbout;
    QPlainTextEdit *aboutDisplay;

    void setupUi(QDialog *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QString::fromUtf8("about"));
        about->resize(505, 471);
        okAbout = new QPushButton(about);
        okAbout->setObjectName(QString::fromUtf8("okAbout"));
        okAbout->setGeometry(QRect(360, 420, 81, 31));
        QFont font;
        font.setPointSize(11);
        okAbout->setFont(font);
        okAbout->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        aboutDisplay = new QPlainTextEdit(about);
        aboutDisplay->setObjectName(QString::fromUtf8("aboutDisplay"));
        aboutDisplay->setGeometry(QRect(60, 30, 381, 371));
        aboutDisplay->setFont(font);
        aboutDisplay->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QDialog *about)
    {
        about->setWindowTitle(QCoreApplication::translate("about", "Dialog", nullptr));
        okAbout->setText(QCoreApplication::translate("about", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
