#include <iostream>
#include<stdlib.h>
#include<time.h>//用于产生随即因子
#include "player.h"
using namespace std;
class weaponer:public player//从基类派生出的一个类,是关于武器专家的~
{
public:
	weaponer(int i,char*cptr);
	void LVup();
	bool attack(player &p);
	bool special(player &p);
	void AI(player &p);
};
weaponer::weaponer(int i,char*cptr)
{
	role=wea;
	for(int j=0;j<10;j++)
		name[j]=cptr[j];
	HP=180+6*(i-1);
	HPmax=180+6*(i-1);
    MP=75+8*(i-1);
	MPmax=75+8*(i-1);
    AP=30+3*(i-1);
	DP=24+3*(i-1);
	speed=30+10*(i-1);
	LV=i;
	death=0;
	EXP=(LV-1)*(LV-1)*70;
	bag.set(i*8,i*8,i*8);
}
void weaponer::LVup()
{
	if(EXP>=LV*LV*70)
	{
		LV++;
		AP=AP+3;
		DP=DP+3;
		HPmax=HPmax+7;
		MPmax=MPmax+9;
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
bool weaponer::attack(player &p)
{
	double HPtemp=0,EXPtemp=0;//敌方受伤及取经验
	double hit=1;//致命一击因子;
	srand(time(NULL));//随机数
    if((speed>p.speed)&&(rand()%100<(speed-p.speed)))//两次攻击
	{
		HPtemp=int((1.0*AP/p.DP)*AP*2/(rand()%4+10));
		cout<<name<<"先一个暴冲..在敌面前罗出在个大锤..大地崩裂,"<<"完美中左"<<p.name<<","<<p.name<<"葛心伤左"<<HPtemp<<endl;
		p.HP=int(p.HP-HPtemp);
		EXPtemp=int(HPtemp*1.2);
	}
	if (rand()%100<1)
	{
		cout<<p.name<<"以鬼异的步法闪来..凤在"<<p.name<<"面前爆裂"<<p.name<<"奸笑不已"<<endl;
		system("pause");
		return 1;
	}
	if (rand()%100<=10)
	{
		hit=1.5;
		cout<<name<<"跳上空中..大剑如闪电飞出.."<<p.name<<"敌无法挡";
		HPtemp=int(hit*(1.0*AP/p.DP)*AP*30/(rand()%8+32));
		cout<<name<<"大剑一下飞去"<<p.name<<"葛"<<(rand()%2==1?"小屁屁,":"ooxx,")<<p.name<<"痛苦不已，被肥仔压死，减少HP"<<HPtemp<<endl;
		EXPtemp=int(HPtemp*1.2);
		p.HP=int(p.HP-HPtemp);
		cout<<name<<"get"<<EXPtemp<<"点经验值"<<endl;
		EXP=int(EXPtemp+EXP);
		system("pause");
			return 1;
	}
	HPtemp=int(hit*(1.0*AP/p.DP)*AP*30/(rand()%8+32));
	cout<<name<<"从背后扔出9种武器..分别从不同的角度命中"<<p.name<<"被穿堂而过"<<"减少hp"<<HPtemp<<endl;
			EXP=int(EXPtemp+HPtemp*1.2);
			p.HP=int(p.HP-HPtemp);
			cout<<name<<"获得"<<EXPtemp<<"点经验值"<<endl;
			EXP=int(EXP+EXPtemp);
		    system("pause");
			return 1;
	}
	bool weaponer::special(player &p)
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
			cout<<"喊出“凤引九雏”"<<"扔出9把武器变成9只凤,,飞出..再合来一只大凤..撞上"<<p.name<<endl;
            cout<<name<<"get"<<EXPtemp<<"点经验值"<<endl;
			p.HP=int(p.HP-HPtemp);
			EXP=int(EXPtemp+EXP);
			system("pause");
		}
		return 1;
	}


