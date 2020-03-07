#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "Item.h"

struct Character
{
    Character(int hp, int armor_, int attackDamage_ );
    virtual ~Character() { }
    
    /*
     a pure virtual getName function.
     derived class stores the name, not the base class.
     */
    
    virtual const std::string& getName() = 0;
    virtual std::string getStats() = 0;
    
    virtual void attack( Character& other );
    void defend();
    
    void help( Character& other );
    
    int takeDamage(int damage);
    
    int getHP() const { return hitPoints; }
    int getArmorLevel() const { return armor; }
    int getAttackDamage() const { return attackDamage; }
    bool getIsDefending() const { return isDefending; }
    
    const std::vector<std::unique_ptr<Item>>& getHelpfulItems() const { return helpfulItems; }
    const std::vector<std::unique_ptr<Item>>& getDefensiveItems() const { return defensiveItems; }
    
    void boostArmor( int amount );
    void boostHitPoints( int amount );
    void boostAttackDamage( int amount );
    void printStats();
    
protected:
    std::vector<std::unique_ptr<Item>> defensiveItems;
    std::vector<std::unique_ptr<Item>> helpfulItems;
    int hitPoints, armor;
    int attackDamage;
    bool isDefending = false;
    
private:
    std::unique_ptr<int> initialHitPoints, initialArmorLevel, initialAttackDamage;
    
    void attackInternal(Character& other);
};
