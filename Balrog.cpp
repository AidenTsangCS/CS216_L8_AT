// Aiden Tsang
// CS216 Lab 8 - member functions of the Balrog class

#include <string>

#include "Balrog.h"

using namespace std;

Balrog::Balrog() : Creature() {
}

Balrog::Balrog(const string &newName, int newStrength, int newHealth)
    : Creature(newName, newStrength, newHealth) {
}

CreatureType Balrog::getType() const {
    return BALROG;
}

string Balrog::getName() const {
    return composeName(BALROG);
}

int Balrog::getDamage() const {
    int damage = 0;

    for (int strikeCount = 0; strikeCount < BALROG_ATTACKS; ++strikeCount) {
        damage = damage + Creature::getDamage();
    }

    return damage;
}