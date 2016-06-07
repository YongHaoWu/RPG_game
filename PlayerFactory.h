#ifndef PLAYER_FACTORY
#define PLAYER_FACTORY
#include "fool.h"
#include "Mage.h"
#include "Swordsman.h"
#include "weaponer.h"

class PlayerFactory
{
    public:
        player* create_player( int instemp, char *temp, bool &success )
        {
            player* human ;
            switch( instemp )
            {
                case 1:
                    human = new Mage(1,temp);
                    success=1;
                    break;
                case 2:
                    human = new Swordsman(1,temp);
                    success=1;
                    break;
                case 3:
                    human = new fool(1,temp);
                    success=1;
                    break;
                case 4:
                    human = new weaponer(1,temp);
                    success=1;
                    break;
                default:
                    break;
            }
            return human;
        }
};
#endif
