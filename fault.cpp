#include "fault.h"

fault::fault(QWidget *parent) : QWidget(parent)
{
 this->setWindowTitle("操作错误，请重新操作");
    a.setParent(this);
    a.setText("OK");
    a.setGeometry(150,75,100,50);
    connect(&a,&QPushButton::clicked,this,&fault::hide);
    this->resize(400,200);
}
