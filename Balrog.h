// Aiden Tsang
// CS216 Lab 8 - definition of the Balrog class

#ifndef BALROG_H
#define BALROG_H

#include <string>

#include "Creature.h"

using namespace std;

const int BALROG_ATTACKS = 2;

class Balrog : public Creature {
  public:
    Balrog();
    Balrog(const string &newName, int newStrength, int newHealth);

    CreatureType getType() const override;
    string getName() const override;
    int getDamage() const override;
};

#endif
