#include <iostream>
#include "player.h"
//#include "fool.h"
//#include "Mage.h"
//#include "Melowdy.h"
//#include "Swordsman.h"
#include "PlayerFactory.h"
using namespace std;
int main()
{
    char temp[10];
    bool success=0;
    cout<<"Game Start " <<endl<<"please input your name: "<<endl;
    cin>>temp;
    player *human;
    int instemp;
    PlayerFactory factory;
    do {
        cout<<"请选择职业：1 魔法师，2 剑士 ,3  枪炮师（bt）,4 武器专家"<<endl;
        cin>>instemp;
        system("clear");
        human = factory.create_player( instemp, temp, success );
    }while (success!=1);
    int stage = 0;
    for(int enemy_level=1; stage<5; enemy_level+=2) {
        stage++;
        system("clear");
        cout<<"关卡"<<stage<<endl;
        cout<<"敌人:一个进化到"<<enemy_level<<"级葛恶良.."<<endl;
        Swordsman enemy(enemy_level, "恶龙");
        human->Recover();
        while(!human->Death()&&!enemy.Death()) {
            success=0;
            while(success!=1) {
                system("clear");
                showinfo(*human,enemy);
                cout<<"请下达指令:"<<endl;
                cout<<"1 攻击，2 魔法，3 补血 4 补魔法值  5 时空商店"<<endl;
                cin>>instemp;
                switch(instemp) {
                    case 1:
                        success=human->attack(enemy);
                        human->LVup();
                        enemy.isDead();
                        break;
                    case 2:
                        success=human->special(enemy);
                        human->LVup();
                        enemy.isDead();
                        break;
                    case 3:
                        success=human->useHeal();
                        break;
                    case 4:
                        success=human->useMW();
                        break;
                    case 5:
                        success=human->shopping(*human);
                    default:break;
                }
                if(!enemy.Death()) {
                    enemy.AI(*human);
                } else {
                    human->get(enemy);
                }
                if(human->Death()) {
                    system("clear");
                    cout<<endl<<endl<<endl<<endl<<endl<<"Game Over"<<endl;
                }
            }
        }
    }
    system("clear");
    cout<<endl<<endl<<endl<<endl<<setw(60)<<"You are win"<<endl;
    delete human;
    cout<<"Thank you for your play.";
}
