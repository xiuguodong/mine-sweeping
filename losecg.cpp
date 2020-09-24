#include "losecg.h"
#include "ui_losecg.h"
#include"QString"

int i= 1;
loseCG::loseCG(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loseCG)
{
    ui->setupUi(this);
     ui->label->setText("                    人类发现了我们的探测器，他们出动大量军队伤害了我们的探测器\n                    并且向我们发射了歼星炮，我们损失过半，撤退！撤退！                    ");
}

loseCG::~loseCG()
{
    delete ui;
}

void loseCG::on_pushButton_clicked()
{
    i++;
    if(i >= 3)
       {
       exit(0);
    }
    ui->label_2->setStyleSheet("background-image: url(:/res/res/lose_"+QString::number(i)+".jpg);");
    if(i == 2)
    {
        ui->pushButton->setText("退出游戏");
        ui->label->setText("                    人类的歼星炮已经制造完成了，他们已经发射了歼星炮。\n                    启动星际跳跃，快速撤退。我宣布我们将永久撤离太阳系。                    ");

    }
}
