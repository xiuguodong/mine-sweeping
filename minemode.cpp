#include "minemode.h"
#include "ui_minemode.h"
#include"QCheckBox"
#include"QGridLayout"
#include"QPushButton"
#include"vector"
#include"minecg.h"
#include <algorithm>
#include <QTime>
#include<QString>
#include<QDebug>
#include<queue>
#include<QMessageBox>
#include<wincg.h>
#include<losecg.h>
MineMode::MineMode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MineMode)
{
    ui->setupUi(this);
   /* QPixmap *banzi = new QPixmap(":/res/res/back_01.png");
    banzi ->scaled(ui->label_2->size(),Qt::KeepAspectRatio);
    ui->label_2->setScaledContents(true);
    ui->label_2->setPixmap(*banzi);*/
    std::vector<QPushButton*> easy,hard,ex;
    //调试
    //nandu = 1;
    if(nandu == 0)
    {
    for(int i = 0;i<10;i++)
    {
        for(int k = 0;k<10;k++)
        {
        QPushButton *a = new QPushButton(this);
        a->move(250+75*i, 25+75*k);
        a->resize(75, 75);
        a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                         background-color: rgb(240,255,240);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(240,255,240);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(240,255,240);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(240,255,240);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(240,255,240);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(240,255,240);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(240,255,240);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(240,255,240);");
               
                
                a->setFlat(false);
        easy.push_back(a);
        }
    }
    std::vector<int> x;
    std::vector<int> y;



    for(int i =1;;i++)
    {
b: int x1,y1;
        if(i%2 == 1&&x.size() <=10)
        {
        QTime time;
        time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000+i*10000);
       x1= qrand() % 10;    //产生10以内的随机数
        }
        else if(y.size() <= 10)
        {
            QTime time;
            time= QTime::currentTime();
            qsrand(time.msec()+time.second()*1000+i*10000);
            y1 = qrand() % 10;    //产生10以内的随机数


        }
        if(x.size() == 11 && y.size() == 11)
        {
            break;

        }
        for(int i1 =1;i1<(int)x.size();i1++)
        if ( x1 == x[i1] && y1 == y[i1] )
        {
            goto b;
        }
        x.push_back(x1);y.push_back(y1);

    }
    for(int i=0;i<10;i++)
        for(int k = 0;k<10;k++)
        {
            connect(easy[i*10+k],&QPushButton::clicked,this,[=](){
                int sum = 0;
                for(int i1 =1;i1<(int)x.size();i1++)
                if ( k == x[i1] && i == y[i1] )
                {
                    easy[i*10+k]->setText("X");
                    if(mode == 2)
                    {
                    int ret = QMessageBox::information(this,"提示","被发现了，游戏失败","退出游戏");
                    if(!ret)
                    {
                        exit(0);
                    }
                    }
                    else
                    {
                        loseCG *a = new loseCG(this);
                        a->show();
                        this->hide();
                    }
                }

                for(int i1 = i - 1;i1<=i+1;i1++)
                    for(int k1 = k - 1;k1<=k+1;k1++)
                    {
                        bool flag = false;
                        for(int i11 =1;i11<(int)x.size();i11++)
                        if ( k1 == x[i11] && i1 == y[i11] )
                        {
                            flag = true;
                        }
                        if( flag)
                        { // qDebug()<<i1<<' '<<k1<<endl;
                            sum++;}                    }
                if(sum!=0)
                {//qDebug()<<sum<<endl;
                    easy[i*10+k]->setText(QString::number(sum));
                    QPushButton *tmp = easy[i*10+k];
                    if(sum == 1)
                        tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                            background-color: rgb(240,255,240);\
                                            color: rgb(0,191,255)");
                          if(sum == 2)
                              tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                  background-color: rgb(240,255,240);\
                                                  color: rgb(50,205,50)");
                            if(sum == 3)
                                tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                   background-color: rgb(240,255,240);\
                                                    color: rgb(205,104,57)");
                      if(sum == 4)
                          tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                              background-color: rgb(240,255,240);\
                                              color: rgb(255,48,48)");
                            if(sum == 5)
                                tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                   background-color: rgb(240,255,240);\
                                                    color: rgb(218,112,214)");
                      if(sum == 6)
                          tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                             background-color: rgb(240,255,240);\
                                              color: rgb(0,0,0)");
                            if(sum == 7)
                                tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                   background-color: rgb(240,255,240);\
                                                    color: rgb(255,0,0)");
                      if(sum == 8)
                          tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                            background-color: rgb(240,255,240);\
                                              color: rgb(205,201,201)");
                            if(sum == 1)
                                tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                    background-color: rgb(240,255,240);\
                                                    color: rgb(0,191,255)");
                                  if(sum == 2)
                                      tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                          background-color: rgb(240,255,240);\
                                                          color: rgb(50,205,50)");
                                    if(sum == 3)
                                        tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                           background-color: rgb(240,255,240);\
                                                            color: rgb(205,104,57)");
                              if(sum == 4)
                                  tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                      background-color: rgb(240,255,240);\
                                                      color: rgb(255,48,48)");
                                    if(sum == 5)
                                        tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                           background-color: rgb(240,255,240);\
                                                            color: rgb(218,112,214)");
                              if(sum == 6)
                                  tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                     background-color: rgb(240,255,240);\
                                                      color: rgb(0,0,0)");
                                    if(sum == 7)
                                        tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                           background-color: rgb(240,255,240);\
                                                            color: rgb(255,0,0)");
                              if(sum == 8)
                                  tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                    background-color: rgb(240,255,240);\
                                                      color: rgb(205,201,201)");
                }
                if(sum == 0)
                {

                    //easy[i*10+k]->setText(QString::number(sum));
                    easy[i*10+k]->setStyleSheet("background-image: url(:/res/res/bg.png);");

                    std::vector<int> xp;
                    std::queue<int> nowx;
                    std::queue<int> nowy;
                    xp.push_back(i*100+k);
                    int ii = i,kk=k;

                        int px[] = {-1, 0, 1, 0};   //移动方向的数组
                            int py[] = {0, -1, 0, 1};
                            nowy.push(ii);
                            nowx.push(kk);//将起点入队
                            while (!nowx.empty()||!nowy.empty())
                            {   sum = 0;
                                //只要队列不为空
                                qDebug()<<nowx.size()<<endl;
                                auto tempx = nowx.front();
                                nowx.pop();
                                kk = tempx;
                                auto tempy = nowy.front();
                                nowy.pop();
                                ii = tempy;
                                if(kk>=10||kk<0||ii>=10||ii<0)
                                    continue;

                                    for(int i1 = ii - 1;i1<=ii+1;i1++)
                                        for(int k1 = kk - 1;k1<=kk+1;k1++)
                                        {
                                            bool flag = false;
                                            for(int i11 =1;i11<(int)x.size();i11++)
                                            if ( k1 == x[i11] && i1 == y[i11] )
                                            {
                                                flag = true;
                                            }
                                            if( flag)
                                            {
                                                sum++;
                                            }
                                        }
                                    if(sum!=0)
                                    {

                                        easy[ii*10+kk]->setText(QString::number(sum));
                                        QPushButton *tmp = easy[ii*10+kk];
                                        if(sum == 1)
                                            tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                background-color: rgb(240,255,240);\
                                                                color: rgb(0,191,255)");
                                              if(sum == 2)
                                                  tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                      background-color: rgb(240,255,240);\
                                                                      color: rgb(50,205,50)");
                                                if(sum == 3)
                                                    tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                       background-color: rgb(240,255,240);\
                                                                        color: rgb(205,104,57)");
                                          if(sum == 4)
                                              tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                  background-color: rgb(240,255,240);\
                                                                  color: rgb(255,48,48)");
                                                if(sum == 5)
                                                    tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                       background-color: rgb(240,255,240);\
                                                                        color: rgb(218,112,214)");
                                          if(sum == 6)
                                              tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                 background-color: rgb(240,255,240);\
                                                                  color: rgb(0,0,0)");
                                                if(sum == 7)
                                                    tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                       background-color: rgb(240,255,240);\
                                                                        color: rgb(255,0,0)");
                                          if(sum == 8)
                                              tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                background-color: rgb(240,255,240);\
                                                                  color: rgb(205,201,201)");
                                                if(sum == 1)
                                                    tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                        background-color: rgb(240,255,240);\
                                                                        color: rgb(0,191,255)");
                                                      if(sum == 2)
                                                          tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                              background-color: rgb(240,255,240);\
                                                                              color: rgb(50,205,50)");
                                                        if(sum == 3)
                                                            tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                               background-color: rgb(240,255,240);\
                                                                                color: rgb(205,104,57)");
                                                  if(sum == 4)
                                                      tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                          background-color: rgb(240,255,240);\
                                                                          color: rgb(255,48,48)");
                                                        if(sum == 5)
                                                            tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                               background-color: rgb(240,255,240);\
                                                                                color: rgb(218,112,214)");
                                                  if(sum == 6)
                                                      tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                         background-color: rgb(240,255,240);\
                                                                          color: rgb(0,0,0)");
                                                        if(sum == 7)
                                                            tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                               background-color: rgb(240,255,240);\
                                                                                color: rgb(255,0,0)");
                                                  if(sum == 8)
                                                      tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                        background-color: rgb(240,255,240);\
                                                                          color: rgb(205,201,201)");
                                    }
                                    if(sum == 0)
                                    {

                                      //  easy[ii*10+kk]->setText(QString::number(sum));
                                        easy[ii*10+kk]->setStyleSheet("background-image: url(:/res/res/bg.png);");
                                        for(int p = 0;p<=3;p++)
                                            {
                                                if(std::find(xp.begin(),xp.end(),(ii+py[p])*100+(kk+px[p]))==xp.end())//&&ii+py[p]>0&&ii+py[p]<10&&kk+px[p]>0&&kk+px[p]<10)
                                                {
                                                   // qDebug()<<kk+px[p]<<" "<<ii+py[p]<<endl;
                                                    nowy.push(ii+py[p]);
                                                    nowx.push(kk+px[p]);
                                                    xp.push_back((ii+py[p])*100+(kk+px[p]));
                                                }

                                            }

                                    }
                                    //qDebug()<<nowx.size()<<endl;
                                }


            };


    });}}
    if(nandu == 2)
    {
    for(int i = 0;i<25;i++)
    {
        for(int k = 0;k<25;k++)
        {
        QPushButton *a = new QPushButton(this);
        a->move(225+30*i, 25+30*k);
        a->resize(30, 30);
        a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                         background-color: rgb(255,222,173);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(255,222,173);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(255,222,173);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(255,222,173);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(255,222,173);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(255,222,173);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(255,222,173);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(255,222,173);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(255,222,173);");
                
        hard.push_back(a);
        }
    }
        std::vector<int> x;
        std::vector<int> y;



        for(int i =1;;i++)
        {
   b1:  int x1,y1;
            if(i%2 == 1&&x.size() <=100)
            {
            QTime time;
            time= QTime::currentTime();
            qsrand(time.msec()+time.second()*1000+i*10000);
           x1= qrand() % 25;    //产生25以内的随机数
            }
            else if(y.size() <= 100)
            {
                QTime time;
                time= QTime::currentTime();
                qsrand(time.msec()+time.second()*1000+i*10000);
                y1 = qrand() % 25;    //产生25以内的随机数


            }
            if(x.size() == 101 && y.size() == 101)
            {
                break;

            }
            for(int i1 =1;i1<(int)x.size();i1++)
            if ( x1 == x[i1] && y1 == y[i1] )
            {
                goto b1;
            }
            x.push_back(x1);y.push_back(y1);

        }
        for(int i=0;i<25;i++)
            for(int k = 0;k<25;k++)
            {
                connect(hard[i*25+k],&QPushButton::clicked,this,[=](){
                    //qDebug()<<"ilxdn1";
                    int sum = 0;
                    for(int i1 =1;i1<(int)x.size();i1++)
                    if ( k == x[i1] && i == y[i1] )
                    {
                        hard[i*25+k]->setText("X");
                        if(mode == 2)
                        {
                        int ret = QMessageBox::information(this,"提示","被发现了，游戏失败","退出游戏");
                        if(!ret)
                        {
                            exit(0);
                        }
                        }
                        else
                        {
                            loseCG *a = new loseCG(this);
                            a->show();
                            this->hide();
                        }
                    }
                  //  qDebug()<<"ilxdn2";
                    for(int i1 = i - 1;i1<=i+1;i1++)
                        for(int k1 = k - 1;k1<=k+1;k1++)
                        {
                            // qDebug()<<"ilxdn3";
                            bool flag = false;
                            for(int i11 =1;i11<(int)x.size();i11++)
                            if ( k1 == x[i11] && i1 == y[i11] )
                            {
                                flag = true;
                            }
                            if( flag)
                            { // qDebug()<<i1<<' '<<k1<<endl;
                                sum++;}
                       }
                     //qDebug()<<"ilxdn5";
                    if(sum!=0)
                    {//qDebug()<<sum<<endl;
                        hard[i*25+k]->setText(QString::number(sum));
                        QPushButton *tmp = hard[i*25+k];
                        if(sum == 1)
                            tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                               background-color: rgb(255,222,173);\
                                                color: rgb(0,191,255)");
                              if(sum == 2)
                                  tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                     background-color: rgb(255,222,173);\
                                                      color: rgb(50,205,50)");
                                if(sum == 3)
                                    tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                       background-color: rgb(255,222,173);\
                                                        color: rgb(205,104,57)");
                          if(sum == 4)
                              tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                 background-color: rgb(255,222,173);\
                                                  color: rgb(255,48,48)");
                                if(sum == 5)
                                    tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                      background-color: rgb(255,222,173);\
                                                        color: rgb(218,112,214)");
                          if(sum == 6)
                              tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                 background-color: rgb(255,222,173);\
                                                  color: rgb(0,0,0)");
                                if(sum == 7)
                                    tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                       background-color: rgb(255,222,173);\
                                                        color: rgb(255,0,0)");
                          if(sum == 8)
                              tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                background-color: rgb(255,222,173);\
                                                  color: rgb(205,201,201)");

                    }
                    if(sum == 0)
                    {
                       // qDebug()<<"ilxdn1";




                        std::vector<int> xp;
                        std::queue<int> nowx;
                        std::queue<int> nowy;
                        xp.push_back(i*100+k);
                        //qDebug()<<"ilxdn2";
                        int ii = i,kk=k;
                       //  hard[ii*25+kk]->setText(QString::number(sum));
                         hard[ii*25+kk]->setStyleSheet("background-image: url(:/res/res/bg.png);");
                          //hard[ii*25+kk]->setFlat(true);
                            int px[] = {-1, 0, 1, 0};   //移动方向的数组
                                int py[] = {0, -1, 0, 1};
                                nowy.push(ii);
                                nowx.push(kk);//将起点入队
                                while (!nowx.empty()||!nowy.empty())
                                {   sum = 0;
                                    //只要队列不为空
                                   // qDebug()<<nowx.size()<<endl;
                                    auto tempx = nowx.front();
                                    nowx.pop();
                                    kk = tempx;
                                    auto tempy = nowy.front();
                                    nowy.pop();
                                    ii = tempy;
                                    if(kk>=25||kk<0||ii>=25||ii<0)
                                        continue;
                                    //qDebug()<<"ilxdn3";
                                        for(int i1 = ii - 1;i1<=ii+1;i1++)
                                            for(int k1 = kk - 1;k1<=kk+1;k1++)
                                            {
                                                bool flag = false;
                                                for(int i11 =1;i11<(int)x.size();i11++)
                                                if ( k1 == x[i11] && i1 == y[i11] )
                                                {
                                                    flag = true;
                                                }
                                                if( flag)
                                                {
                                                    sum++;
                                                }
                                            }
                                        //qDebug()<<"ilxdn4";
                                        if(sum!=0)
                                        {
                                           hard[ii*25+kk]->setText(QString::number(sum));
                                           QPushButton *tmp = hard[ii*25+kk];
                                           if(sum == 1)
                                               tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                  background-color: rgb(255,222,173);\
                                                                   color: rgb(0,191,255)");
                                                 if(sum == 2)
                                                     tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                        background-color: rgb(255,222,173);\
                                                                         color: rgb(50,205,50)");
                                                   if(sum == 3)
                                                       tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                          background-color: rgb(255,222,173);\
                                                                           color: rgb(205,104,57)");
                                             if(sum == 4)
                                                 tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                    background-color: rgb(255,222,173);\
                                                                     color: rgb(255,48,48)");
                                                   if(sum == 5)
                                                       tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                         background-color: rgb(255,222,173);\
                                                                           color: rgb(218,112,214)");
                                             if(sum == 6)
                                                 tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                    background-color: rgb(255,222,173);\
                                                                     color: rgb(0,0,0)");
                                                   if(sum == 7)
                                                       tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                          background-color: rgb(255,222,173);\
                                                                           color: rgb(255,0,0)");
                                             if(sum == 8)
                                                 tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                   background-color: rgb(255,222,173);\
                                                                     color: rgb(205,201,201)");

                                        }
                                        if(sum == 0)
                                        {

                                          // hard[ii*25+kk]->setText(QString::number(sum));
                                        hard[ii*25+kk]->setStyleSheet("background-image: url(:/res/res/bg.png);");
                                            for(int p = 0;p<=3;p++)
                                                {
                                                    if(std::find(xp.begin(),xp.end(),(ii+py[p])*100+(kk+px[p]))==xp.end())//&&ii+py[p]>0&&ii+py[p]<10&&kk+px[p]>0&&kk+px[p]<10)
                                                    {
                                                       // qDebug()<<kk+px[p]<<" "<<ii+py[p]<<endl;
                                                        nowy.push(ii+py[p]);
                                                        nowx.push(kk+px[p]);
                                                        xp.push_back((ii+py[p])*100+(kk+px[p]));
                                                    }

                                                }

                                        }
                                        qDebug()<<nowx.size()<<endl;
                                    }


                };


        });}
    }
    if(nandu == 1)
    {
    for(int i = 0;i<15;i++)
    {
        for(int k = 0;k<15;k++)
        {
        QPushButton *a = new QPushButton(this);
        a->move(250+50*i, 25+50*k);
        a->resize(50, 50);
        a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                         background-color: rgb(255,228,225);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(255,228,225);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(255,228,225);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(255,228,225);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(255,228,225);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(255,228,225);");
                a->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                 background-color: rgb(255,228,225);");
        ex.push_back(a);
        }
    }
    std::vector<int> x;
    std::vector<int> y;



    for(int i =1;;i++)
    {
b2:  int x1,y1;
        if(i%2 == 1&&x.size() <=20)
        {
        QTime time;
        time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000+i*10000);
       x1= qrand() % 15;    //产生25以内的随机数
        }
        else if(y.size() <= 20)
        {
            QTime time;
            time= QTime::currentTime();
            qsrand(time.msec()+time.second()*1000+i*10000);
            y1 = qrand() % 15;    //产生25以内的随机数


        }
        if(x.size() == 21 && y.size() == 21)
        {
            break;

        }
        for(int i1 =1;i1<(int)x.size();i1++)
        if ( x1 == x[i1] && y1 == y[i1] )
        {
            goto b2;
        }
        x.push_back(x1);y.push_back(y1);

    }
    for(int i=0;i<15;i++)
        for(int k = 0;k<15;k++)
        {
            connect(ex[i*15+k],&QPushButton::clicked,this,[=](){
                //qDebug()<<"ilxdn1";
                int sum = 0;
                for(int i1 =1;i1<(int)x.size();i1++)
                if ( k == x[i1] && i == y[i1] )
                {
                   ex[i*15+k]->setText("X");
                   if(mode == 2)
                   {
                   int ret = QMessageBox::information(this,"提示","被发现了，游戏失败","退出游戏");
                   if(!ret)
                   {
                       exit(0);
                   }
                   }
                   else
                   {
                       loseCG *a = new loseCG(this);
                       a->show();
                       this->hide();
                   }
                }
              //  qDebug()<<"ilxdn2";
                for(int i1 = i - 1;i1<=i+1;i1++)
                    for(int k1 = k - 1;k1<=k+1;k1++)
                    {
                        // qDebug()<<"ilxdn3";
                        bool flag = false;
                        for(int i11 =1;i11<(int)x.size();i11++)
                        if ( k1 == x[i11] && i1 == y[i11] )
                        {
                            flag = true;
                        }
                        if( flag)
                        { // qDebug()<<i1<<' '<<k1<<endl;
                            sum++;}
                   }
                 //qDebug()<<"ilxdn5";
                if(sum!=0)
                {//qDebug()<<sum<<endl;
                    QPushButton *tmp = ex[i*15+k];
                    if(sum == 1)
                        tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                           background-color: rgb(255,228,225);\
                                            color: rgb(0,191,255)");
                          if(sum == 2)
                              tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                 background-color: rgb(255,228,225);\
                                                  color: rgb(50,205,50)");
                            if(sum == 3)
                                tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                   background-color: rgb(255,228,225);\
                                                    color: rgb(205,104,57)");
                      if(sum == 4)
                          tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                             background-color: rgb(255,228,225);\
                                              color: rgb(255,48,48)");
                            if(sum == 5)
                                tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                   background-color: rgb(255,228,225);\
                                                    color: rgb(218,112,214)");
                      if(sum == 6)
                          tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                             background-color: rgb(255,228,225);\
                                              color: rgb(0,0,0)");
                            if(sum == 7)
                                tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                   background-color: rgb(255,228,225);\
                                                    color: rgb(255,0,0)");
                      if(sum == 8)
                          tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                             background-color: rgb(255,228,225);\
                                              color: rgb(205,201,201)");
                    ex[i*15+k]->setText(QString::number(sum));
                }
                if(sum == 0)
                {
                   // qDebug()<<"ilxdn1";




                    std::vector<int> xp;
                    std::queue<int> nowx;
                    std::queue<int> nowy;
                    xp.push_back(i*100+k);
                    //qDebug()<<"ilxdn2";
                    int ii = i,kk=k;
                     //ex[ii*15+kk]->setText(QString::number(sum));
                    ex[ii*15+kk]->setStyleSheet("background-image: url(:/res/res/bg.png);");
                        int px[] = {-1, 0, 1, 0};   //移动方向的数组
                            int py[] = {0, -1, 0, 1};
                            nowy.push(ii);
                            nowx.push(kk);//将起点入队
                            while (!nowx.empty()||!nowy.empty())
                            {   sum = 0;
                                //只要队列不为空
                               // qDebug()<<nowx.size()<<endl;
                                auto tempx = nowx.front();
                                nowx.pop();
                                kk = tempx;
                                auto tempy = nowy.front();
                                nowy.pop();
                                ii = tempy;
                                if(kk>=15||kk<0||ii>=15||ii<0)
                                    continue;
                                //qDebug()<<"ilxdn3";
                                    for(int i1 = ii - 1;i1<=ii+1;i1++)
                                        for(int k1 = kk - 1;k1<=kk+1;k1++)
                                        {
                                            bool flag = false;
                                            for(int i11 =1;i11<(int)x.size();i11++)
                                            if ( k1 == x[i11] && i1 == y[i11] )
                                            {
                                                flag = true;
                                            }
                                            if( flag)
                                            {
                                                sum++;
                                            }
                                        }
                                    //qDebug()<<"ilxdn4";
                                    if(sum!=0)
                                    {
                                        QPushButton *tmp = ex[ii*15+kk];
                                        if(sum == 1)
                                            tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                               background-color: rgb(255,228,225);\
                                                                color: rgb(0,191,255)");
                                              if(sum == 2)
                                                  tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                     background-color: rgb(255,228,225);\
                                                                      color: rgb(50,205,50)");
                                                if(sum == 3)
                                                    tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                       background-color: rgb(255,228,225);\
                                                                        color: rgb(205,104,57)");
                                          if(sum == 4)
                                              tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                 background-color: rgb(255,228,225);\
                                                                  color: rgb(255,48,48)");
                                                if(sum == 5)
                                                    tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                       background-color: rgb(255,228,225);\
                                                                        color: rgb(218,112,214)");
                                          if(sum == 6)
                                              tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                 background-color: rgb(255,228,225);\
                                                                  color: rgb(0,0,0)");
                                                if(sum == 7)
                                                    tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                       background-color: rgb(255,228,225);\
                                                                        color: rgb(255,0,0)");
                                          if(sum == 8)
                                              tmp->setStyleSheet("font: 14pt \"方正粗圆简体\";\
                                                                 background-color: rgb(255,228,225);\
                                                                  color: rgb(205,201,201)");
                                        ex[ii*15+kk]->setText(QString::number(sum));

                                    }
                                    if(sum == 0)
                                    {

                                      // ex[ii*15+kk]->setText(QString::number(sum));
                                        ex[ii*15+kk]->setStyleSheet("background-image: url(:/res/res/bg.png);");
                                        for(int p = 0;p<=3;p++)
                                            {
                                                if(std::find(xp.begin(),xp.end(),(ii+py[p])*100+(kk+px[p]))==xp.end())//&&ii+py[p]>0&&ii+py[p]<10&&kk+px[p]>0&&kk+px[p]<10)
                                                {
                                                   // qDebug()<<kk+px[p]<<" "<<ii+py[p]<<endl;
                                                    nowy.push(ii+py[p]);
                                                    nowx.push(kk+px[p]);
                                                    xp.push_back((ii+py[p])*100+(kk+px[p]));
                                                }

                                            }

                                    }
                                    qDebug()<<nowx.size()<<endl;
                                }


            };


    });}
    }

}

void MineMode::winmode()
{

    int ret = QMessageBox::information(this,"提示","恭喜胜利","退出游戏");
    if(!ret)
    {
        exit(0);
    }

}
MineMode::~MineMode()
{
    delete ui;
}

void MineMode::on_pushButton_clicked()
{
    if(mode == 2)
        this->winmode();
    else
    {
        winCG *a = new winCG(this);
        a->show();
        this->hide();
    }
}
