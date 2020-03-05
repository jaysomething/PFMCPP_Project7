#pragma once

#include "Character.h"

struct DragonSlayer : public Character
{
    DragonSlayer(const std::string& name_, int hp_, int armor_);
    ~DragonSlayer();
    
    const std::string& getName() override;
    std::string getStats() override;
    void attack(Character& other) override;
private:
    const std::string name;
    AttackItem* attackItem = new AttackItem;
};
