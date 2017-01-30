#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class MyWindow;
}

class MyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MyWindow(QWidget *parent = 0);
    ~MyWindow();

private slots:
    void on_start_clicked();

private:
    Ui::MyWindow *ui;
};

#endif // MYWINDOW_H
