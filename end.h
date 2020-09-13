#ifndef END_H
#define END_H

#include <QWidget>
#include <QPushButton>

class END : public QWidget
{
    Q_OBJECT
public:
    explicit END(QWidget *parent = nullptr);
QPushButton a;
void sentsolt1();
signals:void mysolt1();

public slots:
};

#endif // END_H
