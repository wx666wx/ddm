#ifndef WIDGET_H
#define WIDGET_H
#include <QPushButton>
#include <QWidget>
#include "sub.h"
#include "moshi.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void solo();
       QPushButton b1;
       QPushButton b2;
       sub h;
      moshi o;


};

#endif // WIDGET_H
