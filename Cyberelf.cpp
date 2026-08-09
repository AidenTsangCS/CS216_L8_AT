// Aiden Tsang
// CS216 Lab 8 - member functions of the Cyberelf class

#include <string>

#include "Cyberelf.h"
#include "Utilities.h"

using namespace std;

Cyberelf::Cyberelf() : Elf() {
}

Cyberelf::Cyberelf(const string &newName, int newStrength, int newHealth)
    : Elf(newName, newStrength, newHealth) {
}

CreatureType Cyberelf::getType() const {
    return CYBERELF;
}

string Cyberelf::getName() const {
    return composeName(CYBERELF);
}

int Cyberelf::getDamage() const {
    int damage = Elf::getDamage();

    if (isChanceHit(CYBERELF_BONUS_CHANCE)) {
        damage = damage + CYBERELF_BONUS_DAMAGE;
    }

    return damage;
}
