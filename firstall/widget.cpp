#include "widget.h"
#include "ui_widget.h"
#include<QComboBox>
#include<QAbstractItemView>
#include<QDebug>
#include<QString>
#include<QPainter>
#include<QDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //重置窗口大小
    resize(1000,600);
    //ui->comboBox1->view()->parentWidget()->setWindowFlags(Qt::Popup|Qt::FramelessWindowHint);
  //  ui->comboBox1->view()->parentWidget()->setAttribute(Qt::WA_TranslucentBackground);
    setWindowIcon(QIcon(":/imi/32.jpg"));
    zu=new zuhe;
    q=new zoesuan;
    ui->comboBox1->setMinimumWidth(500);
    ui->lineEdit_2->setPlaceholderText("请输入房屋单价");
    ui->lineEdit_3->setPlaceholderText("请输入房屋面积");
    connect(zu,SIGNAL(showm1()),this,SLOT(showmain1()));
    connect(zu,SIGNAL(showm2()),this,SLOT(showmain2()));
    connect(q,SIGNAL(mian()),this,SLOT(showmian()));
    connect(q,SIGNAL(zuh()),this,SLOT(showzu()));
    ui->comboBox2->setCurrentIndex(8);
    ui->comboBox2->setMinimumWidth(500);
    ui->comboBox3->setMinimumWidth(500);
    ui->radioButton->setChecked(true);
    ui->comboBox4->setMinimumWidth(500);
    //qDebug()<<this->frameGeometry().width() << this->frameGeometry().height();

  // zuhe  * zu(this);
    //选择进入组合型贷款中
//下拉框
    connect(ui->comboBox1, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),[=](){
        if(ui->comboBox1->currentText()=="组合型贷款")
          {  //进入组合型贷款场景
            //自身隐藏
            this->hide();
            zu->show();


        }

    });


    //选择进入贷款总额
    connect(ui->comboBox4, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),[=](){
        if(ui->comboBox4->currentText()=="根据贷款总额计算")
            {
            this->hide();
            q->show();
        }
    });
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString  x,y;
        double mi,da,zon;
        x=ui->lineEdit_2->text();
        y=ui->lineEdit_3->text();
        mi=x.toDouble();
        da=y.toDouble();
        zon=mi*da;
        qDebug()<<zon;
       double ti;
       ti=(25-ui->comboBox3->currentIndex()) *12;
       qDebug()<<ti;
        double ba;
        ba=(ui->comboBox2->currentIndex()+4)*0.5;
        qDebug()<<ba;
        ba=ba*0.1;
        double li;
        li=ui->doubleSpinBox->value();
        li=(li*0.01)/12;
        qDebug()<<li;
        double hu;
        double shou;
        double zone;
        double zoli;
        shou=zon*(1-ba);
        zone=zon-shou;
        if(ui->radioButton->isChecked()==true)
          {
            double m;
            m=1+li;
            for(int i=1;i<ti;i++)
            {
                m=m*(1+li);
            }

            hu=zone*((li*m)/(m-1));
            zoli=hu*ti-zone;
            double zohu;
            zohu=hu*ti;
            ui->label_12->setText("首付：");
            ui->label_13->setNum(shou);
            ui->label_14->setText("元");
            ui->label_15->setText("首月月供：");
            ui->label_16->setNum(qRound(hu));
            ui->label_17->setText("元");
            ui->label_18->setText("贷款总额：");
            ui->label_19->setNum(zone);
            ui->label_20->setText("元");
            ui->label_21->setText("支付利息：");
            ui->label_22->setNum(qRound(zoli));
            ui->label_23->setText("元");
            ui->label_24->setText("还款总额：");
            ui->label_25->setNum(qRound(zohu));
            ui->label_26->setText("元");
            ui->label_27->setText("还款月数：");
            ui->label_28->setNum(ti);
            ui->label_29->setText("个月");

            qDebug()<<"首付："<<shou<<"元";
            qDebug()<<"每月月供："<<qRound(hu)<<"元";
            qDebug()<<"贷款总额："<<zone<<"元";
            qDebug()<<"支付利息："<<qRound(zoli)<<"元";
            qDebug()<<"还款总额："<<qRound(zohu)<<"元";
            qDebug()<<"还款月数："<<ti<<"个月";
        }
        if(ui->radioButton_2->isChecked()==true)
        {
            double p;
            p=zone/ti;
            double di;
            di=p*li;
            hu=p+zone*li;
            double zodi;
            for(int i=1;i<ti;i++)
            {
                zodi=zodi+di*i;
            }
            double zoli;
            zoli=zone*li*ti-zodi;
            double zohu;
            zohu=zoli+zone;
            ui->label_12->setText("首付");
            ui->label_13->setNum(shou);
            ui->label_14->setText("元");
            ui->label_15->setText("首月月供：");
            ui->label_16->setNum(qRound(hu));
            ui->label_17->setText("元");
            ui->label_18->setText("每月递减：");
            ui->label_19->setNum(qRound(di));
            ui->label_20->setText("元");
            ui->label_21->setText("贷款总额：");
            ui->label_22->setNum(zone);
            ui->label_23->setText("元");
            ui->label_24->setText("支付利息：");
            ui->label_25->setNum(qRound(zoli));
            ui->label_26->setText("元");
            ui->label_27->setText("还款总额：");
            ui->label_28->setNum(qRound(zohu));
            ui->label_29->setText("元");
            ui->label_30->setText("还款月数：");
            ui->label_31->setNum(ti);
            ui->label_32->setText("个月");
            qDebug()<<"首付："<<shou<<"元";
            qDebug()<<"首月月供："<<qRound(hu)<<"元";
            qDebug()<<"每月递减："<<qRound(di)<<"元";
            qDebug()<<"贷款总额："<<zone<<"元";
            qDebug()<<"支付利息："<<qRound(zoli)<<"元";
            qDebug()<<"还款总额："<<qRound(zohu)<<"元";
            qDebug()<<"还款月数："<<ti<<"个月";
        }
    });
//    double i=1.634,j;
//    j=qRound(i);
//    QString b;
//    b=QString::number(j,10,0);
//    QStringList list;
    //ui->listWidget->setViewMode(QListView::IconMode);
   // ui->listWidget->setFlow(QListView::TopToBottom);
    //list<<"shouuf"<<b;
   //ui->listWidget->addItems(list);
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->comboBox2->setCurrentIndex(8);
        ui->comboBox3->setCurrentIndex(0);
        ui->doubleSpinBox->setValue(0.00);
        ui->radioButton->setChecked(true);
    });
}
Widget::~Widget()
{
    delete ui;
}
void  Widget::showmain1()
{
    this->show();
    zu->hide();

    ui->comboBox1->setCurrentIndex(0);
  //  qDebug()<<"yongle";
}
void  Widget::showmain2()
{
    this->show();
    zu->hide();
    ui->comboBox1->setCurrentIndex(1);
}
void Widget::showmian()
{
    this->show();
    q->hide();
    ui->comboBox4->setCurrentIndex(0);
}
void Widget::showzu()
{
    zu->show();
    q->hide();
}
void Widget:: paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

     pix.load(":/imi/52.jpg");

    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
