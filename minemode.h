#ifndef MINEMODE_H
#define MINEMODE_H

#include <QMainWindow>

namespace Ui {
class MineMode;
}
class MineMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit MineMode(QWidget *parent = nullptr);
    ~MineMode();
public slots:
    void winmode();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MineMode *ui;
};

#endif // MINEMODE_H
