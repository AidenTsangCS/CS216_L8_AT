// Aiden Tsang
// CS216 Lab 8 - definition of the Cyberelf class

#ifndef CYBERELF_H
#define CYBERELF_H

#include <string>

#include "Elf.h"

using namespace std;

const int CYBERELF_BONUS_CHANCE = 30;
const int CYBERELF_BONUS_DAMAGE = 50;

class Cyberelf : public Elf {
  public:
    Cyberelf();
    Cyberelf(const string &newName, int newStrength, int newHealth);

    CreatureType getType() const override;
    string getName() const override;
    int getDamage() const override;
};

#endif
