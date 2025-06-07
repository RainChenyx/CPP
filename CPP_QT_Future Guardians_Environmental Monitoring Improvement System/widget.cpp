#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("未来守护者一体式智能化环境检测改善装置可视化窗口");

    mtimer= new QTimer;
    connect(mtimer,SIGNAL(timeout()),this,SLOT(update_time()));

    connect(ui->solutionButton,&QPushButton::clicked,[this]()
    {
        QMessageBox::information(this,"解决方案","");
    });
    connect(ui->AIButton,&QPushButton::clicked,[this]()
    {
        QMessageBox::information(this,"疑问/客服","400-8888-8888");
    });

    connect(ui->VRButton,&QPushButton::clicked,[this]()
    {
        QMessageBox::information(this,"VR模拟","暂未开发，尽情期待");
    });

    mtimer->start(1000);

    time.setHMS(0,0,0,0);
    ui->startEdit->setText("00:00:00:000");
    connect(&timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));
    timer.start(40);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/fire3.jpg"));
}


void Widget::on_solutionButton_clicked()
{

}


void Widget::on_cancelButton_clicked()
{
    this->close();
}


void Widget::on_AIButton_clicked()
{

}

void Widget::update_time()
{
    QString tm = QTime::currentTime().toString("hh:mm;ss");
//    ui->lcdNumber->display(tm);
    ui->newEdit->setText(tm);
}

void Widget::timeout_slot()
{
   time = time.addMSecs(40);
   ui->startEdit->setText(time.toString("hh:mm:ss.zzz"));
}

void Widget::on_pushButton_2_clicked()
{

}


void Widget::on_detaillocationButton_clicked()
{

}

