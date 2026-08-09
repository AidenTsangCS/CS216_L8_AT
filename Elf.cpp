// Aiden Tsang
// CS216 Lab 8 - member functions of the Elf class

#include <string>

#include "Elf.h"
#include "Utilities.h"

using namespace std;

Elf::Elf() : Creature() {
}

Elf::Elf(const string &newName, int newStrength, int newHealth)
    : Creature(newName, newStrength, newHealth) {
}

Elf::~Elf() {
}

CreatureType Elf::getType() const {
    return ELF;
}

string Elf::getName() const {
    return composeName(ELF);
}

int Elf::getDamage() const {
    int damage = Creature::getDamage();

    if (isChanceHit(ELF_BONUS_CHANCE)) {
        damage = damage * ELF_MULTIPLIER;
    }

    return damage;
}
