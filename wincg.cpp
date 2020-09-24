#include "wincg.h"
#include "ui_wincg.h"
#include"QString"

int i2= 1;
winCG::winCG(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::winCG)
{
    ui->setupUi(this);
    ui->label->setText("                    歼星炮的所有位置已经全部被我们发现了，现在启动星际主炮，准备摧毁所有歼星炮                    ");
}

winCG::~winCG()
{
    delete ui;
}

void winCG::on_pushButton_clicked()
{
    i2++;//第几个动画
    if(i2 >= 5)
    {
        exit(0);
    }
    ui->label_2->setStyleSheet("background-image: url(:/res/res/win_"+QString::number(i2)+".png);");
    if(i2 == 2)
        ui->label->setText("                    星际主炮已经成功到达地面，准备启动爆破程序 \n                    5，4，3，2，1.成功爆炸                    ");
    if(i2 == 3)
         ui->label->setText("                   恭喜您，歼星炮已经成功毁灭。\n                   按照我们的任务进程，接下来我们将执行登录作战计划 \n                   我们会将我们的人员和物资投放到地球上。                    ");
    if(i2 == 4)
    {
       ui->pushButton->setText("退出游戏");
        ui->label->setText("                    我们已经成功登陆，人类的末日即将到来，恭喜您，长官。                      ");
}}
