
#ifndef ITEM_H
#define ITEM_H
class Item
{
private:
    int x,y;        //物体坐标
    int height,width;
    int price;
    int kind;       //物体加减速类型
    double speed;   //钩子运行速度
    bool  visible;  //是否可见
public:
    Item();
    void setPosition(const int &X,const int &Y);//设置中心位置
    void setSize(const int &Width,const int &Height);
    void setPrice(const int &Price);
    void setSpeed(const double &Speed);
    //void setKind(const int &Kind);
    void setVisible();                 //设置是否可见
    //int getKind(){return kind;}        //获得物体类型
    int getPrice(){return price;}      //获得物体价值
    int getX(){return x;}              //获得物体位置
    int getY(){return y;}
    int getWidth(){return width;}
    int getHeight(){return height;}
    double getSpeed(){return speed;}   //获得物体速度
    bool isVisible(){return visible;} //获得物体是否可见信息
    void setInvisible();

    void init();                       //初始化

    bool detection(const int &X,const int &Y);//碰撞检测

};

#endif // ITEM_H
