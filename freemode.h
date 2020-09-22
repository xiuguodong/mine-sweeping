#ifndef FREEMODE_H
#define FREEMODE_H

#include <QMainWindow>

namespace Ui {
class FreeMode;
}

class FreeMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit FreeMode(QWidget *parent = nullptr);
    ~FreeMode();

private:
    Ui::FreeMode *ui;
};

#endif // FREEMODE_H
