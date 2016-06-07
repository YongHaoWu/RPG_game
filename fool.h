 #pragma once
#include <iostream>
#include<stdlib.h>
#include<time.h>//用于产生随即因子
#include "player.h"
using namespace std;
class fool:public player//从基类派生出的一个类,是关于大傻的~
{
public:
	fool(int i,char*cptr);
	void LVup();
	bool attack(player &p);
	bool special(player &p);
	void AI(player &p);
};
fool::fool(int i,char*cptr)
{
	role=f;
	for(int j=0;j<10;j++)
		name[j]=cptr[j];
	HP=100+6*(i-1);
	HPmax=180+6*(i-1);
    MP=60+8*(i-1);
	MPmax=75+8*(i-1);
    AP=100+3*(i-1);
	DP=100+3*(i-1);
	speed=100+10*(i-1);
	LV=i;
	death=0;
	EXP=(LV-1)*(LV-1)*70;
	bag.set(i*1,i*1,i*8);
}
void fool::LVup()
{
	if(EXP>=LV*LV*70)
	{
		LV++;
		AP=AP+1;
        DP=DP+3;
        HPmax=HPmax+1;
        MPmax=MPmax+3;
        speed=speed+11;
        cout<<name<<"升级啦"<<endl;
        cout<<"生命值增加"<<6<<"点"<<endl;
        cout<<"魔法值增加."<<8<<"点"<<endl;
        cout<<"速度增加"<<10<<"点."<<endl;
        cout<<"攻击力增加"<<3<<"点"<<endl;
        cout<<"防御力增加."<<3<<"点"<<endl<<endl;
        LVup();//递归调用，可以连升级
    }
}
bool fool::attack(player &p)
{
    double HPtemp=0,EXPtemp=0;//敌方受伤及取经验
    double hit=1;//致命一击因子;
    srand(time(NULL));//随机数
    if((speed>p.speed)&&(rand()%100<(speed-p.speed)))//两次攻击
    {
        HPtemp=int((1.0*AP/p.DP)*AP*2/(rand()%4+10));
        cout<<name<<"先暗射几炮,"<<"完美中左"<<p.name<<"葛OOXX,"<<p.name<<"葛血伤左"<<HPtemp<<endl;
        p.HP=int(p.HP-HPtemp);
        EXPtemp=int(HPtemp*1.2);
    }
    if (rand()%100<1)
    {
        cout<<name<<"准备射枪时,不意走火，射到脚趾"<<p.name<<"奸笑不已"<<endl;
        system("pause");
        return 1;
    }
    if (rand()%100<=10)
    {
        hit=1.5;
        cout<<name<<"暴走，进入无我状态，";
        HPtemp=int(hit*(1.0*AP/p.DP)*AP*30/(rand()%8+32));
        cout<<name<<"射起成千上万葛火箭炮，一下飞去"<<p.name<<"葛"<<(rand()%2==1?"DODO,":"ooxx,")<<p.name<<"粉身碎骨，死无全尸，减少HP"<<HPtemp<<endl;
        EXPtemp=int(HPtemp*1.2);
        p.HP=int(p.HP-HPtemp);
        cout<<name<<"get"<<EXPtemp<<"点经验值"<<endl;
        EXP=int(EXPtemp+EXP);
        system("pause");
        return 1;
    }
    HPtemp=int(hit*(1.0*AP/p.DP)*AP*30/(rand()%8+32));
    cout<<name<<"使用"<<name<<"二重炮射向~~~ ，"<<p.name<<"被穿堂而过"<<"减少hp"<<HPtemp<<endl;
    EXP=int(EXPtemp+HPtemp*1.2);
    p.HP=int(p.HP-HPtemp);
    cout<<name<<"获得"<<EXPtemp<<"点经验值"<<endl;
    EXP=int(EXP+EXPtemp);
    system("pause");
    return 1;
}
bool fool::special(player &p)
{
    if(MP<20)
    {
        cout<<"你唔够魔法值"<<endl;
        system("pause");
        return 0;
    }
    else
    {
        MP=MP-20;
        double HPtemp=0,EXPtemp=0;
        srand(time(NULL));
        HPtemp=int(AP*1.1);
        EXPtemp=int(HPtemp*1.3);
        cout<<"大喝一声“枪林弹雨~~~~~”扮酷甘将"<<p.name<<"打到蜜蜂斗甘"<<endl;
        cout<<name<<"get"<<EXPtemp<<"点经验值"<<endl;
        p.HP=int(p.HP-HPtemp);
        EXP=int(EXPtemp+EXP);
        system("pause");
    }
    return 1;
}


