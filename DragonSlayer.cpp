#include "DragonSlayer.h"
#include "Dragon.h"
#include "Utility.h"
#include "AttackDamage.h"

DragonSlayer::DragonSlayer(const std::string& name_, int hp_, int armor_):
Character { hp_, armor_, attackDamageDragonSlayer },
name { name_ }
{
    std::cout << getName() << " gets some items: \n";
    helpfulItems = makeHelpfulItems(getRandomNumber());
    defensiveItems = makeDefensiveItems(getRandomNumber());
}

DragonSlayer::~DragonSlayer()
{
    delete attackItem;
}

const std::string& DragonSlayer::getName() { return name; }

void DragonSlayer::attack(Character& other)
{
    std::cout << name << " is attacking " << other.getName() << " !!" << std::endl;
    if( auto* dragon = dynamic_cast<Dragon*>(&other) )
    {
        //assert(false);
        //DragonSlayers get a 10x boost when attacking dragons, from their attack item.
        //so they should USE their attack item before attacking the dragon... 
        //
        useAttackItem(this, attackItem);
        
        while( dragon->getHP() > 0 )
        {
          dragon->takeDamage(attackDamage);
        }
    }
        
    Character::attack(other);
        
}

std::string DragonSlayer::getStats() { return getCharacterStats(this); }
