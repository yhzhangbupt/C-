#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<math.h>
#include <iostream>

//#include<cstdlib>
#include<time.h>
#include <stdlib.h>
//#include <stdio.h>
#include <QMovie>
#include<QDebug>
#include<QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i=0;i<3;i++)
        now_sum[i]=0;

    setFixedSize(1000,1000);
    player=new QMediaPlayer(this);
    videoWidget=new QVideoWidget(this);
    videoWidget->setGeometry(0,100,1000,800);
    player->setVideoOutput(videoWidget);
    player->setVolume(50);
    QDir dir;
    player->setMedia(QUrl::fromLocalFile(dir.currentPath()+"/vedioandmusic/video.mov"));

    player->play();

    connect(player,&QMediaPlayer::mediaStatusChanged,
          this,&MainWindow::mediaStatusChanged);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    player2=new QMediaPlayer;

    this->setWindowTitle("绝地寻宝");
    this->setStyleSheet("#MainWindow{border-image:url(:/pie/picturesource/truebk.jpg);}");

    //设置显示字体颜色
    QPalette pal;
    pal.setColor(QPalette::WindowText, Qt::white);
    ui->label_goal->setPalette(pal);//游戏目标分数界面的目标分数
    //ui->label_goalsco->setPalette(pal);//游戏进行中的目标分数
    ui->label_now->setPalette(pal);
    pal.setColor(QPalette::WindowText, Qt::red);
    ui->label_level->setPalette(pal);//游戏关卡数
  //  pal.setColor(QPalette::WindowText, Qt::black);
  //  ui->label_time->setPalette(pal);

    pix.load(":/pie/picturesource/hook1.png");//设置钩子
    //srand(time(NULL));
    interval_angle=15;
    interval_miner=200;

    goal[0]=400;
    goal[1]=750;
    goal[2]=1000;//目标分数

    miner=new Miner;
    map=new Map;

    /*setGoods.setInterval(1000);
    connect(&setGoods,&QTimer::timeout,this,&MainWindow::stop);*/

    timer_angle.setInterval(interval_angle);//设置触发间隔为15ms
    connect(&timer_angle,&QTimer::timeout,this,&MainWindow::rotate);
    connect(&timer_angle,&QTimer::timeout,this,&MainWindow::ss);

    timer_s.setInterval(interval_miner);//s控制矿工的运动
    connect(&timer_s,&QTimer::timeout,this,&MainWindow::mm);

    timer_clock.setInterval(1000);
    connect(&timer_clock,&QTimer::timeout,this,&MainWindow::timereduce);

    rad=180/3.1415926;//弧度
    //angle_change=1;//角度转变量为1°

    lable[0]=ui->label_big1;lable[1]=ui->label_big2;//大箱
    lable[2]=ui->label_small1;lable[3]=ui->label_small2;lable[4]=ui->label_small3;//小箱
    lable[5]=ui->label_unkown;//未知
    lable[6]=ui->label_bigst1;//第一关大石头
    lable[7]=ui->label_smast1;lable[8]=ui->label_smast2;lable[9]=ui->label_smast3;lable[10]=ui->label_smast4;//第一关小石头
    lable[11]=ui->label_bigst2;lable[12]=ui->label_bigst3;//第二关新增大石头
    lable[13]=ui->label_smast5;lable[14]=ui->label_smast6;lable[15]=ui->label_smast7;//第三关新增小石头

    goods[0]=ui->label_mage;goods[1]=ui->label_9mm;
    goods[2]=ui->label_556mm;goods[3]=ui->label_762mm;
    goods[4]=ui->label_45;goods[5]=ui->label_jian;
    goods[6]=ui->label_sandan;goods[7]=ui->label_eight;
    goods[8]=ui->label_hospital;goods[9]=ui->label_secret;
    goods[10]=ui->label_bengdai;goods[11]=ui->label_drinking;
    goods[12]=ui->label_zhitong;goods[13]=ui->label_baodan;
    goods[14]=ui->label_yandan;goods[15]=ui->label_shoudan;
    for (int i=0;i<16;i++)
        goods[i]->setGeometry(650,20,158,180);

    clean();
    ui->label_beginb->setVisible(true);
    ui->label_beginb->move(0,0);
    //ui->label_beginb->resize(1000,1000);
    ui->button_start->setVisible(true);
    boommovie=new QMovie(":/pie/picturesource/bao2.gif");
    boommovie->setScaledSize(QSize(300,300));
    ui->label->setMovie(boommovie);
    ui->label->resize(500,500);
    ui->label->move(0,0);
    ui->label->setVisible(false);
}

