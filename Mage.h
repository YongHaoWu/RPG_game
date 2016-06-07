#include <iostream>
#include<stdlib.h>
#include<time.h>
#include "player.h"
using namespace std;
class Mage:public player
{
    public:
        Mage(int i,char*cptr);
        void LVup();
        bool attack(player &p);
        bool special(player &p);
        void AI(player &p);
};
Mage::Mage(int i,char*cptr)
{
    role = mg;
    for(int j = 0;j<10;j++)
        name[j] = cptr[j];
    HP = 120+4*(i-1);
    HPmax = 120+4*(i-1);
    MP = 200+20*(i-1);
    MPmax = 200+20*(i-1);
    AP = 50+4*(i-1);
    DP = 20+4*(i-1);
    speed = 25+3*(i-1);
    LV = i;
    death = 0;
    EXP = (LV-1)*(LV-1)*65;
    bag.set(i*5,i*30,i*8);
}
void Mage::LVup()
{
    if(EXP> = LV*LV*65)
    {
        LV++;
        AP = AP+2;
        DP = DP+2;
        HPmax = HPmax+4;
        MPmax = MPmax+20;
        speed = speed+3;
        cout<<name<<"升级啦"<<endl;
        cout<<"生命值增加"<<4<<"点"<<endl;
        cout<<"魔法值增加."<<20<<"点"<<endl;
        cout<<"速度增加"<<3<<"点."<<endl;
        cout<<"攻击力增加"<<2<<"点"<<endl;
        cout<<"防御力增加."<<2<<"点"<<endl<<endl;
        LVup();//递归调用，可以连升级
    }
}
bool Mage::attack(player &p)
{
    double HPtemp = 0,EXPtemp = 0;//敌方受伤及取经验
    double hit = 1;//致命一击因子;
    srand(time(NULL));//随机数
    if((speed>p.speed)&&(rand()%100<(speed-p.speed)))//两次攻击
    {
        HPtemp = int((1.0*AP/p.DP)*AP*3/(rand()%4+10));
        cout<<name<<"迅速用长老默念石湖话，向"<<p.name<<"使用double____狂雷天牢,"<<p.name<<"葛生命蜡烛断左"<<HPtemp<<"枝(HP)"<<endl;
        p.HP = int(p.HP-HPtemp);
        EXPtemp = int(HPtemp*1.2);
    }
    if (rand()%100<1)
    {
        cout<<name<<"准备念咒语时,咬亲利，HP-1"<<p.name<<"奸笑不已"<<endl;
        HP = HP-1;
        system("pause");
        return 1;
    }
    if (rand()%100< = 10)
    {
        hit = 1.5;
        cout<<name<<"黑化，进入暴走，发出致命一击~~";
        HPtemp = int(hit*(1.0*AP/p.DP)*AP*25/(rand()%8+35));
        cout<<"举起长老，一下飞去"<<p.name<<"葛"<<(rand()%2 =  = 1?"小屁屁,":"ooxx,")<<p.name<<"痛苦不已，面部崩坏，减少HP"<<HPtemp<<endl;
        EXPtemp = int(HPtemp*1.2);
        p.HP = int(p.HP-HPtemp);
        cout<<name<<"get"<<EXPtemp<<"点经验值"<<endl;
        EXP = int(EXPtemp+EXP);
        system("pause");
        return 1;
    }
    HPtemp = int(hit*(1.0*AP/p.DP)*AP*25/(rand()%8+35));
    cout<<name<<"默念石湖话~#@￥%……~~~ ，"<<p.name<<"被n条OOXX穿堂而过"<<"减少hp"<<HPtemp<<endl;
    EXP = int(EXPtemp+HPtemp*1.2);
    p.HP = int(p.HP-HPtemp);
    cout<<name<<"获得"<<EXPtemp<<"点经验值"<<endl;
    EXP = int(EXP+EXPtemp);
    system("pause");
    return 1;
}
bool Mage::special(player &p)
{
    if(MP<20)
    {
        cout<<"你唔够魔法值"<<endl;
        system("pause");
        return 0;
    }
    else
    {
        MP = MP-20;
        if(rand()%100< = 19)
        {
            cout<<"默念石湖话&#*￥@......,使用无尽剑制"<<p.name<<"rp爆发，完美闪过"<<endl;
            system("pause");
            return 1;
        }
        double HPtemp = 0,EXPtemp = 0;
        srand(time(NULL));
        HPtemp = int(AP*1.1);
        EXPtemp = int(HPtemp*1.3);
        cout<<"血祭......,召唤耶和华将"<<p.name<<"死死抱住,吸取养料....."<<name<<"吸取"<<p.name<<"的粪便"<<HPtemp<<"吨"<<endl;
        cout<<name<<"津津有味地吮吸，增加hp"<<HPtemp<<"点"<<endl;
        cout<<name<<"get"<<EXPtemp<<"点经验值"<<endl;
        p.HP = int(p.HP-HPtemp);
        EXP = int(EXPtemp+EXP);
        if(HP+HPtemp< = HPmax)
            HP = int(HP+HPtemp);
        else
            HP = HPmax;
        system("pause");
    }
    return 1;
}
