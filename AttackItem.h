#pragma once

#include "Item.h"

struct Character;

struct AttackItem : public Item
{
    AttackItem() : Item("attack item", 10) {}
    void use(Character* character) override;
};
