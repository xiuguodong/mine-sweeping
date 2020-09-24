#include "minecg.h"
#include "ui_minecg.h"
#include"QString"
#include"minemode.h"
int i1= 1;
MineCG::MineCG(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MineCG)
{
    ui->setupUi(this);
     ui->label->setText("                    宇宙历114514年，露克星人突袭地球，您是这次突袭行动中露克星的最高指挥长。                    ");
}

MineCG::~MineCG()
{
    delete ui;

}

void MineCG::on_pushButton_clicked()
{
    i1++;
    if(i1 >= 5)
       {
        MineMode *a = new MineMode(this);
        a->show();
        this->hide();
    }
    ui->label_2->setStyleSheet("background-image: url(:/res/res/start_"+QString::number(i1)+".png);");
    if(i1 == 2)
        ui->label->setText("                    地球上一种名叫人类的物种为了反抗您，制造并设置了许多歼星炮 \n                    不过不要害怕，我们星际舰队的主炮可以克制这种武器。                    ");
    if(i1 == 3)
         ui->label->setText("                   因为我们远离母星，只带了发射有限次次主炮的能量。\n                   不过我们可以在地球上放置探测器来窥探歼星炮的位置 \n                   当我们可以确定全部歼星炮的位置的时候，就可以将人类一网打尽。                    ");
    if(i1 == 4)
    {

        ui->label->setText("                    但是我们还是需要小心，如果人类发现了我们的探测器，歼星炮将立刻发射 \n                    您的探测器已经准备完成，祝您好运。                    ");
    }


}
