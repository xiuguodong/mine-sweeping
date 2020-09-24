#ifndef LOSECG_H
#define LOSECG_H

#include <QMainWindow>

namespace Ui {
class loseCG;
}

class loseCG : public QMainWindow
{
    Q_OBJECT

public:
    explicit loseCG(QWidget *parent = nullptr);
    ~loseCG();

private slots:
    void on_pushButton_clicked();

private:
    Ui::loseCG *ui;
};

#endif // LOSECG_H
