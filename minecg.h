#ifndef MINECG_H
#define MINECG_H

#include <QMainWindow>

namespace Ui {
class MineCG;
}
extern int nandu,mode;
class MineCG : public QMainWindow
{
    Q_OBJECT

public:
    explicit MineCG(QWidget *parent = nullptr);
    ~MineCG();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MineCG *ui;
};

#endif // MINECG_H
