#include "Dragon.h"
#include "DragonSlayer.h"
#include "Utility.h"
#include "AttackDamage.h"


Dragon::Dragon(const std::string& name_, int hp_, int armor_):
name { name_ },
Character { hp_, armor_, attackDamageDragon }
{
}

void Dragon::attack(Character &other)
{
    std::cout << name << " is attacking " << other.getName() << "!!!" << std::endl;
    if( auto* slayer = dynamic_cast<DragonSlayer*>(&other) )
    {
        //dragons can't attack dragon slayers
        slayer->defend();
    }
    else
    {
        Character::attack(other);
    }
}

const std::string& Dragon::getName() { return name; }

std::string Dragon::getStats() { return getCharacterStats(this); }
