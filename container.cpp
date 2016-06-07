#include "container.h"
containerc::containerc()
{
	set(0,0,0);
}

void containerc::set( int i, int j, int g )
{
	numOfHeal=i;
	numOfMagicWater=j;
	gold=g;
}

int containerc::nOfHeal()
{
	return numOfHeal;
}
int containerc::nOfMW()
{
	return numOfMagicWater;
}
int containerc::nOfgold()
{
	return gold;
}

void containerc::display()
{
	cout<<"你有"<<numOfHeal<<"个可爱多(+100HP)"<<endl;
	cout<<"你有"<<numOfMagicWater<<"个哈根达斯(+80MP)"<<endl;
	cout<<"你有"<<gold<<"米拉"<<endl;
}

bool containerc::useHeal()
{
	numOfHeal--;
	return 1;
}

bool containerc::useMW()
{
	gold=gold-2;
	numOfMagicWater--;
	return 1;
}

bool containerc::buyHeal()
{
	gold=gold-2;
	cout<<"成功购买一个可爱多"<<endl;
	numOfHeal++;
	return 1;
}

bool containerc::buyMW()
{
	gold=gold-2;
	numOfMagicWater++;
	cout<<"成功购买一个哈根达斯"<<endl;
	return 1;
}

bool containerc::buy1()
{
	gold=gold-5;
	return 1;
}

bool containerc::buy2()
{
	gold=gold-10;
	return 1;
}

bool containerc::buy3()
{
	gold=gold-20;
	return 1;
}

bool containerc::buy4()
{
	gold=gold-25;
	return 1;
}








