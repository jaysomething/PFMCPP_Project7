#include "Character.h"
#include <iostream>
#include <vector>

#include "Utility.h"
#include "DefensiveItem.h"
#include "HelpfulItem.h"

Character::Character(int hp, int armor_, int attackDamage_ ) :
    hitPoints(hp),
    armor(armor_),
    attackDamage(attackDamage_)
{
    initialHitPoints.reset( new int(hitPoints) );
    initialArmorLevel.reset( new int(armor) );
    initialAttackDamage.reset( new int(attackDamage) );
}

void Character::attack( Character& other )
{
    if( hitPoints <= 0 )
    {
        std::cout << getName() << " can't attack. " << getName() << " is dead." << std::endl;
        std::cout << "make another party member use an item to revive them" << std::endl << std::endl;
        return;
    }
        
    isDefending = false;
    std::cout << getName() << " has attacked " << other.getName() << std::endl;
    //subtract attackDamage from other->hitPoints
    if( other.takeDamage(attackDamage) <= 0 )
    {
        //if you kill other, you get a boost in hit points and armor.
        attackInternal(other);
    }
}

void Character::defend()
{
    std::cout << getName() << " is defending!!" << std::endl;
    for( auto& item : defensiveItems )
    {
        if( auto* defensiveItem = dynamic_cast<DefensiveItem*>(item.get()) )
        {
            defensiveItem->use(this);
            item.reset(); //can only be used once!
            break;
        }
    }
    isDefending = true;
}

void Character::help(Character& other)
{
    std::cout << getName() << " is going to help " << other.getName() << std::endl;
    for( auto& item : helpfulItems )
    {
        if( auto* helpfulItem = dynamic_cast<HelpfulItem*>(item.get()) )
        {
            helpfulItem->use(&other);
            item.reset(); //can only be used once!
            break;
        }
    }
}

int Character::takeDamage(int damage)
{
    std::cout << getName() << " is taking " << damage << " damage!" << std::endl;
    if( damage < armor )
    {
        armor -= damage;
    }
    else
    {
        damage -= armor;
        armor = 0;
        
        hitPoints -= damage;
        if( hitPoints < 0 )
        {
            std::cout << getName() << " has died in battle!" << std::endl;
            hitPoints = 0;
        }
    }
    printStats();
    return hitPoints;
}


// #include <cassert>
void Character::attackInternal(Character& other)
{
    if( other.hitPoints <= 0 )
    {
// When you defeat another Character:
// a) your stats are restored to their initial value
// b) your stats are boosted 10%
// c) the initial value of your stats is updated to reflect this boosted stat for the next time you defeat another character.
        
        *initialHitPoints *= 1.1;
        *initialArmorLevel *= 1.1;
        *initialAttackDamage *= 1.1;
        
        hitPoints = *initialHitPoints;
        armor = *initialArmorLevel;
        attackDamage = *initialAttackDamage;
      
// assert(false);
        std::cout << getName() << " defeated " << other.getName() << " and leveled up!" << std::endl;        
    }
}

void Character::boostArmor( int amount )
{
    armor += amount;
    std::cout << getName() << "'s armor level has been boosted to " << armor << std::endl;
}

void Character::boostHitPoints( int amount )
{
    hitPoints += amount;
    std::cout << getName() << "'s hit point level has been boosted to " << hitPoints << std::endl;
}

void Character::boostAttackDamage( int amount )
{
    attackDamage += amount;
    std::cout << getName() << "'s attack damage level has been boosted to " << attackDamage << std::endl;
}

void Character::printStats()
{
    std::cout << getName() << "'s stats: " << std::endl;
    std::cout << getStats(); //make your getStats() use a function from the Utility.h
    
    std::cout << std::endl;
    std::cout << std::endl;
}

