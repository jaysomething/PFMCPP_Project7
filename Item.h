#pragma once

#include <string>

struct Character;

struct Item
{
    virtual ~Item();
    virtual void use(Character*) = 0;
    Item(const std::string& name_, int effect ) : name(name_), boost(effect) { }
    
    const std::string& getName();
    int getBoost() const;
private:
    std::string name;
    int boost;
};
