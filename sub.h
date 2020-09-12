#ifndef SUB_H
#define SUB_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPen>
#include <QDebug>
#include <QPicture>
#include "fault.h"
#include <QString>
#include "end.h"
#include <QPushButton>
#include <time.h>
class sub : public QWidget
{
    Q_OBJECT
private:
    int gridw;//每个横长
    int gridh;//每个竖长
    int startw;
    int starth;
    int chessx,chessy;
    int c[21][21];
    int dx[8]={1,1,1,0,-1,-1,-1,0};
    int dy[8]={1,0,-1,1,-1,0,1,-1};
    QPushButton d;
    QPushButton e;

public:
    explicit sub(QWidget *parent = nullptr);
     int s=1;
     int m;
     int t,r;
     fault j;
     END f;
protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*e);
    void sendsolt();
    void huiqi();

    bool inboard(int x,int y){
        if(x<0||x>=21||y<0||y>=21)return false;
        return true;
    }
//    bool chang(int (&a)[21][21]){// 长连禁手

//    int sum=1;
//        for(int i=0;i<21;i++){
//            for(int j=0;j<21;j++){
//                for(int k=0;k<4;k++){int q=i,p=j;
//                while(q+dx[k]>=0&&q+dx[k]<20&&p+dy[k]>=0&&p+dy[k]<20&&a[q+dx[k]][p+dy[k]]==a[q][p]&&a[q][p]!=0)
//                {sum++;q+=dx[k];p+=dy[k];}
//                sum=1;if(sum==7)break;}if(sum==7)break;}
//        if(sum==7)break;}
//        if(sum==7)return true;
//        return false;
//    }

    bool six(int (&a)[21][21]){//判断是否六子
        int sum=1;
        for(int i=0;i<21;i++){
            for(int j=0;j<21;j++){
                for(int k=0;k<4;k++){int q=i,p=j;
                while(q+dx[k]>=0&&q+dx[k]<21&&p+dy[k]>=0&&p+dy[k]<21&&a[q+dx[k]][p+dy[k]]==a[q][p]&&a[q][p]!=0)
                {sum++;q+=dx[k];p+=dy[k];}
                if(sum==6)break;sum=1;}if(sum==6)break;}
        if(sum==6)break;}
        if(sum==6)return true;
        return false;
    }
    bool four(int (&a)[21][21],int q,int p){//判断是否四四禁手 活四数量等于2
        QString n="0011110",h="0110110",l="0101110";int sum=0;
        for(int m=0;m<4;m++){
            for(int i=-5;i<=-1;i++){QString b;
                for(int j=i;j<=i+6;j++){
                    if(!inboard(q+dx[m]*j,p+dy[m]*j)||a[q+dx[m]*j][p+dy[m]*j]==2){b+='Y';continue;}//不在期盘；
                    if(a[q+dx[m]*j][p+dy[m]*j]==1)b+='1';
                    if(a[q+dx[m]*j][p+dy[m]*j]==0)b+='0';
                }QString k;int v=b.size();
                for(int s=v-1;s>=0;s--){
                    k+=b[s];
                }
                if(b==n||b==h||b==l||k==n||k==h||k==l){sum++;break;}
            }}
            if(sum>=2)return true;
            return false;

     }
    bool five(int (&a)[21][21],int q,int p){//判断是否五五禁手
          QString n="111110";QString h="111101";QString l="111011";int sum=0;
          for(int m=0;m<4;m++){
            for(int i=-5;i<=0;i++){QString b;
                for(int j=i;j<i+6;j++){if(!inboard(q+dx[m]*j,p+dy[m]*j)||a[q+dx[m]*j][p+dy[m]*j]==2){b+='Y';continue;}//不在期盘；
                    if(a[q+dx[m]*j][p+dy[m]*j]==1)b+='1';
                    if(a[q+dx[m]*j][p+dy[m]*j]==0)b+='0';
                  }QString k;int v=b.size();
                for(int s=v-1;s>=0;s--){
                    k+=b[s];
                }
                if(b==n||b==h||b==l||k==n||k==h||k==l){sum++;break;}
            }}
            if(sum>=2)return true;
            return false;
    }
    void ai(int (&a)[21][21],int q,int p){
        srand((unsigned int)time(NULL));
        QString n="0011110",h="0110110",l="0101110";int sum=0;
        for(int m=0;m<4;m++){
            for(int i=-5;i<=-1;i++){QString b;int j=i;
                for(;j<=i+6;j++){
                    if(!inboard(q+dx[m]*j,p+dy[m]*j)||a[q+dx[m]*j][p+dy[m]*j]==2){b+='Y';continue;}//不在期盘；
                    if(a[q+dx[m]*j][p+dy[m]*j]==1)b+='1';
                    if(a[q+dx[m]*j][p+dy[m]*j]==0)b+='0';
                }QString k;int v=b.size();
                for(int s=v-1;s>=0;s--){
                    k+=b[s];
                }
               if(b==n){a[q+dx[m]*(j-1)][p+dy[m]*(j-1)]=2;sum=1;break;}
               if(k==n){a[q+dx[m]*(j)][p+dy[m]*(j)]=2;sum=1;break;}
               if(b==h||k==h){a[q+dx[m]*(j-4)][p+dy[m]*(j-4)]=2;sum=1;break;}
               if(b==l){a[q+dx[m]*(j-5)][p+dy[m]*(j-5)]=2;sum=1;break;}
               if(k==l){a[q+dx[m]*(j-3)][p+dy[m]*(j-3)]=2;sum=1;break;}
            }if(sum)break;}
        if(sum==0){
        QString n1="111110";QString h1="111101";QString l1="111011";int sum1=0;
        for(int m=0;m<4;m++){
          for(int i=-5;i<=0;i++){QString b;int j=i;
              for(;j<i+6;j++){if(!inboard(q+dx[m]*j,p+dy[m]*j)||a[q+dx[m]*j][p+dy[m]*j]==2){b+='Y';continue;}//不在期盘；
                  if(a[q+dx[m]*j][p+dy[m]*j]==1)b+='1';
                  if(a[q+dx[m]*j][p+dy[m]*j]==0)b+='0';
                }QString k;int v=b.size();
              for(int s=v-1;s>=0;s--){
                  k+=b[s];
              }
         if(b==n1){a[q+dx[m]*(j)][p+dy[m]*(j)]=2;sum1=1;break;}
          if(k==n1){a[q+dx[m]*(j-6)][p+dy[m]*(j-6)]=2;sum=1;break;}
             if(b==h1){a[q+dx[m]*(j-2)][p+dy[m]*(j-2)]=2;sum=1;break;}
             if(k==h1){a[q+dx[m]*(j-5)][p+dy[m]*(j-5)]=2;sum=1;break;}
             if(b==l1){a[q+dx[m]*(j-3)][p+dy[m]*(j-3)]=2;sum=1;break;}
            if(k==l1){a[q+dx[m]*(j-4)][p+dy[m]*(j-4)]=2;sum=1;break;}

          }if(sum1)break;}}
        if(sum==0){int k=0;
        while(1){int s=rand()%8;k++;
            if(a[q+dx[s]][p+dy[s]]==0){a[q+dx[s]][p+dy[s]]=2;break;}
            if(k>15)break;}
        if(k>15){while(1){int t=rand()%21;int r=rand()%21;
        if(a[t][r]==0){a[t][r]=2;break;}}}
        }}

signals:void mysignal();

public slots:
};

#endif // SUB_H
