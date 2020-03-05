#pragma once

#include "Item.h"
#include "Character.h"

struct AttackItem : public Item
{
    AttackItem() : Item("attack item", 3) {}
    void use(Character* character) override;
};
