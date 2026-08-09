// Aiden Tsang
// CS216 Lab 8 - definition of the Elf class

#ifndef ELF_H
#define ELF_H

#include <string>

#include "Creature.h"

using namespace std;

const int ELF_BONUS_CHANCE = 20;
const int ELF_MULTIPLIER = 2;

class Elf : public Creature {
  public:
    Elf();
    Elf(const string &newName, int newStrength, int newHealth);
    virtual ~Elf();

    CreatureType getType() const override;
    string getName() const override;
    int getDamage() const override;
};

#endif
