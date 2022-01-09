#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "about.h"
#include <QObject>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void get();
    void on_calculate_clicked();
    void split_ip();
    void split_mask();
    void ip_toBin();
    void mask_toBin();
    void net_address();
    void convert_net_address();
    bool is_numIp();
    bool ip_valid();
    bool mask_valid();
    bool is_numMask();
    void not_oper();
    void broadcast_address();
    void not_toDec();
    int host_num();
    void on_back_clicked();
    void first_host();
    void last_host();
    void on_settings_clicked();
    void setup_comboBox();
    void on_back_settings_clicked();
    void reset();
    void constructor_setup();
    void on_choose_mask_currentIndexChanged(int index);
    void on_save_clicked();
    void on_quitSettings_clicked();
    void quit_buttons();
    void on_quitShow_clicked();
    void on_quitMain_clicked();
    void on_about_clicked();
    void ischecked_input();
    void on_credits_clicked();
    void on_myip_clicked();
    bool is_checked_all();
    bool is_unchecked_all();
    void on_selectAll_clicked();
    void on_unselectAll_clicked();
    void on_clear_clicked();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent* event);
};
#endif // MAINWINDOW_H
