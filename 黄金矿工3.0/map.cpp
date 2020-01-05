#include "map.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

int j=0;
const double rad=180/3.1415926;//弧度

Map::Map()
{

  for(int i=0;i<=15;i++)//宝箱和石头
      item[i]=new Item;
  for(j=0;j<=15;j++)//物资
  {
      goods[j]=new Item;
      goods[j]->setInvisible();
  }
  cur_item=0;
  item_sum=11;
  count=0;
  cur_goods=0;
}

QPoint Map::getCurPoint(const int &i)//获取第i个物体的坐标
{
   QPoint p(item[i]->getX(),item[i]->getY()) ;
   return p;
}

bool Map::getVisible(const int &i)//查看第i个物体是否可见
{
    return item[i]->isVisible();
}
void Map::SetInvisible(int j)
{
    item[j]->setInvisible();
}
void Map::drawLevel(const int &i)//判断关数，确定宝箱和盒子数目
{
    if(i==1)
    {
        item_sum=11;//第一关
    }
    else if(i==2)
        item_sum=13;//第二关
    else if(i==3)
        item_sum=16;//第三关
    else
        item_sum=11;//默认第一关
    for (j=0;j<item_sum;j++)
    {
        item[j]->setVisible();
    }
}

bool Map::isDetection(const int &x, const int &y)//碰撞检测
{
    for(int i=0;i<item_sum;i++)
    {
        if(item[i]->detection(x,y))//如果碰到了任意一个物体,x,y指的是钩子的坐标
        {
            cur_item=i;
            return true;
         }


    }
    return false;
}

void Map::disappear()//让当前物体到达中心点时不见，同时随时出现物资
{
    item[cur_item]->setInvisible();
    map_goods();
}

bool Map::is_overlap()//判断是否重叠
{
    int minWidth=120;
    int minHigth=120;
    bool flag=true;
    for(int i=count-1;i>=0;i--)
    {
        if(abs(item[count]->getX()-item[i]->getX())-minWidth<=0&&
                abs(item[count]->getY()-item[i]->getY())-minHigth<=0)
           {flag=false;}
        else
           {flag=true;}


        if(flag==false)
            break;

    }
    return flag;
}

void Map::setGoodsVisible(const int &i,bool b)
{
    if (b)
        goods[i]->setVisible();
    else
        goods[i]->setInvisible();
}

void Map::map_init(const int &i)//随机生成宝箱，石头位置
{
    count=i;
    int w=abs(50+qrand()%800);
    int h=210+abs(qrand()%640);
    item[i]->setPosition(w,h);

        //检测是否重叠，如果重叠，就再次生成，如果没有重叠，就直接放置
    if((is_overlap())==true)
    {
        if(i<2)//大箱子0,1
        {
           if (item_sum==11)
           {
             item[i]->setSize(120,80);
             item[i]->setPrice(100);
             item[i]->setSpeed(-1);
           }
           if (item_sum==13)
           {
               if (h>320)
               {
                 item[i]->setSize(120,80);
                 item[i]->setPrice(100);
                 item[i]->setSpeed(-1);
               }
               else
                   map_init(i);
           }
           if (item_sum==16)
           {
               if (h>450)
               {
                   item[i]->setSize(120,80);
                   item[i]->setPrice(100);
                   item[i]->setSpeed(-1);
               }
               else
                   map_init(i);
           }
        }
        else if(i>=2&&i<5)//小箱子2,3,4
        {
            item[i]->setSize(90,60);
            item[i]->setPrice(50);
            item[i]->setSpeed(-2.5);
        }
        else if(i==5)//随机箱子5
        {
            item[i]->setSize(80,80);
            item[i]->setPrice(80);
            item[i]->setSpeed(-2);
        }
        else if(i==6)//大石头6
        {
            item[i]->setSize(150,150);
            item[i]->setPrice(20);
            item[i]->setSpeed(-1);
        }
        else if(i>6&&i<=10)//小石头7,8,9,10
        {
            item[i]->setSize(80,80);
            item[i]->setPrice(10);
            item[i]->setSpeed(-2);
        }
        else if(i>10&&i<=12)//大石头，11,12
        {
            item[i]->setSize(150,150);
            item[i]->setPrice(20);
            item[i]->setSpeed(-1);
        }
        else //小石头，13,14,15
        {
            item[i]->setSize(80,80);
            item[i]->setPrice(10);
            item[i]->setSpeed(-2);
        }
     }
     else
     {
        map_init(i);
     }
}

void Map::map_goods()//随机生成物资
{
    //sqrand(time(NULL));
    //知道宝盒的种类，随机生成物资
    if(cur_item>=0&&cur_item<6)//即如果抓上来的东西是宝箱，则会有物资出现
    {
      if(cur_item==0||cur_item==1)//0,1
      {
        goods[0]->setVisible();
        cur_goods=0;
      }
      else if(cur_item>1&&cur_item<5)//2,3,4
      {
        j=1+qrand()%6;
        goods[j]->setVisible();
        cur_goods=j;
      }
      else
      {
        j=7+qrand()%9;
        goods[j]->setVisible();
        cur_goods=j;
      }
    }
}

QPoint Map::map_move(int &angle,double remain_length)//宝箱和石头的运动
{
      QPoint p(item[cur_item]->getX(),item[cur_item]->getY());
      QPoint temp(remain_length*sin(angle/rad),-remain_length*cos(angle/rad));
      return (p+temp);
      //label[cur_item]->move((p+temp));
}