void MainWindow::yanhua(int X,int Y)
{
    boommovie=new QMovie(":/pie/picturesource/bao2.gif");
    boommovie->setScaledSize(QSize(300,300));
    ui->label->setMovie(boommovie);
    ui->label->resize(500,500);
    ui->label->move(X-100,Y-300);
    ui->label->setVisible(true);
    boommovie->start();
    QTimer::singleShot(1200,this, stopYanhua);
    QDir dir;
    player2->setMedia(QUrl::fromLocalFile(dir.currentPath()+"/vedioandmusic/9882.mp3"));
    //player2->setMedia(QUrl::fromLocalFile("D:/Helo/sucess1.0/vedioandmusic/9882.mp3"));
    player2->setVolume(80);
    player2->play();

}
void MainWindow::mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if(status==QMediaPlayer::EndOfMedia)
    {
        //player->stop();
       delete player;
       delete videoWidget;
       ui->pushButton->setVisible(false);
    }
}
void MainWindow::boom()
{
    int x,y,a,b,num;
    num=map->getCurNumber();
    x=map->getX(num);
    y=map->getY(num);
    for(int i=0;i<map->getItemSum();i++)
    {
        if(num==i)
            continue;
        a=map->getX(i);
        b=map->getY(i);
        if((x-a)*(x-a)+(y-b)*(y-b)<=100000)
        {
            map->SetInvisible(i);
        }
    }
    map->SetInvisible(num);
    int rlength=miner->get_remain_length();
    int angle=miner->get_angle();
    QPoint nowpot(map->map_move(angle,rlength));
    yanhua(nowpot.x(),nowpot.y());
}
void MainWindow::stopYanhua()
{
    ui->label->setVisible(false);
    //delete player2;
}
void MainWindow::stop()
{
    map->setGoodsVisible(map->getCurGoods(),false);
    goods[map->getCurGoods()]->setVisible(false);
    //setGoods.stop();
}
void MainWindow::initbefore()//进入游戏前界面
{
    clean();
    ui->label_before->setVisible(true);
    ui->label_goal->setVisible(true);
    ui->button_game->setVisible(true);
    ui->label_now->setVisible(true);
    ui->label_goal->move(523,561);
    ui->label_now->move(523,653);
    QString sow = QString::number(goal[level-1], 10);
    ui->label_goal->display(sow);
    QString so=QString::number(0);
    ui->label_now->display(so);
   // ui->label_goal->setText(so);
}

void MainWindow::init()//初始化游戏界面
{
    clean();
    ui->label_2->setVisible(true);
    timesboom=1;
    ui->button_pause->setVisible(true);
  //  QString s = QString::number(miner->get_sum(), 10);
  //  ui->label_nowsco->setText(s);
    QString so = QString::number(goal[level-1], 10);
    ui->lcd_goalsco->display(so);
    //ui->label_goalsco->setText(so);
    QString l = QString::number(level, 10);
    ui->label_level->display(l);
    ui->toolButton->setStyleSheet("#toolButton{border-image:url(:/pie/picturesource/people1.png);}");//设置矿工

    time_left=60;//剩余时间为60s
     map->drawLevel(level);
     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
     for (int i=0;i<map->getItemSum();i++)
         map->map_init(i);

     for (int i=0;i<map->getItemSum();i++)
     {
       lable[i]->setVisible(true);
       lable[i]->move(map->getCurPoint(i));
       lable[i]->resize(map->getWidth(i),map->getHeight(i));
     }
     for (int i=0;i<map->getItemSum();i++)
     {
         std::cout << "lable " << i << " "<< map->getVisible(i)<<std::endl;
     }
    ui->lcd_time->display(time_left);
    ui->lcd_nowsco->display(miner->get_sum());
    timer_angle.start();
    timer_clock.start();
    timer_s.start();
}

void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.translate(500,200); //让图片的中心作为旋转的中心
    painter.rotate(miner->get_angle()); //顺时针旋转90度
    painter.translate(-500,-200); //使原点复原

    int length=miner->get_length();
    if(!miner->get_isrotating()||miner->get_isstopped())
    {
        QPen pen;
        pen.setWidth(0.5);
        pen.setColor(800000);
        painter.setPen(pen);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.drawLine(500,195,500,195+length);
        painter.drawPixmap(470,195+length,pix);//绘图的起点
    }
    else
       painter.drawPixmap(470,195,pix);//绘图的起点
    if (!ui->button_start->isVisible())
        update();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    int key=e->key();
    if (!miner->get_isstopped()&& key ==Qt::Key_0) // 没有暂停并按向下方向键时
    {
        if(miner->get_isrotating())//如果正在旋转
        {
            //停止旋转，进行下拉操作
            miner->set_isrotating(false);
        }
    }
    if(key==Qt::Key_1)//暂停功能
    {
        if(miner->get_isstopped()&&time_left>0)
            resume();
        else
            do_stop();
    }
    if(miner->get_isgrab()&&key==Qt::Key_2)
    {
        if (timesboom>0)
        {
          //int x,y,num;
          //num=map->getCurNumber();
          int rlength=miner->get_remain_length();
          int angle=miner->get_angle();
          QPoint nowpot(map->map_move(angle,rlength));
          //x=map->getX(num);
          //y=map->getY(num);
          //yanhua(x,y);
          yanhua(nowpot.x(),nowpot.y());
          map->SetInvisible(map->getCurNumber());
          miner->set_remain_length(0);
          miner->set_isgrab(false);
          miner->set_speed(-7);
          timesboom--;
          ui->label_2->setVisible(false);
        }
     }
}

