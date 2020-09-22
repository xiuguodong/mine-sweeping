#include "startgame.h"
#include"minecg.h"
#include <QApplication>
#include"minemode.h"
int nandu,mode = 0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   StartGame w;
    w.show();
    return a.exec();
}
