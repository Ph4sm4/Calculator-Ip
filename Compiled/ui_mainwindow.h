/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *calculate;
    QLineEdit *maskAddress;
    QLineEdit *ipAddress;
    QPlainTextEdit *welcome;
    QPushButton *settings;
    QComboBox *choose_mask;
    QPushButton *quitMain;
    QPushButton *about;
    QPushButton *credits;
    QPushButton *myip;
    QPushButton *clear;
    QWidget *page_2;
    QPlainTextEdit *showNet;
    QPlainTextEdit *showBroadcast;
    QPlainTextEdit *showHostNum;
    QPushButton *back;
    QPlainTextEdit *showFirstHost;
    QPlainTextEdit *showLastHost;
    QPushButton *quitShow;
    QWidget *page_3;
    QPlainTextEdit *info_settings;
    QPushButton *back_settings;
    QCheckBox *netBox;
    QCheckBox *broadcastBox;
    QCheckBox *numHostBox;
    QCheckBox *firstHostBox;
    QCheckBox *lastHostBox;
    QPushButton *save;
    QPushButton *quitSettings;
    QPushButton *selectAll;
    QPushButton *unselectAll;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(819, 593);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 3, 821, 1041));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        calculate = new QPushButton(page);
        calculate->setObjectName(QString::fromUtf8("calculate"));
        calculate->setGeometry(QRect(630, 450, 181, 81));
        QFont font;
        font.setPointSize(16);
        calculate->setFont(font);
        calculate->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        maskAddress = new QLineEdit(page);
        maskAddress->setObjectName(QString::fromUtf8("maskAddress"));
        maskAddress->setGeometry(QRect(10, 260, 661, 41));
        maskAddress->setFont(font);
        ipAddress = new QLineEdit(page);
        ipAddress->setObjectName(QString::fromUtf8("ipAddress"));
        ipAddress->setGeometry(QRect(10, 210, 661, 41));
        ipAddress->setFont(font);
        welcome = new QPlainTextEdit(page);
        welcome->setObjectName(QString::fromUtf8("welcome"));
        welcome->setGeometry(QRect(10, 110, 661, 51));
        welcome->setFont(font);
        welcome->setLayoutDirection(Qt::LeftToRight);
        settings = new QPushButton(page);
        settings->setObjectName(QString::fromUtf8("settings"));
        settings->setGeometry(QRect(20, 10, 181, 81));
        settings->setFont(font);
        settings->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        choose_mask = new QComboBox(page);
        choose_mask->setObjectName(QString::fromUtf8("choose_mask"));
        choose_mask->setGeometry(QRect(680, 260, 131, 41));
        quitMain = new QPushButton(page);
        quitMain->setObjectName(QString::fromUtf8("quitMain"));
        quitMain->setGeometry(QRect(210, 450, 411, 81));
        quitMain->setFont(font);
        quitMain->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        about = new QPushButton(page);
        about->setObjectName(QString::fromUtf8("about"));
        about->setGeometry(QRect(20, 450, 181, 81));
        about->setFont(font);
        about->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        credits = new QPushButton(page);
        credits->setObjectName(QString::fromUtf8("credits"));
        credits->setGeometry(QRect(210, 10, 411, 81));
        credits->setFont(font);
        credits->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        myip = new QPushButton(page);
        myip->setObjectName(QString::fromUtf8("myip"));
        myip->setGeometry(QRect(630, 10, 181, 81));
        myip->setFont(font);
        myip->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        clear = new QPushButton(page);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(680, 210, 131, 41));
        clear->setAutoFillBackground(false);
        clear->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid white; \n"