/*bool MainWindow::detection()//碰撞和越界检测
{
    return ...
}*/

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::do_stop()
{
    if(time_left>0){
        ui->button_pause->setVisible(false);//暂停图案
        ui->button_resume->setVisible(true);
    }
    miner->set_isrotating(!(miner->get_isrotating()));
    timer_clock.stop();
    timer_angle.stop();
    timer_s.stop();
    miner->set_isstopped(true);
}
void MainWindow::resume()
{
    ui->button_resume->setVisible(false);//暂停图案
    ui->button_pause->setVisible(true);

    miner->set_isrotating(!(miner->get_isrotating()));
    timer_clock.start();
    timer_angle.start();
    timer_s.start();
    miner->set_isstopped(false);
}
void MainWindow::timereduce()//计时器
{
    if(time_left>=0)
    {
        ui->lcd_time->display(time_left--);
    }
    if(time_left<0)//剩余时间为0，则停止游戏
    {
        do_stop();
        if(miner->get_sum()>=goal[level-1]&&level<3)//过关
        {
          clean();
          QDir dir;
          player2->setMedia(QUrl::fromLocalFile(dir.currentPath()+"/vedioandmusic/7774.wav"));
          //player2->setMedia(QUrl::fromLocalFile("D:/Helo/sucess1.0/vedioandmusic/7774.wav"));
          player2->setVolume(80);
          player2->play();
          ui->label_guobac->setVisible(true);
          ui->button_next->setVisible(true);
          ui->button_exit->setVisible(true);
          ui->label_goal->setVisible(true);
          ui->label_now->setVisible(true);
          ui->label_goal->move(540,330);
          ui->label_now->move(540,422);
          QString s = QString::number(miner->get_sum(), 10);
          ui->label_now->display(s);
          QString so = QString::number(goal[level-1], 10);
          ui->label_goal->display(so);
        }
        else if(miner->get_sum()>=goal[level-1]&&level==3){
            QDir dir;
            player2->setMedia(QUrl::fromLocalFile(dir.currentPath()+"/vedioandmusic/4667.mp3"));
            //player2->setMedia(QUrl::fromLocalFile("D:/Helo/sucess1.0/vedioandmusic/4667.mp3"));
            player2->play();
            ui->label_tong->setVisible(true);
            ui->button_restart->setVisible(true);
            ui->button_exit->setVisible(true);
            ui->label_now->setVisible(true);
             ui->label_now->move(540,422);
             QString s = QString::number(miner->get_sum(), 10);
             ui->label_now->display(s);
        }
        else {
            QDir dir;
            player2->setMedia(QUrl::fromLocalFile(dir.currentPath()+"/vedioandmusic/1756.mp3"));
            //player2->setMedia(QUrl::fromLocalFile("D:/Helo/sucess1.0/vedioandmusic/1756.mp3"));
            player->setVolume(80);
            player2->play();
            ui->label_lose->setVisible(true);
            ui->button_restart->setVisible(true);
            ui->button_exit->setVisible(true);
            ui->label_now->setVisible(true);
            ui->label_now->move(540,422);
            QString s = QString::number(miner->get_sum(), 10);
            ui->label_now->display(s);
        }
    }
}

