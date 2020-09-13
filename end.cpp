#include "end.h"

END::END(QWidget *parent) : QWidget(parent)
{

       a.setParent(this);
       a.setText("OK");
       a.setGeometry(150,75,100,50);
       connect(&a,&QPushButton::clicked,
               [=](){
           this->close();
          sentsolt1();
       });

       this->resize(400,200);
}
void END::sentsolt1(){emit mysolt1();}
