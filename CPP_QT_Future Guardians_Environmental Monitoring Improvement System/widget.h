#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QProcess>
#include<QMessageBox>
#include<QPainter>
#include<QTimer>
#include<QTime>

//QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
//QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent * event);

    QTimer timer;
    QTime time;

private slots:
    void on_solutionButton_clicked();

    void on_cancelButton_clicked();

    void on_AIButton_clicked();

    void update_time();

    void timeout_slot();

    void on_pushButton_2_clicked();

    void on_detaillocationButton_clicked();

private:
    Ui::Widget *ui;
    QTimer *mtimer;
};
#endif // WIDGET_H
