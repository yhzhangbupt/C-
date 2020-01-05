#ifndef MINER_H
#define MINER_H

#include "map.h"
#include<QKeyEvent>
#include <QWidget>
#include <QtGui>
class Miner
{
private:
    int angle;//钩子当前角度
    int shifty_angle;//钩子当前变化的角度
    int speed;//钩子当前速度
    double length;//钩子当前长度
    double remain_length;//钩子减少的长度
    int sum;//分数总和
    bool is_rotating;//钩子是否旋转
    bool is_grab;//钩子是否抓取
    bool is_stopped;//钩子是否停止
    bool is_switchAct2;//矿工是否切换
    const double rad=180/3.1415926;//弧度

public:
    Miner();//初始化矿工
    void set_speed(int _speed);//设置钩子当前速度
    void set_length(int _length);//设置钩子当前长度
    void set_sum(int _sum);
    void set_remain_length(int _length);//设置钩子当前将变化的长度
    void set_isrotating(bool _isrotating);//设置钩子是否旋转
    void set_isgrab(bool _isgrab);//设置钩子是否抓取到物体
    void set_isstopped(bool _isstopeed);//设置钩子是否停止
    //void set_isminerout(bool _isminerout);//设置钩子是否越界
    int get_speed(){return speed;}//得到钩子速度
    int get_angle(){return angle;}//得到钩子角度
    double get_length(){return length;}//得到钩子长度
    double get_remain_length(){return remain_length;}//得到钩子将变化的长度
    int get_sum(){return sum;}//得到钩子当前分数总和
    bool get_isrotating(){return is_rotating;}//得到钩子是否旋转
    bool get_isgrab(){return is_grab;}//得到钩子是否抓取
    bool get_isstopped(){return is_stopped;}//得到钩子是否停止
    bool get_isswitch(){is_switchAct2=!is_switchAct2;
        return is_switchAct2;}//得到钩子是否切换
    //bool get_isminerout(){return is_minerout;}//得到钩子是否越界
    bool miner_outdec(Map *m);//钩子碰撞和越界检测
    void change_angle(int _angle);//改变钩子角度
    void change_remain_length(double _length);//改变钩子将变化的长度
    void change_length(double _length);//改变钩子长度
    void change_sum(int _sum);//改变分数总和
    void miner_init();//矿工信息初始化
   //void paintEvent(QPaintEvent *);//画绳子

    void miner_rotate();//当钩子正在旋转时旋转钩子
    void miner_retreve(Map *m);//当钩子没有旋转且抓取到物品时，或者矿工没有旋转且越界时，钩子回撤，画绳子
    //void miner_switchAct2();//当矿工没有旋转时，切换矿工动作
    //void miner_drawline();//当矿工没有旋转时，没有越界，也没有抓取到物品时，钩子下放，画绳子
};

#endif // MINER_H
