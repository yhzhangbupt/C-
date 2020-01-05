#include "miner.h"

Miner::Miner()
{
    miner_init();
}

//关于各项数值的设置
void Miner::set_speed(int _speed)
{
    speed=_speed;
}

void Miner::set_length(int _length)
{
    length=_length;
}

void Miner::set_sum(int _sum)
{
    sum=_sum;
}

void Miner::set_remain_length(int _length)
{
    remain_length=_length;
}

void Miner::set_isrotating(bool _isrotating)
{
    is_rotating=_isrotating;
}

//关于各布尔值的设置
void Miner::set_isgrab(bool _isgrab)
{
    is_grab=_isgrab;
}

void Miner::set_isstopped(bool _isstopeed)
{
    is_stopped=_isstopeed;
}

//关于各项数值的更改
void Miner::change_angle(int _angle)
{
    angle+=_angle;
}

void Miner::change_remain_length(double _length)
{
    remain_length+=_length;
}

void Miner::change_length(double _length)
{
    length+=_length;
}

void Miner::change_sum(int _sum)
{
    sum+=_sum;
}

//初始化
void Miner::miner_init()
{
    angle=0;//起始旋转角度为0
    shifty_angle=1;//初始旋转变化角为1°
    speed=7;//钩子初始速度为4
    length=0;//起始长度为0
    remain_length=0;//起始已减少长度为0
    sum=0;//起始分数为0

    is_rotating=true;//判断是否正在进行旋转
    is_grab=false;//当前没有抓取任何物体
    is_stopped=false;//当前没有停止
    is_switchAct2=true;//不进行切换
}

bool Miner::miner_outdec(Map *m)
{
    //定义临时变量angle和length
    int angle=get_angle();
    int length=get_length();

    if(fabs(angle)>32){
        if(length>(500/(sin(fabs(angle/rad)))))
                 return true;
    }
    else if(length>(800/(cos(angle/rad))))
        return true;//判断是否越界
    if(m->isDetection(500-length*sin(angle/rad),195+length*cos(angle/rad)))//如果map.碰撞检测返回为真
        {
            set_isgrab(true);
            return true;
        }

    return false;
}

void Miner::miner_rotate()
{
    if (is_rotating)
    {
        change_angle(shifty_angle);
        int angle=get_angle();
        if(angle>=90||angle<=-90)
            shifty_angle*=-1;
    }//改变旋转方向
}

void Miner::miner_retreve(Map* m)//按下键就一直会执行的函数
{
    if (is_grab||miner_outdec(m))//判断越界或抓取
    {
        if(is_grab)
         {
            set_speed(m->getCurSpeed());//物品速度记为-x,x为最终速度；
        }
        else
            set_speed(-1*(get_speed()));//速度相反，往反向拉
    }
    change_length(get_speed());//画绳子

    if(get_length()<=0)//如果钩子回到了起点
    {

        if(is_grab)//如果抓到了东西
        {
            m->disappear();//令当前物体不可见，物资设属性为可见
            //label[map->get_cur_item()]->setVisible(false);//令当前物体不可见
            change_sum(m->getCurPrice());
            set_remain_length(0);
            set_isgrab(false);
        }
        set_isrotating(true);
        set_speed(7);
        set_length(0);
    }
}
