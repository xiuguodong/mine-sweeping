#include "startgame.h"
#include "ui_startgame.h"
#include<QFile>
#include<QMessageBox>
#include"minecg.h"
#include<minecg.h>
#include<minemode.h>
StartGame::StartGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartGame)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);//去掉最大化按钮
    this->setFixedSize(this->size().width(),this->size().height());
}

StartGame::~StartGame()
{
    delete ui;
}

void StartGame::on_btn_start_clicked()
{
    int ret1 = QMessageBox::information(this,"选择","选择游戏模式","自由模式","闯关模式","返回");
    if(ret1!=2)
    {
    int ret =0;
    if(!ret)
    {
        if(ret1 == 1)
            {
            mode = 1;
        int ret3 = QMessageBox::information(this,"选择","选择难度","萌新","高手","大师");
        nandu=ret3;
        MineCG * a = new MineCG(this);
        a->show();
        this->hide();
        }
        if(ret1 == 0)
            {
            mode = 2;
        int ret3 = QMessageBox::information(this,"选择","选择难度","萌新","高手","大师");
        nandu=ret3;
        MineMode * a = new MineMode(this);
        a->show();
        this->hide();
        }
    }}
}



void StartGame::on_pushButton_3_clicked()
{
    int ret = QMessageBox::critical(this,"警告","你确定要退出游戏吗？","确定","取消");
    if(!ret)
    {
        exit(0);
    }
}



