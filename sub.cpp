#include "sub.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPen>
#include <QDebug>
#include <QPicture>
#include <QMessageBox>
#include <QPushButton>

sub::sub(QWidget *parent) : QWidget(parent) 
{this->resize(600,500);
    d.setText("和棋");
    d.setParent(this);
d.setGeometry(220,470,50,25);
connect(&d,&QPushButton::released,
        [=](){sendsolt();this->close();for(int i=0;i<21;i++)for(int j=0;j<21;j++){
        c[i][j]=0;}});

e.setText("悔棋");
e.setParent(this);
e.setGeometry(320,470,50,25);
    chessx=-1;chessy=-1;
 this->setWindowTitle("下棋");
    gridw=width()/22;
    gridh=height()/22;
    startw=gridw;
    starth=gridh;
for(int i=0;i<21;i++)for(int j=0;j<21;j++){
  c[i][j]=0;  }
connect(&e,&QPushButton::released,
                         [=](){c[chessx][chessy]=0;s=3-s;});
}

void sub::mousePressEvent(QMouseEvent *e ){
    int x=e->x();
    int y=e->y();
    int a,b;
    if(x>=startw&&x<=startw+20*gridw&&y>=starth&&y<=starth+20*gridh){
        a=(x-startw)%gridw;
        if(a>=gridw/2)chessx=(x-startw)/gridw+1;
        else chessx=(x-startw)/gridw;
        b=(y-starth)%gridh;
        if(b>=gridh/2)chessy=(y-starth)/gridh+1;
       else chessy=(y-starth)/gridh;
        if(c[chessx][chessy]!=0){j.show();}
        else{c[chessx][chessy]=s;}}
        s=3-s;
      update();
      if(m==2&&s==2){ai(c,chessx,chessy);s=3-s;update();}

}

void sub::paintEvent(QPaintEvent *){
    this->update();
    QPainter p(this);
   p.drawPixmap(rect(),QPixmap(":/new/prefix1/1.jpg"));
    QPen pen;
    pen.setWidth(2);
    p.setPen(pen);
    for(int i=0;i<=20;i++){
        p.drawLine(startw,starth+i*gridh,startw+20*gridw,starth+i*gridh);
       p.drawLine(startw+i*gridw,starth,startw+i*gridw,starth+20*gridh);}

    for(int g=0;g<21;g++){
        for(int k=0;k<21;k++){
            if(c[g][k]==1){ p.drawPixmap(startw+g*gridw-13,starth+k*gridh-13,26,26,
                                                           QPixmap(":/new/prefix1/4.png"));}
            if(c[g][k]==2){ p.drawPixmap(startw+g*gridw-13,starth+k*gridh-13,26,26,
                                         QPixmap(":/new/prefix1/5.png"));}  }
    }
  //判断是否结束
    if(s==2)if(four(c,chessx,chessy)){f.setWindowTitle("四四禁手，白子胜");f.show();
connect(&f,&END::mysolt1,
        [=](){for(int i=0;i<21;i++)for(int j=0;j<21;j++){
        c[i][j]=0;}this->close();sendsolt();});}

      if(s==2)if(five(c,chessx,chessy)){f.setWindowTitle("五五禁手，白子胜");f.show();
           connect(&f,&END::mysolt1,
                   [=](){for(int i=0;i<21;i++)for(int j=0;j<21;j++){
                   c[i][j]=0;}this->close();sendsolt();});}
//        if(chang(c)){ qDebug()<<1;f.setWindowTitle("长连禁手，白子胜");f.show();
//           connect(&f,&END::mysolt1,
//                  [=](){this->close();sendsolt();});}
         if(six(c)){
            if(m==1&&s==1||m==2&&s==2){for(int i=0;i<21;i++)for(int j=0;j<21;j++){
                    c[i][j]=0;}f.setWindowTitle("白子胜");f.show();
               connect(&f,&END::mysolt1,
                       [=](){this->close();sendsolt();});}
          if(m==1&&s==2||m==2&&s==1){for(int i=0;i<21;i++)for(int j=0;j<21;j++){
                  c[i][j]=0;}f.setWindowTitle("黑子胜");f.show();
              connect(&f,&END::mysolt1,
                      [=](){this->close();sendsolt();});}}
}
void sub::sendsolt(){emit mysignal();}
void sub::huiqi(){c[chessx][chessy]=0;}




