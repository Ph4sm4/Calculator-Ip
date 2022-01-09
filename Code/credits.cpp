#include "credits.h"
#include "ui_credits.h"
#include <QFile>
#include <QTextStream>
#include <QTextCodec>

Credits::Credits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credits)
{
    ui->setupUi(this);
    ui->creditsDisplay->setStyleSheet("background-color: #FFFFFF; color: black;");
    ui->creditsDisplay->setReadOnly(true);
    display_credits();
}

Credits::~Credits()
{
    delete ui;
}

void Credits::on_pushButton_clicked()
{
    this->hide();
}

void Credits::display_credits(){

    QFile file("credits.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    in.setCodec("UTF-8");
    QString text = in.readAll();

    ui->creditsDisplay->setPlainText(text);
    file.close();
}
