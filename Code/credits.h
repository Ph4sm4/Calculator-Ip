#ifndef CREDITS_H
#define CREDITS_H

#include <QDialog>

namespace Ui {
class Credits;
}

class Credits : public QDialog
{
    Q_OBJECT

public:
    explicit Credits(QWidget *parent = nullptr);
    ~Credits();

private slots:
    void on_pushButton_clicked();
    void display_credits();

private:
    Ui::Credits *ui;
};

#endif // CREDITS_H
