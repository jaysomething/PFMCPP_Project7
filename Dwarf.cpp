#include "Dwarf.h"
#include "Utility.h"
#include "AttackDamage.h"

Dwarf::Dwarf(const std::string& name_, int hp_, int armor_):
name { name_ },
Character { hp_, armor_, attackDamageDwarf }
{
    std::cout << getName() << " gets some items: \n";
    helpfulItems = makeHelpfulItems(getRandomNumber());
    defensiveItems = makeDefensiveItems(getRandomNumber());
}

const std::string& Dwarf::getName() { return name; }

std::string Dwarf::getStats() { return getCharacterStats(this); }
