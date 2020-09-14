#ifndef MOSHI_H
#define MOSHI_H

#include <QWidget>
#include <QPushButton>
#include "sub.h"

class moshi : public QWidget
{
    Q_OBJECT
public:
    explicit moshi(QWidget *parent = nullptr);
    QPushButton q;
    QPushButton p;
    QPushButton m;
    sub h;
    void solt1();
    void solt2();
    void solt3();
signals:void mesolt1();
        void mesolt2();
        void mesolt3();

public slots:
};

#endif // MOSHI_H
