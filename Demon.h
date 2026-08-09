// Aiden Tsang
// CS216 Lab 8 - definition of the Demon class

#ifndef DEMON_H
#define DEMON_H

#include <string>

#include "Creature.h"

using namespace std;

const int DEMON_BONUS_CHANCE = 15;
const int DEMON_BONUS_DAMAGE = 40;

class Demon : public Creature {
  public:
    Demon();
    Demon(const string &newName, int newStrength, int newHealth);

    CreatureType getType() const override;
    string getName() const override;
    int getDamage() const override;
};

#endif
