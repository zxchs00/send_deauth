#include "mywindow.h"
#include "ui_mywindow.h"

#include <tins/tins.h>

using namespace Tins;

MyWindow::MyWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Aireplay - LHS");
}

MyWindow::~MyWindow()
{
    delete ui;
}

void MyWindow::on_start_clicked()
{
    if(ui->bssid->text() == NULL){
        QMessageBox* a = new QMessageBox();
        a->setWindowTitle("Warning!");
        a->setText(QString("BSSID가 입력되지 않았습니다."));
        a->exec();
        return;
    }

}
