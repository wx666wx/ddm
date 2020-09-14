#include "moshi.h"


moshi::moshi(QWidget *parent) : QWidget(parent)
{this->resize(500,500);
    this->setWindowTitle("游戏模式选择");
q.setText("人人对战");
q.setGeometry(200,150,100,50);
q.setParent(this);
p.setText("人机对战");
p.setGeometry(200,250,100,50);
p.setParent(this);
connect(&q,&QPushButton::released,
        [=](){this->solt1();this->close();});
connect(&p,&QPushButton::released,
        [=](){this->solt2();this->close();});}

void moshi::solt1(){emit mesolt1();}
void moshi::solt2(){emit mesolt2();}