"color: white;\n"
" background-color: #202020;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: gray;\n"
"color: #FFFFFF;\n"
"border: 1px solid white;\n"
"}"));
        clear->setFlat(false);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        showNet = new QPlainTextEdit(page_2);
        showNet->setObjectName(QString::fromUtf8("showNet"));
        showNet->setGeometry(QRect(40, 40, 711, 51));
        showNet->setFont(font);
        showBroadcast = new QPlainTextEdit(page_2);
        showBroadcast->setObjectName(QString::fromUtf8("showBroadcast"));
        showBroadcast->setGeometry(QRect(40, 110, 711, 51));
        showBroadcast->setFont(font);
        showHostNum = new QPlainTextEdit(page_2);
        showHostNum->setObjectName(QString::fromUtf8("showHostNum"));
        showHostNum->setGeometry(QRect(40, 180, 711, 51));
        showHostNum->setFont(font);
        back = new QPushButton(page_2);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 450, 181, 81));
        back->setFont(font);
        back->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        showFirstHost = new QPlainTextEdit(page_2);
        showFirstHost->setObjectName(QString::fromUtf8("showFirstHost"));
        showFirstHost->setGeometry(QRect(40, 250, 711, 51));
        showFirstHost->setFont(font);
        showLastHost = new QPlainTextEdit(page_2);
        showLastHost->setObjectName(QString::fromUtf8("showLastHost"));
        showLastHost->setGeometry(QRect(40, 320, 711, 51));
        showLastHost->setFont(font);
        quitShow = new QPushButton(page_2);
        quitShow->setObjectName(QString::fromUtf8("quitShow"));
        quitShow->setGeometry(QRect(210, 450, 411, 81));
        quitShow->setFont(font);
        quitShow->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        info_settings = new QPlainTextEdit(page_3);
        info_settings->setObjectName(QString::fromUtf8("info_settings"));
        info_settings->setGeometry(QRect(50, 30, 491, 51));
        info_settings->setFont(font);
        back_settings = new QPushButton(page_3);
        back_settings->setObjectName(QString::fromUtf8("back_settings"));
        back_settings->setGeometry(QRect(20, 450, 181, 81));
        back_settings->setFont(font);
        back_settings->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        netBox = new QCheckBox(page_3);
        netBox->setObjectName(QString::fromUtf8("netBox"));
        netBox->setGeometry(QRect(50, 90, 351, 51));
        netBox->setFont(font);
        netBox->setLayoutDirection(Qt::LeftToRight);
        netBox->setAutoFillBackground(false);
        netBox->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"color: #FFFFFF;\n"
"border: 1px solid white;\n"
"}"));
        netBox->setIconSize(QSize(20, 20));
        broadcastBox = new QCheckBox(page_3);
        broadcastBox->setObjectName(QString::fromUtf8("broadcastBox"));
        broadcastBox->setGeometry(QRect(50, 150, 351, 51));
        broadcastBox->setFont(font);
        broadcastBox->setLayoutDirection(Qt::LeftToRight);
        broadcastBox->setAutoFillBackground(false);
        broadcastBox->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"color: #FFFFFF;\n"
"border: 1px solid white;\n"
"}"));
        broadcastBox->setIconSize(QSize(20, 20));
        numHostBox = new QCheckBox(page_3);
        numHostBox->setObjectName(QString::fromUtf8("numHostBox"));
        numHostBox->setGeometry(QRect(50, 210, 351, 51));
        numHostBox->setFont(font);
        numHostBox->setLayoutDirection(Qt::LeftToRight);
        numHostBox->setAutoFillBackground(false);
        numHostBox->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"color: #FFFFFF;\n"
"border: 1px solid white;\n"
"}"));
        numHostBox->setIconSize(QSize(20, 20));
        firstHostBox = new QCheckBox(page_3);
        firstHostBox->setObjectName(QString::fromUtf8("firstHostBox"));
        firstHostBox->setGeometry(QRect(50, 270, 351, 51));
        firstHostBox->setFont(font);
        firstHostBox->setLayoutDirection(Qt::LeftToRight);
        firstHostBox->setAutoFillBackground(false);
        firstHostBox->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"color: #FFFFFF;\n"
