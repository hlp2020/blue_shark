#include "zuhe.h"
#include "ui_zuhe.h"

#include<QWidget>
#include<QDebug>
#include<QComboBox>
#include<widget.h>
#include<QPainter>
zuhe::zuhe(QWidget *parent) :
   QWidget(parent),
   ui(new Ui::zuhe)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/imi/25.jpg"));
    this->setFixedSize(1000,600);
    ui->comboBox->setCurrentText("组合型贷款");
    ui->lineEdit1->setPlaceholderText("请输入商业贷款额");
    ui->lineEdit2->setPlaceholderText("请输入公积金贷款额");
    ui->radioButton->setChecked(true);
    ui->comboBox->setMinimumWidth(500);
    ui->comboBox_2->setMinimumWidth(500);

//    connect(ui->comboBox,static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),[=]({
//        if(ui->comboBox->currentText()=="商业贷款" || ui->comboBox->currentText()=="公积金贷款")
//               {
//                   this->hide();
//                   this->showmain();
//                  this->show();
//        }
//    }));
    connect(ui->comboBox,static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),[=](){
     if(ui->comboBox->currentText()=="商业贷款" )
       { emit showm1();
       // qDebug()<<"dui";
     }
    });
    connect(ui->comboBox,static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),[=](){
        if(ui->comboBox->currentText()=="公积金贷款")
            {
            emit showm2();
        }
    });

    connect(ui->pushButton,&QPushButton::clicked,[=](){
       QString x,y;
       double sh,go;
       x=ui->lineEdit1->text();
       y=ui->lineEdit2->text();
       sh=x.toDouble();
       go=y.toDouble();
       sh=sh*10000;
       go=go*10000;
       double l1,l2;
       l1=ui->doubleSpinBox->value();
       l2=ui->doubleSpinBox_2->value();
       l1=(l1*0.01)/12;
       l2=(l2*0.01)/12;
       double ti;
       double zol1,zol2;
       ti=(25-ui->comboBox_2->currentIndex()) *12;
       if(ui->radioButton->isChecked()==true)
       {
           double m1,m2;
           m1=1+l1;
           m2=1+l2;
           for(int i=1;i<ti;i++)
           {
               m1=m1*(1+l1);
               m2=m2*(1+l2);
           }
           double hu1,hu2;
           hu1=sh*((l1*m1)/(m1-1));
           hu2=go*((l2*m2)/(m2-1));
           zol1=hu1*ti-sh;
           zol2=hu2*ti-go;
           double zohu;
           zohu=(hu1+hu2)*ti;
           ui->label_12->setText("每月月供：");
           ui->label_13->setNum(qRound(hu1+hu2));
           ui->label_14->setText("元");
           ui->label_15->setText("贷款总额：");
           ui->label_16->setNum(qRound(sh+go));
           ui->label_17->setText("元");
           ui->label_18->setText("支付利息：");
           ui->label_19->setNum(qRound(zol1+zol2));
           ui->label_20->setText("元");
           ui->label_21->setText("还款总额：");
           ui->label_22->setNum(qRound(zohu));
           ui->label_23->setText("元");
           ui->label_24->setText("还款月数：");
           ui->label_25->setNum(ti);
           ui->label_26->setText("个月");
           qDebug()<<"每月月供："<<qRound(hu1+hu2)<<"元";
           qDebug()<<"贷款总额："<<qRound(sh+go)<<"元";
           qDebug()<<"支付利息："<<qRound(zol1+zol2)<<"元";
           qDebug()<<"还款总额："<<qRound(zohu)<<"元";
           qDebug()<<"还款月数："<<ti<<"个月";
       }
       else
       {
           double p1,p2;
           p1=sh/ti;
           p2=go/ti;
           double d1,d2,di;
           d1=p1*l1;
           d2=p2*l2;
           di=d1+d2;
           double hu1,hu2;
           hu1=p1+sh*l1;
           hu2=p2+go*l2;
           double zod1,zod2;
           for(int i=0;i<ti;i++)
           {
               zod1=zod1+d1*i;
               zod2=zod2+d2*i;
           }
           double zol1,zol2;
           zol1=sh*l1*ti-zod1;
           zol2=go*l2*ti-zod2;
           ui->label_12->setText("首月月供：");
           ui->label_13->setNum(qRound(hu1+hu2));
           ui->label_14->setText("元");
           ui->label_15->setText("每月递减：");
           ui->label_16->setNum(qRound(di));
           ui->label_17->setText("元");
           ui->label_18->setText("贷款总额：");
           ui->label_19->setNum(qRound(sh+go));
           ui->label_20->setText("元");
           ui->label_21->setText("支付利息：");
           ui->label_22->setNum(qRound(zol1+zol2));
           ui->label_23->setText("元");
           ui->label_24->setText("还款总额：");
           ui->label_25->setNum(qRound(sh+go+zol1+zol2));
           ui->label_26->setText("元");
           ui->label_27->setText("还款月数：");
           ui->label_28->setNum(ti);
           ui->label_29->setText("个月");
           qDebug()<<"首月月供"<<qRound(hu1+hu2)<<"元";
           qDebug()<<"每月递减"<<qRound(di)<<"元";
           qDebug()<<"贷款总额"<<qRound(sh+go)<<"元";
           qDebug()<<"支付利息"<<qRound(zol1+zol2)<<"元";
           qDebug()<<"还款总额"<<qRound(sh+go+zol1+zol2)<<"元";
           qDebug()<<"还款月数"<<ti<<"元";
       }
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        ui->lineEdit1->setText("");
        ui->lineEdit2->setText("");
        ui->comboBox_2->setCurrentIndex(0);
        ui->doubleSpinBox->setValue(0.00);
        ui->doubleSpinBox_2->setValue(0.00);
        ui->radioButton->setChecked(true);
    });
}
//void zuhe::showmainwidget()
//{
//    this->hide();
//    qDebug()<<"哈";
//    emit showm();
//}
zuhe::~zuhe()
{
    delete ui;
}
void zuhe:: paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

     pix.load(":/imi/27.jpg");

    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
