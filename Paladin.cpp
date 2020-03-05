#include "Paladin.h"
#include "Utility.h"
#include "AttackDamage.h"

Paladin::Paladin(const std::string& name_, int hp_, int armor_):
Character { hp_, armor_, attackDamagePaladin },
name { name_ }
{
    std::cout << getName() << " gets some items: \n";
    helpfulItems = makeHelpfulItems(getRandomNumber());
    defensiveItems = makeDefensiveItems(getRandomNumber());
}

const std::string& Paladin::getName() { return name; }

std::string Paladin::getStats() { return getCharacterStats(this); }
