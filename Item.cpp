#include "Item.h"

Item::~Item() { }

const std::string& Item::getName() { return name; }
int Item::getBoost() const { return boost; }
