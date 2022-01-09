#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include <QDebug>
#include <QVector>
#include <QList>
#include <QChar>
#include <QMessageBox>
#include <algorithm>
#include <QtMath>
#include <QProcess>
#include <cstring>
#include <QFile>
#include <QDir>
#include <credits.h>
#include <cctype>
#include <QCloseEvent>
#include <QTcpServer>
#include <QTcpSocket>
#include <QKeyEvent>


//user's input
QString users_mask;
QString users_ip;
//handling errors
QString is_Valid_usersIp;
QString is_Valid_usersMask;

bool is_IpValid = false;
bool is_MaskValid = false;
//splitting ip and mask to parts between the dots
QVector<int> int_mask;
QList<QString> mask_bin;
QVector<int> int_ip;
QList<QString> ip_bin;
//getting the broadcast address
QVector<int> int_broadcast;
QList<QString> broadcast;
//getting number of possible hosts
QList<QString> mask_Host;
//first host
QList<QString> firstHost;
//last host
QList<QString> lastHost;
//settings setup
QVector<QString> ischecked;
QString ip_single_host;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #202020;");
    QMainWindow::setWindowTitle("Calculator Ip");
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/ip.ico"));
    constructor_setup();
    ischecked.reserve(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get(){

    users_ip = ui->ipAddress->text();
    is_Valid_usersIp = users_ip;
    ip_single_host = users_ip;
    users_mask = ui->maskAddress->text();
    is_Valid_usersMask = users_mask;
    //qDebug()<<users_ip;
}

void MainWindow::on_calculate_clicked()
{
    QMessageBox msg;
    msg.setStyleSheet("background-color: #FFFFFF; color: black;");
    msg.setIcon(QMessageBox::Warning);
    msg.setStandardButtons(QMessageBox::Ok);
    if(ui->ipAddress->text().isEmpty() && ui->maskAddress->text().isEmpty()){
        qDebug()<<"both empty";
        msg.setText("You didn't enter any ip address nor mask");
        msg.exec();
    }
    else if(ui->ipAddress->text().isEmpty()){
        qDebug()<<"ip empty";
        msg.setText("You didn't enter any ip address");
        msg.exec();
    }
    else if(ui->maskAddress->text().isEmpty()){
        qDebug()<<"mask empty";
        msg.setText("You didn't enter any mask address");
        msg.exec();
    }
    else{
    get();
    split_ip();
    split_mask();
    ip_valid();
    if(!ip_valid() || !is_numIp()){
        msg.setText("This is not a valid ip address");
        msg.exec();
        reset();
        //QApplication::quit();
        //QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
    else if(!mask_valid() || !is_numMask()){
        msg.setText("This is not a valid mask address");
        msg.exec();
        reset();
        //QApplication::quit();
        //QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
    else{
        QString showNet, showBroadcast;
        showNet = "Net address: ";

        ip_toBin();
        mask_toBin();
        net_address();
        convert_net_address();
        not_oper();
        not_toDec();
        broadcast_address();
        host_num();
        first_host();
        last_host();
        ui->stackedWidget->setCurrentIndex(1);
        ischecked_input();

        if(ischecked.at(0) == "true"){
            QString contentNet;
            if(mask_Host.at(0) == "11111111" && mask_Host.at(1) == "11111111"
                    && mask_Host.at(2) == "11111111"
                    && mask_Host.at(3) == "11111111"){

                ui->showNet->setPlainText("It is a single host, not a network: " + ip_single_host);
            }
            else{
                for(int i = 0; i < 4; i++){
                    if(i == 3){
                        contentNet = contentNet + ip_bin.at(i);
                    }
                    else{
                        contentNet = contentNet + ip_bin.at(i) + '.';
                    }

                }

                contentNet = showNet + contentNet;
                ui->showNet->setStyleSheet("border: 1px solid white; color: #FFFFFF");
                ui->showNet->setPlainText(contentNet);
            }

        }
        else{
            ui->showNet->hide();
        }

    ///---------------------------------------------------------------
        if(ischecked.at(1) == "true"){
            QString contentBroad;
            showBroadcast = "Broadcast address: ";
            if(mask_Host.at(0) == "11111111" && mask_Host.at(1) == "11111111"
                    && mask_Host.at(2) == "11111111"
                    && mask_Host.at(3) == "11111111"){

                ui->showBroadcast->setPlainText("---------");
            }
            else{
                for(int i = 0; i < 4; i++){
                    if(i == 3){
                        contentBroad = contentBroad + QString::number(int_broadcast.at(i));
                    }
                    else{
                        contentBroad = contentBroad + QString::number(int_broadcast.at(i)) + '.';
                    }
                }

                contentBroad = showBroadcast + contentBroad;
                ui->showBroadcast->setStyleSheet("border: 1px solid white; color: #FFFFFF;");
                ui->showBroadcast->setPlainText(contentBroad);
            }

        }
        else{
            ui->showBroadcast->hide();
        }

///----------------------------------------------------------------------------------------
    if(ischecked.at(2) == "true"){

        QString contentHost;
        contentHost = "Number of possible hosts: " + QString::number(host_num());
        //naprawic bo dla maski 0.0.0.0 jest za duzo hostow
        if(mask_Host.at(0) == "00000000" && mask_Host.at(1) == "00000000"
                && mask_Host.at(2) == "00000000"
                && mask_Host.at(3) == "00000000"){

            ui->showHostNum->setPlainText("Number of possible hosts: too much ;)");
        }
        else if(mask_Host.at(0) == "11111111" && mask_Host.at(1) == "11111111"
                && mask_Host.at(2) == "11111111"
                && mask_Host.at(3) == "11111111"){

            ui->showHostNum->setPlainText("---------");
        }
        else{
            ui->showHostNum->setPlainText(contentHost);
        }

    }
    else{
        ui->showHostNum->hide();
    }

///-----------------------------------------------------------------------------------------
    if(ischecked.at(3) == "true"){

        QString contentFirstHost;
        contentFirstHost = "First host address: ";
        for(int i = 0; i < 4; i++){
            if(i == 3){
                contentFirstHost = contentFirstHost + firstHost.at(i);
            }
            else{
                contentFirstHost = contentFirstHost + firstHost.at(i) + '.';
            }
        }
        if(mask_Host.at(0) == "00000000" && mask_Host.at(1) == "00000000"
                && mask_Host.at(2) == "00000000"
                && mask_Host.at(3) == "00000000"){
            ui->showFirstHost->setPlainText("---------");
        }
        else if(mask_Host.at(0) == "11111111" && mask_Host.at(1) == "11111111"
                && mask_Host.at(2) == "11111111"
                && mask_Host.at(3) == "11111111"){

            ui->showFirstHost->setPlainText("---------");
        }
        else if(mask_Host.at(0) == "11111111" && mask_Host.at(1) == "11111111"
                && mask_Host.at(2) == "11111111"
                && mask_Host.at(3) == "11111101"){
            ui->showFirstHost->setPlainText("---------");
        }
        else if(mask_Host.at(0) == "11111111" && mask_Host.at(1) == "11111111"
                && mask_Host.at(2) == "11111111"
                && mask_Host.at(3) == "11111110"){
            ui->showFirstHost->setPlainText("---------");
        }
        else{
            ui->showFirstHost->setPlainText(contentFirstHost);
        }

    }
    else{
        ui->showFirstHost->hide();
    }

///-----------------------------------------------------------------------------------------
    if(ischecked.at(4) == "true"){

        QString contentLastHost;
        contentLastHost = "Last host address: ";
        for(int i = 0; i < 4; i++){
            if(i == 3){
                contentLastHost = contentLastHost + lastHost.at(i);
            }
            else{
                contentLastHost = contentLastHost + lastHost.at(i) + '.';
            }
        }
        if(mask_Host.at(0) == "00000000" && mask_Host.at(1) == "00000000"
                && mask_Host.at(2) == "00000000"
                && mask_Host.at(3) == "00000000"){
            ui->showLastHost->setPlainText("---------");
        }
        else if(mask_Host.at(0) == "11111111" && mask_Host.at(1) == "11111111"
                && mask_Host.at(2) == "11111111"
                && mask_Host.at(3) == "11111111"){

            ui->showLastHost->setPlainText("---------");
        }
        else if(mask_Host.at(0) == "11111111" && mask_Host.at(1) == "11111111"
                && mask_Host.at(2) == "11111111"
                && mask_Host.at(3) == "11111101"){
            ui->showLastHost->setPlainText("---------");
        }
        else if(mask_Host.at(0) == "11111111" && mask_Host.at(1) == "11111111"
                && mask_Host.at(2) == "11111111"
                && mask_Host.at(3) == "11111110"){
            ui->showLastHost->setPlainText("---------");
        }
        else{
            ui->showLastHost->setPlainText(contentLastHost);
        }

    }
    else{
        ui->showLastHost->hide();
    }

        }
    }
}


void MainWindow::split_ip(){
    QString subIp;
    for(int i = 0; i < 4; i++){
        subIp = users_ip.left(users_ip.indexOf('.'));
        int_ip.append(subIp.toInt());
        users_ip.remove(0, users_ip.indexOf('.')+1);
        //qDebug()<<"sub ip: "<<subIp;
        qDebug()<<"vector ip: "<<int_ip.at(i);
    }
}

void MainWindow::split_mask(){
    QString subMask;
    for(int i = 0; i < 4; i++){
        subMask = users_mask.left(users_mask.indexOf('.'));
        int_mask.append(subMask.toInt());
        users_mask.remove(0, users_mask.indexOf('.')+1);
        //qDebug()<<"sub mask: "<<subMask;
        //qDebug()<<"vector mask: "<<int_mask.at(i);
    }

}

void MainWindow::ip_toBin(){
    int ip_Len[4];
    QString bin = "";
    for(int i = 0; i < 4; i++){
        while(int_ip.at(i)){
            bin = bin + QString::number(int_ip.at(i) % 2);
            int_ip[i] /= 2;
            //qDebug()<<"current bin ip: "<<bin;
        }
        std::reverse(bin.begin(), bin.end());
        ip_Len[i] = bin.length();
        if(ip_Len[i] < 8){
            for(int g = 0; g < 8 - ip_Len[i]; g++){
                bin = '0' + bin;
            }
        }
        ip_bin.append(bin);
        bin = "";

        qDebug()<<"binary ip: "<<ip_bin.at(i);
    }

}

void MainWindow::mask_toBin(){
    int ip_Len[4];
    QString bin = "";
    for(int i = 0; i < 4; i++){
        while(int_mask.at(i)){
            bin = bin + QString::number(int_mask.at(i) % 2);
            int_mask[i] /= 2;
            //qDebug()<<"current bin mask: "<<bin;
        }
        std::reverse(bin.begin(), bin.end());
        ip_Len[i] = bin.length();
        if(ip_Len[i] < 8){
            for(int g = 0; g < 8 - ip_Len[i]; g++){
                bin = '0' + bin;
            }
        }
        mask_bin.append(bin);
        broadcast.append(bin);
        mask_Host.append(bin);
        bin = "";

        qDebug()<<"binary mask: "<<mask_bin.at(i);

    }
}

void MainWindow::net_address(){

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            if(mask_bin.at(i)[j] == '0'){
                ip_bin[i][j] = '0';
            }
        }
        qDebug()<<ip_bin.at(i);
    }

}

void MainWindow::convert_net_address(){

    int n[4];
    int decimalNumber[4], i = 0, remainder;
    for(int a = 0; a < 4; a++){
        n[a] = ip_bin.at(a).toInt();
        decimalNumber[a] = 0;
    }
    for(int j = 0; j < 4; j++){
        while (n[j]!=0)
        {
            remainder = n[j]%10;
            n[j] /= 10;
            decimalNumber[j] += remainder*qPow(2,i);
            ++i;
        }
        i = 0;

        qDebug()<<"decimal number: "<<decimalNumber[j];
    }
    qDebug()<<"--------";
    ip_bin.clear();
    for(int z = 0; z < 4; z++){
        ip_bin.append(QString::number(decimalNumber[z]));
        qDebug()<<"content of a new vector: "<<ip_bin.at(z);
        firstHost.append(QString::number(decimalNumber[z]));
        qDebug()<<"content of first host: "<<firstHost.at(z);
    }
}

bool MainWindow::ip_valid(){
    int dotsIp = 0;
    for(int i = 0; i < is_Valid_usersIp.length(); i++){
        if(is_Valid_usersIp[i] == '.'){
            dotsIp++;
        }
    }
//errors that can occur in the ip address
    for(int i = 0; i < 4; i++){
        for(int j = 0; j <= is_Valid_usersIp.length(); j++){
        if(int_ip.at(i) > 255){
            is_IpValid = false;
            qDebug()<<"greater then 255";
            break;
        }
        else if(int_ip.at(i) < 0){
            is_IpValid = false;
            qDebug()<<"less then 0";
            break;
        }
        else if(QString::number(int_ip.at(i)).length() > 3){
            is_IpValid = false;
            qDebug()<<"too long";
            break;
        }
        else if(is_Valid_usersIp[0] == '.'){
            is_IpValid = false;
            qDebug()<<"dot ip first";
            break;
        }
        else if(dotsIp != 3){
            is_IpValid = false;
            qDebug()<<"dots error";
            break;
        }
        else if(is_Valid_usersIp[j] == '.' && is_Valid_usersIp[j+1] == '.'){
            is_IpValid = false;
            qDebug()<<"empty slot";
            break;
        }
        else if(const QString::iterator it = is_Valid_usersIp.end()-1; *it == '.'){
            is_IpValid = false;
            qDebug()<<"dot is last";
            break;
        }


        else{
            is_IpValid = true;
        }
    }
    if(!is_IpValid) break;

    }
    return is_IpValid;
}

bool MainWindow::is_numIp(){
    is_Valid_usersIp.remove('.');
    qDebug()<<is_Valid_usersIp;
    for(int i = 0; i < is_Valid_usersIp.length(); i++){
        const QChar s = is_Valid_usersIp[i];
        if(!s.isDigit()){
            is_IpValid = false;
            qDebug()<<"this is not a number";
            break;
        }
    }
    return is_IpValid;
}

bool MainWindow::mask_valid(){
//errors that can occur in the mask address
    int dotsMask = 0;
    for(int i = 0; i < is_Valid_usersMask.length(); i++){
        if(is_Valid_usersMask[i] == '.'){
            dotsMask++;
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < is_Valid_usersMask.length(); j++){
            if(int_mask.at(i) > 255){
               is_MaskValid = false;
               qDebug()<<"greater then 255";
               break;
            }
            else if(int_mask.at(i) < 0){
               is_MaskValid = false;
               qDebug()<<"less then 0";
                break;
            }
            else if(QString::number(int_mask.at(i)).length() > 3){
                is_MaskValid = false;
                qDebug()<<"too long";
                break;
          }
            else if(is_Valid_usersMask[0] == '.'){
                is_MaskValid = false;
                qDebug()<<"dot mask first";
                break;
            }
            else if(dotsMask != 3){
                is_MaskValid = false;
                qDebug()<<"dots error";
                break;
        }
            else if(is_Valid_usersMask[j] == '.' && is_Valid_usersMask[j+1] == '.'){
               is_MaskValid = false;
               qDebug()<<"empty slot";
                break;
         }
            else if(const QString::iterator it = is_Valid_usersMask.end()-1; *it == '.'){
                is_MaskValid = false;
                qDebug()<<"dot is last";
                break;
            }
        else{
            is_MaskValid = true;
            }
        }
        if(!is_MaskValid) break;
    }

    return is_MaskValid;
}

bool MainWindow::is_numMask(){

    is_Valid_usersMask.remove('.');
    qDebug()<<is_Valid_usersMask;
    for(int i = 0; i < is_Valid_usersMask.length(); i++){
        const QChar s = is_Valid_usersMask[i];
        if(!s.isDigit()){
            is_MaskValid = false;
            qDebug()<<"this is not a number";
            break;
        }
    }
    return is_MaskValid;
}

void MainWindow::not_oper(){
    qDebug()<<"--------------";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            if(mask_bin.at(i)[j] == '1'){
                //qDebug()<<"before 1: "<<mask_bin.at(i)[j];
                mask_bin[i][j] = '0';
                //qDebug()<<"after 1: "<<mask_bin.at(i)[j];
            }
            else if(mask_bin.at(i)[j] == '0'){
                //qDebug()<<"before 0: "<<mask_bin.at(i)[j];
                mask_bin[i][j] = '1';
                //qDebug()<<"after 0: "<<mask_bin.at(i)[j];
            }
        }
        qDebug()<<mask_bin.at(i);
    }

}

