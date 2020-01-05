#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <time.h>
#include <QTime>
#include <stdlib.h>
#include<QtGui>
#include<QLabel>
#include<QTimer>
#include<QKeyEvent>
#include <QtGlobal>
#include<QMediaPlayer>
#include<QVideoWidget>
#include <QMovie>
#include "miner.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void boom();
    void music();//碰撞音效
    //bool detection();//碰撞检测， 判断是否碰到物体
    void clean();
    void do_stop();
    void resume();
    void initbefore();//初始化
    void init();
    void yanhua(int X,int Y);//播放烟花特效
    ~MainWindow();
    int timesboom=0;//可以放置炸弹的次数
    int level=1;
    int goal[3];
    int now_sum[3];
    bool flag=false;//碰撞音效开关
private:
    Ui::MainWindow *ui;
     QPixmap pix;
     QImage hook;
     QMovie * boommovie;
     QMediaPlayer *player;//视频播放
     QMediaPlayer *player2;//爆炸音效
     QVideoWidget *videoWidget;


     int cur_item;
     double rad;//表示1弧度=多少度
     //int angle_change;
     //int k;//表示倍数

     Miner *miner;
     Map *map;

     //计时器
     QTimer timer_angle,timer_clock,timer_s;
     //QTimer setGoods;
     int interval_angle,interval_miner;
     int time_left;
     int time;//表示已经进行了多久，每10秒随机产生一次矿石

     QLabel *lable[16];//宝箱：0，1->大型；2，3，4->小型；5->未知；
     //6->第一关大型石头；7，8，9，10->第一关小型石头
     //11，12->第二关新增大型石头；13，14，15->第二关小型石头

     QLabel *goods[15];

private slots:

    void mediaStatusChanged(QMediaPlayer::MediaStatus status);
    void timereduce();//倒计时
    void rotate();//旋转
    void ss();
    void mm();

    void stop();//停止物资图片显示
    void stopYanhua();
    void on_button_reset_clicked();

    void on_button_game_clicked();

    void on_button_resume_clicked();

    void on_button_start_clicked();

    void on_button_pause_clicked();

    void on_button_restart_clicked();

    void on_button_exit_clicked();

    void on_button_next_clicked();


    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
