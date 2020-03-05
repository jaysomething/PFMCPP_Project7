#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "Item.h"

#include <random> // for std::mt19937
#include <ctime> // for std::time

static constexpr int rNum_min { 0 };
static constexpr int rNum_max { 5 };

int getRandomNumber();

std::vector<std::unique_ptr<Item>> makeHelpfulItems(int num);

std::vector<std::unique_ptr<Item>> makeDefensiveItems(int num);

struct Character;
std::string getCharacterStats(Character* ch);

void useDefensiveItem(Character*, Item&);
void useHelpfulItem(Character*, Item*);
void useAttackItem(Character*, Item*);