void MainWindow::not_toDec(){
    qDebug()<<"--------";
    int n[4];
    int decimalNumber[4], i = 0, remainder;
    for(int a = 0; a < 4; a++){
        n[a] = mask_bin.at(a).toInt();
        decimalNumber[a] = 0;
    }
    for(int j = 0; j < 4; j++){
        while (n[j]!=0)
        {
            remainder = n[j]%10;
            n[j] /= 10;
            decimalNumber[j] += remainder*qPow(2,i);
            ++i;
        }
        i = 0;

        qDebug()<<"not decimal number: "<<decimalNumber[j];
    }
    qDebug()<<"--------";
    broadcast.clear();
    for(int z = 0; z < 4; z++){
        broadcast.append(QString::number(decimalNumber[z]));
        qDebug()<<"content of a new vector (not): "<<broadcast.at(z);
    }
}

void MainWindow::broadcast_address(){
    for(int i = 0; i < 4; i++){
        int_broadcast.append(broadcast[i].toInt() + ip_bin[i].toInt());
        lastHost.append(QString::number(broadcast[i].toInt() + ip_bin[i].toInt()));
    }

}

int MainWindow::host_num(){
    unsigned long long int host_num;
    int oneNumber = 0, bitNum = 0;
    qDebug()<<"-------";
    for(int i = 0; i < 4; i++){
        qDebug()<<"mask host: "<<mask_Host.at(i);
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < mask_Host.at(i).length(); j++){
            if(mask_Host.at(i)[j] == '1'){
                oneNumber++;
            }
        }
        bitNum = bitNum + mask_Host.at(i).length();
    }
    qDebug()<<"number of 1: "<<oneNumber;
    qDebug()<<"bit number: "<<bitNum;

    host_num = pow(2, bitNum - oneNumber) - 2;
    qDebug()<<"host number: "<<host_num;
    if(host_num < 0){
        return 0;
    }
    else{
      return host_num;
    }

}

