#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void changeMoney(int inputMoney);
    void checkMoney();
    void calculateMoney();
    int money {0};

private slots:
    void on_pb500_clicked();

    void on_pb100_clicked();

    void on_pb50_clicked();

    void on_pb10_clicked();

    void on_pbWater30_clicked();

    void on_pbCoffee60_clicked();

    void on_pbCoke150_clicked();



    void on_Reset_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
