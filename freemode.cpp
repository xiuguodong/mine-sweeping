#include "freemode.h"
#include "ui_freemode.h"

FreeMode::FreeMode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FreeMode)
{
    ui->setupUi(this);
}

FreeMode::~FreeMode()
{
    delete ui;
}