void MainWindow::rotate()//控制旋转
{
    /*if(miner->isrotating())//旋转时
    {
        miner->change_angle(angle_change);
        int angle=miner->get_angle();
        if(angle>=90||angle<=-90)
            angle_change*=-1;
    }*/
    miner->miner_rotate();
    if (!ui->button_start->isVisible())
        update();
}
void MainWindow::mm()//矿工动作设置
{
    if(!miner->get_isrotating())
    {
        if(miner->get_isswitch())//矿工的动作设置
            ui->toolButton->setStyleSheet("#toolButton{border-image:url(:/pie/picturesource/people1.png);}");
        else
            ui->toolButton->setStyleSheet("#toolButton{border-image:url(:/pie/picturesource/people3.png);}");
    }

}
void MainWindow::ss()//伸展操作
{
    if(!miner->get_isrotating())//当钩子不旋转
    {
        if(miner->get_isgrab())//抓住后物体的移动
        {
            if(!flag)
            {
                //player3->play();
                int choice;
                choice=map->getCurNumber();
                if(choice==0||choice==1)
                {
                    QDir dir;
                    player2->setMedia(QUrl::fromLocalFile(dir.currentPath()+"/vedioandmusic/8807.wav"));
                   // player2->setMedia(QUrl::fromLocalFile("D:/Helo/sucess1.0/vedioandmusic/8807.wav"));
                    player2->setVolume(80);

                    player2->play();
                }
                if(choice==2||choice==3||choice==4)
                {
                    QDir dir;
                    player2->setMedia(QUrl::fromLocalFile(dir.currentPath()+"/vedioandmusic/6416.mp3"));
                    //player2->setMedia(QUrl::fromLocalFile("D:/Helo/sucess1.0/vedioandmusic/6416.mp3"));
                    player2->setVolume(80);

                    player2->play();
                }
                if(choice==5)
                {
                    QDir dir;
                    player2->setMedia(QUrl::fromLocalFile(dir.currentPath()+"/vedioandmusic/9266.mp3"));
                    //player2->setMedia(QUrl::fromLocalFile("D:/Helo/sucess1.0/vedioandmusic/9266.mp3"));
                    player2->setVolume(80);
                    player2->play();
                }
                flag=true;
            }
            if(miner->get_length()<=0)
                flag=false;
            if(map->getCurNumber()==15){
                boom();
                miner->set_isgrab(false);
                miner->set_speed(-7);}
            miner->change_remain_length(fabs(miner->get_speed()));
            int rlength=miner->get_remain_length();
            int angle=miner->get_angle();

            lable[map->getCurNumber()]->move(map->map_move(angle,rlength));
        }
        if(miner->get_length()<=0)
            flag=false;
        miner->miner_retreve(map);//当钩子没有旋转且抓取到物品时，或者矿工没有旋转且越界时，钩子回撤，画绳子，回到原点时令当前物体不可见，当前物品属性设为不可见物资设属性为可见

        if (!map->getVisible(map->getCurNumber()))//当前物品属性为不可见的时候
                {
                    lable[map->getCurNumber()]->setVisible(false);//隐藏物体
                    if (map->getGoodsVisible(map->getCurGoods()))//物资属性为可见时
                        {goods[map->getCurGoods()]->setVisible(true);
                     QTimer::singleShot(1000,this, stop);}
                }
        for (int i=0;i<map->getItemSum();i++){
            if (!map->getVisible(i))
            {
                lable[i]->setVisible(false);

            }}

    }
    ui->lcd_nowsco->display(miner->get_sum());
    if (!ui->button_start->isVisible())
        update();
}
void MainWindow::on_button_reset_clicked(){
    miner->miner_init();
    if (level==1)
        miner->set_sum(0);
    else
        miner->set_sum(now_sum[level-2]);
    init();
}
void MainWindow::on_button_game_clicked(){
    init();
}
void MainWindow::on_button_pause_clicked(){
    do_stop();
}
void MainWindow::on_button_resume_clicked(){
        ui->button_resume->setVisible(false);//暂停图案
        ui->button_pause->setVisible(true);

        miner->set_isrotating(!(miner->get_isrotating()));
        timer_clock.start();
        timer_angle.start();
        timer_s.start();
        miner->set_isstopped(false);

}
void MainWindow::on_button_restart_clicked(){
   level=1;
   initbefore();
   miner->miner_init();
}
void MainWindow::on_button_exit_clicked(){
    qApp->quit();
}
void MainWindow::on_button_next_clicked(){
    now_sum[level-1]=miner->get_sum();
    miner->miner_init();
    miner->set_sum(now_sum[level-1]);
    level++;
    init();
}

void MainWindow::on_button_start_clicked(){
    initbefore();
}

void MainWindow::clean()
{
    ui->button_exit->setVisible(false);
    ui->button_game->setVisible(false);
    ui->button_next->setVisible(false);
    ui->button_pause->setVisible(false);
    ui->label_lose->setVisible(false);
    //ui->button_reset->setVisible(false);
    ui->button_restart->setVisible(false);
    ui->button_resume->setVisible(false);
    ui->button_start->setVisible(false);
    ui->label_before->setVisible(false);
    ui->label_beginb->setVisible(false);
    ui->label_goal->setVisible(false);
    ui->label_guobac->setVisible(false);
    ui->label_now->setVisible(false);
    ui->label_tong->setVisible(false);
    ui->label_2->setVisible(false);
    for (int i=0;i<16;i++)
        goods[i]->setVisible(false);
    for (int i=0;i<16;i++)
        lable[i]->setVisible(false);
}

void MainWindow::on_pushButton_clicked()
{
   player->stop();
   videoWidget->close();
   ui->pushButton->setVisible(false);
}
