 #pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<stdlib.h>
#include<time.h>//用于产生随机因子
#include "container.h"
using namespace std;
enum property {sw,mg,f,wea};
class player
{
	friend void showinfo(player &p1, player &p2);
	friend class Swordsman;
	friend class Mage;
	friend class fool;
	friend class weaponer;
	friend class Melowdy;
protected:
	int HP, HPmax, MP, MPmax, DP, AP, speed, EXP, LV;
	char name[10];
	property role;
	containerc bag;
	string wuqi,fangju;
public:
	int shop;
	int tempxx;
	int wuqiAP;
	int wuqiHP;
	int fangjuDP;
	int fangjuHP;
	virtual bool attack(player &p){return 1;};//普通攻击
	virtual bool special(player &p){return 1;};//特殊攻击
	virtual void LVup(){};//上面三个都是虚函数~分别代表 人物的普通攻击~特殊攻击和是否升级};
	void Recover();
	bool shopping(player &p);
	bool Death();//告知是否死亡
	void isDead();//判断dead
    bool useHeal();
	bool useMW();
	void get(player &p);//杀死敌人得到物品
	char showRole();
private:
	bool death;
};


void player::Recover()
{
	HP=HPmax;
	MP=MPmax;
}
bool player::shopping(player &p)
{
	cout<<"欢迎来到时空商店，请选择到：1 武器店 ；2 防具店；3 store（药店）；4 返回；PS：请注意自己够唔够钱买，唔好浑水摸鱼！！！"<<endl;
	cin>>shop;
	switch(shop)
	{
	case 3:
		cout<<"1:  可爱多（￥2 ）   2:  哈根达斯（￥2）"<<endl;
		cin>>tempxx;
		switch(tempxx)
		{
		case 1:
			if(bag.nOfgold()>=2)
			{
				bag.buyHeal();
			}
			else
			{
				cout<<"你唔够钱"<<endl;
			}
			break;
		case 2:
			if(bag.nOfgold()>=2)
			{
				bag.buyMW();
			}
			else
			{
				cout<<"你唔够钱"<<endl;
			}
			break;
		}
		break;
	case 1:
		cout<<"武器店"<<endl;
		cout<<"1: ￥5  \t|辛洛斯，诸界的毁灭者|\t\t攻击+10\t体力+5\n";
		cout<<"2: ￥10 \t|上古其拉撕裂者|\t\t攻击+30\t体力+15\n";
		cout<<"3: ￥20 \t|萨弗拉斯，炎魔拉格纳罗斯之手|\t攻击+50\t体力+25\n";
		cout<<"4: ￥25 \t|雷霆之怒*逐风者的祝福之剑|\t攻击+100体力+50\n";
		cout<<"5:   *返回*\n";
		cin>>tempxx;
		switch(tempxx)
		{
		case 1:
			if(bag.nOfgold()>=5)
			{
				cout<<"购买成功！\n你获得一把|辛洛斯，诸界的毁灭者|\n";
				string wuqi="|诸界的毁灭者|";
				wuqiAP=10;
				wuqiHP=15;
				AP=wuqiAP+AP;
				HP=HP+wuqiHP;
				bag.buy1();
			}
			else
			{
				cout<<"你唔够钱"<<endl;
			}
			break;
		case 2:
			if(bag.nOfgold()>=10)
			{
				cout<<"购买成功！\n你获得一把|上古其拉撕裂者|\n";
				string wuqi="|上古其拉撕裂者|";
				wuqiAP=30;
				wuqiHP=35;
				p.AP=wuqiAP+p.AP;
				p.HP=p.HP+wuqiHP;
				bag.buy2();
			}
			else
			{
				cout<<"你唔够钱"<<endl;
			}
			break;
		case 3:
			if(bag.nOfgold()>=20)
			{
				cout<<"购买成功！\n你获得一把|萨弗拉斯，炎魔拉格纳罗斯之手|\n";
				string wuqi="|萨弗拉斯，炎魔拉格纳罗斯之手|";
				wuqiAP=40;
				wuqiHP=45;
				p.AP=wuqiAP+p.AP;
				p.HP=p.HP+wuqiHP;
				bag.buy3();
			}
			else
			{
				cout<<"你唔够钱"<<endl;
			}
			break;
		case 4:
			if(bag.nOfgold()>=25)
			{
				cout<<"购买成功！\n你获得一把|雷霆之怒*神一般的长老|\n";
				string  wuqi="|雷霆之怒*神一般的长老|";;
				wuqiAP=50;
				wuqiHP=55;
				p.AP=wuqiAP+p.AP;
				p.HP=p.HP+wuqiHP;
				bag.buy4();
			}
			else
			{
				cout<<"你唔够钱"<<endl;
			}
			break;
		}break;
	case 2:
		cout<<"<<防具店>>\n\n";
		cout<<"1: 5两\t\t|T1|\t体力+10\t防御+3 \n";
		cout<<"2: 10两\t|T2|\t体力+15\t防御+5\n";
		cout<<"3: 20两\t|T3|\t体力+20\t防御+10\n";
		cout<<"4: 30两\t|T4|\t体力+40\t防御+18\n";
		cout<<"5:*返回*\n";
		cin>>tempxx;
		switch(tempxx)
		{
		case 1:
			if(bag.nOfgold()>=5)
			{
				cout<<"购买成功！\n你装备上T1\n";
				string  fangju="|T1|";
				fangjuDP=3;
				fangjuHP=10;
				p.DP=fangjuDP+p.DP;
				p.HP=p.HP+fangjuHP;
				bag.buy1();
			}
			else
			{
				cout<<"你唔够钱"<<endl;
			}
			break;
		case 2:
			if(bag.nOfgold()>=10)
			{
				cout<<"购买成功！\n你装备上T2\n";
				string  fangju="|T2|";
				fangjuDP=5;
				fangjuHP=15;
				p.DP=fangjuDP+p.DP;
				p.HP=p.HP+fangjuHP;
				bag.buy2();
			}
			else
			{
				cout<<"你唔够钱"<<endl;
			}
			break;
		case 3:
			if(bag.nOfgold()>=20)
			{
				cout<<"购买成功！\n你装备上T3\n";
				string  fangju="|T3|";
				fangjuDP=10;
				fangjuHP=20;
				p.DP=fangjuDP+p.DP;
				p.HP=p.HP+fangjuHP;
				bag.buy3();
			}
			else
			{
				cout<<"你唔够钱"<<endl;
			}
			break;
		case 4:
			if(bag.nOfgold()>=25)
			{
				cout<<"购买成功！\n你装备上T4\n";
				string  fangju="|T4|";
				fangjuDP=18;
				fangjuHP=40;
				p.DP=fangjuDP+p.DP;
				p.HP=p.HP+fangjuHP;
				bag.buy4();
			}
			else
			{
				cout<<"你唔够钱"<<endl;
			}
			break;
		}break;
	}
	return 1;
}
bool player::Death()
{
	return death;
}
void player::isDead()
{
	if(HP<=0)
	{
		cout<<"...哈哈 "<<name<<"死左啦"<<endl;
		system("pause");
		death=1;
	}
}
bool player::useHeal()
{
	if(bag.nOfHeal()>0)
	{
		HP=HP+100;
		if(HP>HPmax)
			HP=HPmax;
		cout<<name<<"食左个可爱多，HP+100."<<endl;
		bag.useHeal();
		system("pause");
		return 1;
	}
	else
	{
		cout<<"额。。你无物品啦。。准备死啦！！"<<endl;
		system("pause");
		return 0;
	}
}
bool player::useMW()
{if(bag.nOfMW()>0)
{
	MP=MP+80;
	if(MP>MPmax)
		MP=MPmax;
	cout<<name<<"及时享受一盒哈根达斯"<<endl;
	bag.useMW();
	system("pause");
	return 1;
}
cout<<"无得食啦"<<endl;
system("pause");
return 0;
}








