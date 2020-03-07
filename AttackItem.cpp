#include "AttackItem.h"
#include "Utility.h"
#include "Character.h"
//#include "Dwarf.h"
//#include "Paladin.h"
//#include "DragonSlayer.h"
//#include "Dragon.h"

void AttackItem::use(Character* character)
{
    useAttackItem(character, this);
}
