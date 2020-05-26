#ifndef ZUHE_H
#define ZUHE_H

#include <QWidget>
//#include<widget.h>

namespace Ui {
class zuhe;
}

class zuhe : public QWidget
{
    Q_OBJECT

public:
    explicit zuhe(QWidget *parent = nullptr);
  \
    ~zuhe();
    void  showmainwidget();
    void paintEvent(QPaintEvent *);
signals:
     void showm1();
     void showm2();
private:
    Ui::zuhe *ui;
    // Widget a;
   // friend class Widget;


};

#endif // ZUHE_H