void MainWindow::on_back_clicked()
{
    reset();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::first_host(){

    qDebug()<<"------------";
    if(!firstHost.isEmpty()){
        firstHost.back() = QString::number(firstHost.back().toInt() + 1);
        qDebug()<<"first host: "<<firstHost.back();
    }
}

void MainWindow::last_host(){
    qDebug()<<"-------------";
    if(!lastHost.isEmpty()){
        lastHost.back() = QString::number(lastHost.back().toInt() - 1);
        for(int i = 0; i < 4; i++){
            qDebug()<<"last host: "<<lastHost.at(i);
        }
    }

}


void MainWindow::on_settings_clicked()
{
   ischecked_input();
   if(ischecked.at(0) == "true"){
       ui->netBox->setChecked(true);
   }
   if(ischecked.at(1) == "true"){
       ui->broadcastBox->setChecked(true);
   }
   if(ischecked.at(2) == "true"){
       ui->numHostBox->setChecked(true);
   }
   if(ischecked.at(3) == "true"){
       ui->firstHostBox->setChecked(true);
   }
   if(ischecked.at(4) == "true"){
       ui->lastHostBox->setChecked(true);
   }
    is_checked_all();
    is_unchecked_all();

   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_back_settings_clicked()
{
    reset();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::setup_comboBox(){
    ui->choose_mask->insertItem(0, "Proposed masks");
    ui->choose_mask->addItem("0.0.0.0");
    ui->choose_mask->addItem("128.0.0.0");
    ui->choose_mask->addItem("192.0.0.0");
    ui->choose_mask->addItem("224.0.0.0");
    ui->choose_mask->addItem("240.0.0.0");
    ui->choose_mask->addItem("248.0.0.0");
    ui->choose_mask->addItem("252.0.0.0");
    ui->choose_mask->addItem("254.0.0.0");
    ui->choose_mask->addItem("255.0.0.0");
    ui->choose_mask->addItem("255.128.0.0");
    ui->choose_mask->addItem("255.192.0.0");
    ui->choose_mask->addItem("255.224.0.0");
    ui->choose_mask->addItem("255.240.0.0");
    ui->choose_mask->addItem("255.248.0.0");
    ui->choose_mask->addItem("255.252.0.0");
    ui->choose_mask->addItem("255.254.0.0");
    ui->choose_mask->addItem("255.255.0.0");
    ui->choose_mask->addItem("255.255.128.0");
    ui->choose_mask->addItem("255.255.192.0");
    ui->choose_mask->addItem("255.255.224.0");
    ui->choose_mask->addItem("255.255.240.0");
    ui->choose_mask->addItem("255.255.248.0");
    ui->choose_mask->addItem("255.255.252.0");
    ui->choose_mask->addItem("255.255.254.0");
    ui->choose_mask->addItem("255.255.255.0");
    ui->choose_mask->addItem("255.255.255.128");
    ui->choose_mask->addItem("255.255.255.192");
    ui->choose_mask->addItem("255.255.255.224");
    ui->choose_mask->addItem("255.255.255.240");
    ui->choose_mask->addItem("255.255.255.248");
    ui->choose_mask->addItem("255.255.255.252");
    ui->choose_mask->addItem("255.255.255.255");
}

void MainWindow::on_choose_mask_currentIndexChanged(int index)
{
    if(ui->choose_mask->currentIndex() != 0){
        ui->maskAddress->setText(ui->choose_mask->currentText());
    }
}

void MainWindow::reset(){
    users_ip = "";
    users_mask = "";
    is_Valid_usersIp = "";
    is_Valid_usersMask = "";
    is_MaskValid = false;
    is_IpValid = false;
    int_mask.clear();
    mask_bin.clear();
    int_ip.clear();
    ip_bin.clear();
    int_broadcast.clear();
    broadcast.clear();
    mask_Host.clear();
    firstHost.clear();
    lastHost.clear();
    ischecked.clear();

    ui->showNet->show();
    ui->showBroadcast->show();
    ui->showHostNum->show();
    ui->showFirstHost->show();
    ui->showLastHost->show();
}

void MainWindow::constructor_setup(){
    ui->ipAddress->setStyleSheet("border: 1px solid white; color: #A0A0A0;");
    ui->ipAddress->setPlaceholderText("Ip address");
    ui->maskAddress->setPlaceholderText("Mask address");
    ui->maskAddress->setStyleSheet("border: 1px solid white; color: #A0A0A0;");
    ui->welcome->setPlainText("Welcome to the ip address calculator!");
    ui->welcome->setStyleSheet("border: 1px #484848; color: #FFFFFF;");
    ui->welcome->setEnabled(false);
    ui->showNet->setEnabled(false);
    ui->showNet->setStyleSheet("border: 1px solid white; color: #FFFFFF;");
    ui->stackedWidget->setCurrentIndex(0);
    ui->showBroadcast->setEnabled(false);
    ui->showBroadcast->setStyleSheet("border: 1px solid white; color: #FFFFFF;");
    ui->showHostNum->setEnabled(false);
    ui->showHostNum->setStyleSheet("border: 1px solid white; color: #FFFFFF;");
    ui->showFirstHost->setEnabled(false);
    ui->showFirstHost->setStyleSheet("border: 1px solid white; color: #FFFFFF;");
    ui->showLastHost->setEnabled(false);
    ui->showLastHost->setStyleSheet("border: 1px solid white; color: #FFFFFF;");
    ui->info_settings->setEnabled(false);
    ui->info_settings->setStyleSheet("border: 1px solid white; color: #FFFFFF;");
    ui->choose_mask->setStyleSheet("color: #FFFFFF; border: 1px solid white;");
    setup_comboBox();
    ui->info_settings->setStyleSheet("color: #FFFFFF; border: 1px #202020;");
    ui->info_settings->setPlainText("Choose what you want to be displayed");
    ui->info_settings->setEnabled(false);
    ui->netBox->setStyleSheet("border: 1px #202020; color: #FFFFFF;");
    ui->broadcastBox->setStyleSheet("border: 1px #202020; color: #FFFFFF;");
    ui->numHostBox->setStyleSheet("border: 1px #202020; color: #FFFFFF;");
    ui->firstHostBox->setStyleSheet("border: 1px #202020; color: #FFFFFF;");
    ui->lastHostBox->setStyleSheet("border: 1px #202020; color: #FFFFFF;");
}

void MainWindow::on_save_clicked()
{
        QDir::setCurrent(QCoreApplication::applicationDirPath());
        QString filename = "settings.txt";
        QFile file(filename);
        if(!file.exists()){
            QMessageBox msg;
            msg.setIcon(QMessageBox::Critical);
            msg.setWindowTitle("Error");
            msg.setText("Unable to save the settings");
            qDebug()<<"doesnt exist";
            msg.exec();
        }
        else{
            file.open(QIODevice::WriteOnly | QIODevice::Truncate);
            QTextStream out(&file);
            for(int i = 0; i < 5; i++){
                switch (i) {
                    case 0:
                        if(ui->netBox->isChecked()) out<<"true"<<'\n';
                        else out<<"false"<<'\n';
                        break;
                    case 1:
                        if(ui->broadcastBox->isChecked()) out<<"true"<<'\n';
                        else out<<"false"<<'\n';
                        break;
                    case 2:
                        if(ui->numHostBox->isChecked()) out<<"true"<<'\n';
                        else out<<"false"<<'\n';
                        break;
                    case 3:
                        if(ui->firstHostBox->isChecked()) out<<"true"<<'\n';
                        else out<<"false"<<'\n';
                        break;
                    case 4:
                        if(ui->lastHostBox->isChecked()) out<<"true";
                        else out<<"false";
                        break;
                }
            }

            file.close();

            QMessageBox save_msg;
            save_msg.setIcon(QMessageBox::Information);
            save_msg.setText("The changes were saved successfully");
            save_msg.setWindowTitle("Success");
            save_msg.setStandardButtons(QMessageBox::Ok);
            save_msg.exec();
        }

}

void MainWindow::on_quitSettings_clicked()
{
    quit_buttons();
}

void MainWindow::quit_buttons(){
    QMessageBox quit_msg;
    quit_msg.setIcon(QMessageBox::Question);
    quit_msg.setText("Are you sure you want to exit?");
    quit_msg.setWindowTitle("Are you sure");
    quit_msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    if(quit_msg.exec() == QMessageBox::Yes){
        QApplication::quit();
    }
}

void MainWindow::on_quitShow_clicked()
{
    quit_buttons();
}

void MainWindow::on_quitMain_clicked()
{
    quit_buttons();
}


void MainWindow::on_about_clicked()
{
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    QString filename = "About.txt";
    QFile file(filename);
    if(!file.exists()){
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setWindowTitle("Error");
        msg.setText("File " + filename + " was not found");
        msg.exec();
    }
    else if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setWindowTitle("Error");
        msg.setText("Unable to open " + filename);
        msg.exec();
    }
    else{
        file.close();
        about about;
        about.setWindowTitle("About calculator");
        about.setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
        about.setStyleSheet("background-color: #202020;");
        about.exec();
    }

}

void MainWindow::ischecked_input(){
    QDir::setCurrent(QCoreApplication::applicationDirPath());

    QFile inputFile("settings.txt");
    if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text)){
       QTextStream in(&inputFile);
       while (!in.atEnd()){
          QString line = in.readLine();
          ischecked.append(line);
       }
       inputFile.close();
    }
}



