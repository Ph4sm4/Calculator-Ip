#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
class about;
}

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = nullptr);
    ~about();

private slots:
    void on_okAbout_clicked();
    void file_content_show();

private:
    Ui::about *ui;
};

#endif // ABOUT_H