"border: 1px solid white;\n"
"}"));
        firstHostBox->setIconSize(QSize(20, 20));
        lastHostBox = new QCheckBox(page_3);
        lastHostBox->setObjectName(QString::fromUtf8("lastHostBox"));
        lastHostBox->setGeometry(QRect(50, 330, 351, 51));
        lastHostBox->setFont(font);
        lastHostBox->setLayoutDirection(Qt::LeftToRight);
        lastHostBox->setAutoFillBackground(false);
        lastHostBox->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"color: #FFFFFF;\n"
"border: 1px solid white;\n"
"}"));
        lastHostBox->setIconSize(QSize(20, 20));
        save = new QPushButton(page_3);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(630, 450, 181, 81));
        save->setFont(font);
        save->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        quitSettings = new QPushButton(page_3);
        quitSettings->setObjectName(QString::fromUtf8("quitSettings"));
        quitSettings->setGeometry(QRect(210, 450, 411, 81));
        quitSettings->setFont(font);
        quitSettings->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        selectAll = new QPushButton(page_3);
        selectAll->setObjectName(QString::fromUtf8("selectAll"));
        selectAll->setGeometry(QRect(630, 30, 181, 51));
        selectAll->setFont(font);
        selectAll->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        unselectAll = new QPushButton(page_3);
        unselectAll->setObjectName(QString::fromUtf8("unselectAll"));
        unselectAll->setGeometry(QRect(630, 100, 181, 51));
        unselectAll->setFont(font);
        unselectAll->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 819, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(ipAddress, maskAddress);
        QWidget::setTabOrder(maskAddress, calculate);
        QWidget::setTabOrder(calculate, welcome);
        QWidget::setTabOrder(welcome, settings);
        QWidget::setTabOrder(settings, choose_mask);
        QWidget::setTabOrder(choose_mask, showNet);
        QWidget::setTabOrder(showNet, showBroadcast);
        QWidget::setTabOrder(showBroadcast, showHostNum);
        QWidget::setTabOrder(showHostNum, back);
        QWidget::setTabOrder(back, showFirstHost);
        QWidget::setTabOrder(showFirstHost, showLastHost);
        QWidget::setTabOrder(showLastHost, info_settings);
        QWidget::setTabOrder(info_settings, back_settings);
        QWidget::setTabOrder(back_settings, netBox);
        QWidget::setTabOrder(netBox, broadcastBox);
        QWidget::setTabOrder(broadcastBox, numHostBox);
        QWidget::setTabOrder(numHostBox, firstHostBox);
        QWidget::setTabOrder(firstHostBox, lastHostBox);
        QWidget::setTabOrder(lastHostBox, save);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        calculate->setText(QCoreApplication::translate("MainWindow", "Show results", nullptr));
        welcome->setPlainText(QString());
        settings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        quitMain->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        about->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        credits->setText(QCoreApplication::translate("MainWindow", "About ~ Credits", nullptr));
        myip->setText(QCoreApplication::translate("MainWindow", "My ip", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        back->setText(QCoreApplication::translate("MainWindow", "<- Back", nullptr));
        quitShow->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        back_settings->setText(QCoreApplication::translate("MainWindow", "<- Back", nullptr));
        netBox->setText(QCoreApplication::translate("MainWindow", "Net address", nullptr));
        broadcastBox->setText(QCoreApplication::translate("MainWindow", "Broadcast address", nullptr));
        numHostBox->setText(QCoreApplication::translate("MainWindow", "Number of hosts", nullptr));
        firstHostBox->setText(QCoreApplication::translate("MainWindow", "First host", nullptr));
        lastHostBox->setText(QCoreApplication::translate("MainWindow", "Last host", nullptr));
        save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        quitSettings->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        selectAll->setText(QCoreApplication::translate("MainWindow", "Check All", nullptr));
        unselectAll->setText(QCoreApplication::translate("MainWindow", "Uncheck all", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
