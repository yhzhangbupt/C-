#ifndef MAP_H
#define MAP_H

#include"item.h"
#include<QPoint>
#include<stdlib.h>
#include<cstdlib>
#include<time.h>
class Map
{
private:
    int count;
    Item *item[16];//宝箱，石头
    Item *goods[16];//物资
    int  cur_item=0;//当前物体编号
    int cur_goods=0;//
    int  item_sum;//这一关物体总数（第一关为11，第二关为13，第三关为16）
public:
    Map();//调用init（）函数初始化地图界面
    int getCurNumber(){return cur_item;} //获取当前物体编号
    int getCurGoods(){return cur_goods;}//获取当前物资编号
    int getCurSpeed(){return item[cur_item]->getSpeed();}//获取当前物体的速度
    int getCurPrice(){return item[cur_item]->getPrice();}//获取当前物体的价格
    //int getCurSize(){return item[cur_item]->;}//获取当前物体的体积
    int getCurWidth(){return item[cur_item]->getWidth();}
    int getCurHeight(){return item[cur_item]->getHeight();}
    QPoint getCurPoint(const int &i);//获取第i个物体的坐标
    bool getVisible(const int &i);//查看第i个物体是否可见
    bool getGoodsVisible(const int &i){return goods[i]->isVisible();}//查看第i个物资是否可见
    int getSpeed(const int &i){return item[i]->getSpeed();}
    int getX(const int &i){return item[i]->getX();}
    int getY(const int &i){return item[i]->getY();}
    int getPrice(const int &i){return item[i]->getPrice();}
    int getWidth(const int &i){return item[i]->getWidth();}
    int getHeight(const int &i){return item[i]->getHeight();}
    int getItemSum(){return item_sum;}
    void SetInvisible(int j);
    void setGoodsVisible(const int &i,bool b);//设置第i个物资是否可见
    bool isDetection(const int &x,const int &y);//是否碰撞
    bool is_overlap(); //是否重叠
    void disappear();  //物体到达原点后消失
    void map_init(const int &i);   //随机生成宝箱，石头
    void map_goods();  //随机控制宝箱出现的物质
    QPoint map_move(int &angle,double remain_length);//移动坐标
    void drawLevel(const int &i);//确定关数
};

#endif // MAP_H
