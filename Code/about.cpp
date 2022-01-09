#include "about.h"
#include "ui_about.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDir>
#include <QString>
#include <QTextCodec>

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    ui->aboutDisplay->setStyleSheet("background-color: #FFFFFF; color: black;");
    ui->aboutDisplay->setReadOnly(true);
    file_content_show();
}

about::~about()
{
    delete ui;
}

void about::on_okAbout_clicked()
{
    this->hide();
}

void about::file_content_show(){
    QFile file("About.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    in.setCodec("UTF-8");
    QString text = in.readAll();
    ui->aboutDisplay->setPlainText(text);
    file.close();

}
