#ifndef WINCG_H
#define WINCG_H

#include <QMainWindow>

namespace Ui {
class winCG;
}

class winCG : public QMainWindow
{
    Q_OBJECT

public:
    explicit winCG(QWidget *parent = nullptr);
    ~winCG();

private slots:
    void on_pushButton_clicked();

private:
    Ui::winCG *ui;
};

#endif // WINCG_H
