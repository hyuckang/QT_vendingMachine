#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    checkMoney();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbWater30_clicked()
{
    changeMoney(-30);
}

void Widget::on_pbCoffee60_clicked()
{
    changeMoney(-60);
}

void Widget::on_pbCoke150_clicked()
{
    changeMoney(-150);
}
void Widget::calculateMoney()
{
    int change = money;
    int coin500 = change/500;
    change = change%500;
    int coin100 = change/100;
    change = change%100;
    int coin50 = change/50;
    change = change%50;
    int coin10 = change/10;

    QMessageBox::information(this, "Change", QString("coin 500 : %1\n" "coin 100 : %2\n" "coin 50 : %3\n" "coin 10 : %4\n").arg(coin500).arg(coin100).arg(coin50).arg(coin10));
    changeMoney(-1 *money);
}
void Widget::on_Reset_clicked()
{
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "Get the change", "Want to return the change?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        calculateMoney();
    }
}

void Widget::changeMoney(int inputMoney)
{
    money += inputMoney;
    checkMoney();
    ui->lcdNumber->display(money);
}

void Widget::checkMoney()
{
    ui->pbWater30->setEnabled(false);
    ui->pbCoffee60->setEnabled(false);
    ui->pbCoke150->setEnabled(false);

    if(money>150) ui->pbCoke150->setEnabled(true);
    if(money>60) ui->pbCoffee60->setEnabled(true);
    if(money>30) ui->pbWater30->setEnabled(true);
}