void player::get(player &p)
{
	cout<<name<<"抢到"<<p.bag.nOfHeal()<<"个可爱多and"<<p.bag.nOfMW()<<"合哈根达斯"<<p.bag.nOfgold()<<"钱"<<endl;
	system("pause");
	bag.set(bag.nOfHeal()+p.bag.nOfHeal(),bag.nOfMW()+p.bag.nOfMW(),bag.nOfgold()+p.bag.nOfgold());
}
char player::showRole()
{
	switch(role)
	{
	case sw:
		cout<<setw(6)<<"剑士";break;
	case mg:
		cout<<setw(6)<<"魔法师";break;
	case f:
		cout<<setw(6)<<"枪炮师";break;
	case wea:
		cout<<setw(6)<<"武器专家";break;
	default: break;
	}
	return 1;
}
void showinfo(player &p1,player &p2)
{
	cout<<"###########################################################"<<endl;
	cout<<"# 勇者"<<setw(11)<<p1.name<<" LV."<<setw(3)<<p1.LV<<"     # 敌人"<<setw(11)<<p2.name<<" LV."<<setw(3)<<p2.LV<<"     #"<<endl;
	cout<<"# ＨＰ "<<setw(3)<<(p1.HP<=999?p1.HP:999)<<'/'<<setw(3)<<(p1.HPmax<=999?p1.HPmax:999)<<" ＭＰ　"<<setw(3)<<(p1.MP<=999?p1.MP:999)<<'/'<<setw(3)<<(p1.MPmax<=999?p1.MPmax:999)<<"|| HP "<<setw(3)<<(p2.HP<=999?p2.HP:999)<<'/'<<(p2.HPmax<=999?p2.HPmax:999)<<" ＭＰ　"<<setw(3)<<(p2.MP<=999?p2.MP:999)<<'/'<<setw(3)<<(p2.MPmax<=999?p2.MPmax:999)<<"   #"<<endl;
	cout<<"# AP   "<<setw(3)<<(p1.AP<=999?p1.AP:999)<<"  DP"<<setw(3)<<(p1.DP<=999?p1.DP:999)<<" speed"<<setw(3)<<(p1.speed<=999?p1.speed:999)<<"   # AP"<<setw(3)<<(p2.AP<=999?p2.AP:999)<<" DP"<<setw(3)<<(p2.DP<=999?p2.DP:999)<<"   speed"<<setw(3)<<(p2.speed<=999?p2.speed:999)<<"     #"<<endl;
	cout<<"# EXP"<<setw(7)<<p1.EXP<<"　 职业·";
	cout<<p1.showRole();
	cout<<" # EXP"<<setw(7)<<p2.EXP<<" 职业·";
	cout<<p2.showRole()<<"  #"<<endl;
	cout<<"——————————————————————————————"<<endl;
	p1.bag.display();
}