void MainWindow::on_credits_clicked()
{
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    QString filename = "credits.txt";
    QFile file(filename);
    if(!file.exists()){
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setWindowTitle("Error");
        msg.setText("File " + filename + " was not found");
        msg.exec();
    }
    else if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setWindowTitle("Error");
        msg.setText("Unable to open " + filename);
        msg.exec();
    }
    else{
        file.close();
        Credits credits;
        credits.setWindowTitle("~Credits~");
        credits.setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
        credits.setStyleSheet("background-color: #202020;");
        credits.exec();
    }
}

void MainWindow::on_myip_clicked()
{
    QTcpSocket socket;
    socket.connectToHost("8.8.8.8", 53);
    if (socket.waitForConnected()) {
        QString text = socket.localAddress().toString();
        ui->ipAddress->setText(text);

    } else {
        QMessageBox msg;
        msg.setText("Couldn't connect to the DNS server! No internet connection...");
        msg.setWindowTitle("No internet connection");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }

}

void MainWindow::on_selectAll_clicked()
{
    //check_all();
    if(is_checked_all()){
        QMessageBox msg;
        msg.setText("Every checkbox is checked!");
        msg.setWindowTitle("Error");
        msg.setIcon(QMessageBox::Information);
        msg.exec();
    }
    else{
        ui->netBox->setChecked(true);
        ui->broadcastBox->setChecked(true);
        ui->numHostBox->setChecked(true);
        ui->firstHostBox->setChecked(true);
        ui->lastHostBox->setChecked(true);
    }
}

