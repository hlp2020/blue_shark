#include "zoesuan.h"
#include "ui_zoesuan.h"
#include<QDebug>
#include<QPainter>
zoesuan::zoesuan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zoesuan)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/imi/30.jpg"));
    this->setFixedSize(1000,600);
    ui->comboBox->setMinimumWidth(500);
    ui->comboBox_2->setMinimumWidth(500);
    ui->comboBox_3->setMinimumWidth(500);
    ui->comboBox_4->setMinimumWidth(500);
    ui->radioButton->setChecked(true);
    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit->setPlaceholderText("请输入贷款总额");
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString x;
        double zo;
        x=ui->lineEdit->text();
        zo=x.toDouble();
        zo=zo*10000;
        double l;
        l=ui->doubleSpinBox->value();
        l=(l*0.01)/12;
        double ti;
        double zoli;
        ti=(25-ui->comboBox_4->currentIndex())*12;
        if(ui->radioButton->isChecked()==true)
        {
            double m;
            m=1+l;
            for(int i=1;i<ti;i++)
            {
                m=m*(1+l);
            }
            double hu;
            hu=zo*(l*m)/(m-1);
            zoli=hu*ti-zo;
            double zohu;
            zohu=hu*ti;
            ui->label_24->setText("首月月供：");
            ui->label_25->setNum(qRound(hu));
            ui->label_26->setText("元");
            ui->label_27->setText("贷款总额：");
            ui->label_28->setNum(qRound(zo));
            ui->label_29->setText("元");
            ui->label_30->setText("支付利息：");
            ui->label_31->setNum(qRound(zoli));
            ui->label_32->setText("元");
            ui->label_33->setText("还款总额：");
            ui->label_34->setNum(qRound(zohu));
            ui->label_35->setText("元");
            ui->label_36->setText("还款月数：");
            ui->label_37->setNum(ti);
            ui->label_38->setText("个月");
            qDebug()<<"每月月供："<<qRound(hu)<<"元";
            qDebug()<<"贷款总额："<<qRound(zo)<<"元";
            qDebug()<<"支付利息："<<qRound(zoli)<<"元";
            qDebug()<<"还款总额："<<qRound(zohu)<<"元";
            qDebug()<<"还款月数："<<ti<<"个月";
        }
        else
        {
            double p;
            p=zo/ti;
            double d;
            d=p*l;
            double hu;
            hu=p+zo*l;
            double zodi;
            for(int i=0;i<ti;i++)
            {
                zodi=zodi+d*i;
            }
            double zoli;
            zoli=zo*l*ti-zodi;
            ui->label_24->setText("首月月供：");
            ui->label_25->setNum(qRound(hu));
            ui->label_26->setText("元");
            ui->label_27->setText("每月递减：");
            ui->label_28->setNum(qRound(d));
            ui->label_29->setText("元");
            ui->label_30->setText("贷款总额：");
            ui->label_31->setNum(qRound(zo));
            ui->label_32->setText("元");
            ui->label_33->setText("支付利息：");
            ui->label_34->setNum(qRound(zoli));
            ui->label_35->setText("元");
            ui->label_36->setText("还款总额：");
            ui->label_37->setNum(qRound(zoli+zo));
            ui->label_38->setText("元");
            ui->label_39->setText("还款月数：");
            ui->label_40->setNum(ti);
            ui->label_41->setText("个月");
            qDebug()<<"首月月供"<<qRound(hu)<<"元";
            qDebug()<<"每月递减"<<qRound(d)<<"元";
            qDebug()<<"贷款总额"<<qRound(zo)<<"元";
            qDebug()<<"支付利息"<<qRound(zoli)<<"元";
            qDebug()<<"还款总额"<<qRound(zoli+zo)<<"元";
            qDebug()<<"还款月数"<<ti<<"元";
        }
    });
    connect(ui->comboBox_2,static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),[=](){
        if(ui->comboBox_2->currentText()=="根据面积，单价计算")
            {
            emit mian();
        }
    });
     connect(ui->comboBox,static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),[=](){
         if(ui->comboBox->currentText()=="组合型贷款")
             {
             emit zuh();
         }
     });

    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        ui->lineEdit->setText("");
        ui->comboBox_4->setCurrentIndex(0);
        ui->doubleSpinBox->setValue(0.00);
        ui->radioButton->setChecked(true);
        ui->comboBox_2->setCurrentIndex(0);
    });
}

zoesuan::~zoesuan()
{
    delete ui;
}
void zoesuan:: paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

     pix.load(":/imi/16.jpg");

    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
