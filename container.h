#pragma once
#include <iostream>
using namespace std;
class containerc//人物的物品栏
{
protected:
	int numOfHeal;//回复剂数
	int numOfMagicWater;//魔法水数
	int gold;
	int use;

public:
	containerc();//构造函数
	void set( int i,int j, int g );//重设物品数
	int nOfHeal();//判断是否还有回复剂
	int nOfMW();//判断是否还有魔法水
	int nOfgold();//判断是否还有gold
	void display();//显示物品情况
	bool useHeal();//使用回复剂
	bool useMW();//使用魔法水
	bool buyHeal();
	bool buyMW();
	bool buy1();
	bool buy2();
	bool buy3();
	bool buy4();//使用gold
};