bool MainWindow::is_checked_all(){
    if(ui->netBox->isChecked() == true && ui->broadcastBox->isChecked() == true
        && ui->numHostBox->isChecked() == true && ui->firstHostBox->isChecked() == true
        && ui->lastHostBox->isChecked() == true){
            qDebug()<<"all checked";
            return true;
    }
    else return false;

}


bool MainWindow::is_unchecked_all(){
    if(ui->netBox->isChecked() == false && ui->broadcastBox->isChecked() == false
        && ui->numHostBox->isChecked() == false && ui->firstHostBox->isChecked() == false
        && ui->lastHostBox->isChecked() == false){
            qDebug()<<"all empty";
            return true;
    }
    else return false;
}

void MainWindow::on_unselectAll_clicked()
{
    //check_all();
    if(is_unchecked_all()){
        QMessageBox msg;
        msg.setText("Every checkbox is empty!");
        msg.setWindowTitle("Error");
        msg.setIcon(QMessageBox::Information);
        msg.exec();
    }
    else{
        ui->netBox->setChecked(false);
        ui->broadcastBox->setChecked(false);
        ui->numHostBox->setChecked(false);
        ui->firstHostBox->setChecked(false);
        ui->lastHostBox->setChecked(false);
    }

}

void MainWindow::on_clear_clicked()
{
    if(ui->ipAddress->text().isEmpty() && ui->maskAddress->text().isEmpty()){
        qDebug()<<"both empty";
        QMessageBox msg;
        msg.setStyleSheet("background-color: #FFFFFF; color: black;");
        msg.setIcon(QMessageBox::Warning);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setText("Labels are already empty");
        msg.exec();
    }
    else{
        ui->ipAddress->setText("");
        ui->maskAddress->setText("");
        ui->choose_mask->setCurrentIndex(0);
    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
        if(event->type() == QEvent::KeyPress){
           if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
               if(ui->stackedWidget->currentIndex() == 0){
                   on_calculate_clicked();
               }
               else if(ui->stackedWidget->currentIndex() == 2){
                    on_save_clicked();
               }
               qDebug()<<"enter pressed";
           }
           if(event->key() == Qt::Key_Escape){
               quit_buttons();
               qDebug()<<"esc pressed";
           }
        }
}
