// Aiden Tsang
// CS216 Lab 8 - member functions of the Demon class

#include <string>

#include "Demon.h"
#include "Utilities.h"

using namespace std;

Demon::Demon() : Creature() {
}

Demon::Demon(const string &newName, int newStrength, int newHealth)
    : Creature(newName, newStrength, newHealth) {
}

CreatureType Demon::getType() const {
    return DEMON;
}

string Demon::getName() const {
    return composeName(DEMON);
}

int Demon::getDamage() const {
    int damage = Creature::getDamage();

    if (isChanceHit(DEMON_BONUS_CHANCE)) {
        damage = damage + DEMON_BONUS_DAMAGE;
    }

    return damage;
}
