#ifndef ZOESUAN_H
#define ZOESUAN_H

#include <QWidget>

namespace Ui {
class zoesuan;
}

class zoesuan : public QWidget
{
    Q_OBJECT

public:
    explicit zoesuan(QWidget *parent = nullptr);
    ~zoesuan();
    void  paintEvent(QPaintEvent *);
signals:
    void mian();
    void zuh();
private:
    Ui::zoesuan *ui;

signals:

};

#endif // ZOESUAN_H
