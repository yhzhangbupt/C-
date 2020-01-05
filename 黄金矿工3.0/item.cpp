#include "item.h"
#include<QDebug>
#include"math.h"

Item::Item()
{
    visible=false;
}

void Item::setPosition(const int &X, const int &Y)
{
    x=X;
    y=Y;
}
void Item::setSize(const int &wwidth, const int &hheight)
{
    width=wwidth;
    height=hheight;
}
void Item::setPrice(const int &pprice)
{
    price=pprice;
}
void Item::setSpeed(const double &sspeed)
{
    speed=sspeed;
}
/*void item::setKind(const int &kkind)
{
    kind=kkind;
}*/

void Item::setVisible()//设置为可见
{
    visible=true;
}


void Item::init()//初始化
{
    x=y=height=width=kind=0;
    visible=true;
}

bool Item::detection(const int &X,const int &Y)//item碰撞检测
{
    //if(visible==true&&X>x+5&&X<(x+width-5)&&Y>y+2&&Y<(y+height-5))//+5、-5是为了缩小碰撞检测范围
    //return true;
    double xx,yy;
    xx=x+width/2;
    yy=y+height/2;
    double len;
    double lent;
    lent=pow((height/2),2)+pow((width/2),2);
    len=pow((X-xx),2)+pow((Y-yy),2);
    if(visible==true&&sqrt(len)<=sqrt(lent))
        return true;
    else
        return false;
}

void Item::setInvisible()//设置为不可见
{
    visible=false;
}
