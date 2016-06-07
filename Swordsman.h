#include <iostream>
#include<stdlib.h>
#include<time.h>
#include "player.h"
using namespace std;
class Swordsman:public player
{
    public:
        Swordsman(int i,char*cptr);
        void LVup();
        bool attack(player &p);
        bool special(player &p);
        void AI(player &p);
};
Swordsman::Swordsman(int i,char*cptr)
{
    role = sw;
    for(int j = 0;j<10;j++)
        name[j] = cptr[j];
    HP = 150+8*(i-1);
    HPmax = 150+8*(i-1);
    MP = 75+2*(i-1);
    MPmax = 75+2*(i-1);
    AP = 25+4*(i-1);
    DP = 25+4*(i-1);
    speed = 25+2*(i-1);
    LV = i;
    death = 0;
    EXP = LV*LV*75;
    bag.set(i*5,i*5,i*5);
}
void Swordsman::LVup()
{
    if(EXP >= LV*LV*75) {
        LV++;
        AP = AP+4;
        DP = DP+4;
        HPmax = HPmax+8;
        MPmax = MPmax+2;
        speed = speed+2;
        cout<<name<<"升级啦"<<endl;
        cout<<"生命值增加"<<8<<"点"<<endl;
        cout<<"魔法值增加"<<2<<"点"<<endl;
        cout<<"速度增加"<<2<<"点."<<endl;
        cout<<"攻击力增加"<<4<<"点"<<endl;
        cout<<"防御力增加."<<4<<"点"<<endl<<endl;
        LVup();//递归调用，可以连升级
    }
}
bool Swordsman::attack(player &p)
{
    double HPtemp = 0,EXPtemp = 0;//敌方受伤及取经验
    double hit = 1;//致命一击因子;
    srand(time(NULL));//随机数
    if((speed>p.speed)&&(rand()%100<(speed-p.speed)))//两次攻击
    {
        HPtemp = int((1.0*AP/p.DP)*AP*5/(rand()%4+10));
        cout<<"迅速用剑将"<<p.name<<"斩杀,"<<p.name<<"葛生命蜡烛断左"<<HPtemp<<endl;
        p.HP = int(p.HP-HPtemp);
        EXPtemp = int(HPtemp*1.2);
    }
    if (rand()%100<1) {
        cout<<"准备攻击时扑街，HP-1"<<p.name<<"奸笑不已"<<endl;
        return 1;
    }
    if (rand()%100< = 10) {
        hit = 1.5;
        cout<<name<<"黑化，进入暴走，发出会心一击";
    }
    HPtemp = int(hit*(1.0*AP/p.DP)*AP*30/(rand()%8+32));
    cout<<name<<"猛然挥剑，一道银光掠过眼前~~~~ ，"<<p.name<<"被一道剑气穿堂而过"<<"减少hp"<<HPtemp<<endl;
    EXP = int(EXPtemp+HPtemp*1.2);
    p.HP = int(p.HP-HPtemp);
    cout<<name<<"get"<<EXPtemp<<"点经验值"<<endl;
    EXP = int(EXP+EXPtemp);
    system("pause");
    return 1;
}
bool Swordsman::special(player &p)
{
    if(MP<40)
    {
        cout<<"你唔够魔法值"<<endl;
        system("pause");
        return 0;
    }
    else
    {
        MP = MP-40;
        if(rand()%100< = 10)
        {
            cout<<name<<"使用无尽剑制"<<p.name<<"rp爆发，完美闪过"<<endl;
            system("pause");
            return 1;
        }
        double HPtemp = 0,EXPtemp = 0;
        double hit = 1;
        srand(time(NULL));
        HPtemp = int(AP*1.2+20);
        EXPtemp = int(HPtemp*1.5);
        cout<<name<<"大喝一声：“长老~~~~~~~”，拿起长老向"<<p.name<<"砸去，顿时"<<name<<"鲜血四溅"<<endl;
        cout<<p.name<<"生命值减少"<<HPtemp<<","<<name<<"get"<<EXPtemp<<"点经验值"<<endl;
        p.HP = int(p.HP-HPtemp);
        EXP = int(EXPtemp+EXP);
        system("pause");
    }
    return 1;
}
void Swordsman::AI(player &p)
{
    if((HP< = int(1.0*p.AP/DP)*p.AP*1.5)&&(HP+100< = 1.1*HPmax)&&(bag.nOfHeal()>0)&&(p.HP>int((1.0*p.AP/DP)*p.AP*0.6))) {
        useHeal();
    } else {
        if(MP> = 40&&HP>0.5*HPmax&&rand()%10>7)//mp&hp足够，且30%概率
        {
            special(p);
            p.isDead();//判断人类是否死
        }
        else
        {
            if(MP<40&&HP>0.5*HPmax&&!bag.nOfMW())//mp不足，安全
            {
                useMW();
            }
            else
            {
                attack(p);
                p.isDead();
            }
        }
    }
}
