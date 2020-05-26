#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QDialog>
#include<zuhe.h>
#include<zoesuan.h>
#include<QPainter>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    zuhe * zu=NULL;
    zoesuan * q=NULL;
    //重写painEvent事件,画背景图
    void paintEvent(QPaintEvent *);
private slots:
     void  showmain1();
     void  showmain2();//显示主窗口
     void  showmian();
     void  showzu();
//signals:
//    void showm();
private:
    Ui::Widget *ui;
    friend class zuhe;
};
#endif // WIDGET_H
