#include "widget.h"
#include <QWidget>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{setWindowTitle("六子旗");
    this->resize(500,500);


    b1.setText("开始游戏");
    b1.setParent(this);
    b1.setGeometry(200,100,100,50);
    b2.setText("退出游戏");
    b2.setParent(this);
    b2.setGeometry(200,300,100,50);
    connect(&b1,&QPushButton::released,this,&Widget::solo);
    connect(&b2,&QPushButton::released,this,&Widget::close);
    connect(&h,&sub::mysignal,
            [=](){  this->show();});
    connect(&o,&moshi::mesolt1,
            [=](){h.m=1;h.s=1;h.show();});
    connect(&o,&moshi::mesolt2,
            [=](){h.m=2;h.s=1;h.show();});


}
void Widget::solo(){
    this->hide();
            o.show();
}
Widget::~Widget()
    {

 }
