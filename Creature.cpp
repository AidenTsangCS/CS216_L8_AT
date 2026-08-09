// Aiden Tsang
// CS216 Lab 8 - member functions of the abstract Creature class

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Creature.h"
#include "Utilities.h"

using namespace std;

Creature::Creature() {
    setCreature(DEFAULT_NAME, DEFAULT_STAT, DEFAULT_STAT);
}

Creature::Creature(const string &newName, int newStrength, int newHealth) {
    setCreature(newName, newStrength, newHealth);
}

Creature::~Creature() {
    assignCreature(INVALID_NAME, INVALID_STAT, INVALID_STAT);
}

void Creature::assignCreature(const string &newName, int newStrength,
                              int newHealth) {
    name = newName;
    strength = newStrength;
    health = newHealth;
}

string Creature::composeName(CreatureType type) const {
    return name + " the " + capitalizeFirst(CREATURE_TYPE_NAMES[type]);
}

void Creature::setCreature(const string &newName, int newStrength,
                           int newHealth) {
    bool isValid = countAlphabetic(newName) > 0
                   && newStrength >= MIN_VALID_STRENGTH
                   && newHealth >= MIN_VALID_HEALTH;

    if (!isValid) {
        cout << "\nInvalid creature record; " << name
             << " was left unchanged" << endl;
    }
    else {
        assignCreature(newName, newStrength, newHealth);
    }
}

void Creature::reset() {
    int newStrength = randomInRange(MIN_RESET_STAT, MAX_RESET_STAT);
    int newHealth = randomInRange(MIN_RESET_STAT, MAX_RESET_STAT);

    setCreature(name, newStrength, newHealth);
}

void Creature::takeDamage(int damageTaken) {
    int newHealth = health - damageTaken;

    if (newHealth < MIN_VALID_HEALTH) {
        newHealth = MIN_VALID_HEALTH;
    }

    setCreature(name, strength, newHealth);
}

string Creature::getId() const {
    return name;
}

int Creature::getStrength() const {
    return strength;
}

int Creature::getHealth() const {
    return health;
}

string Creature::getTypeName() const {
    return CREATURE_TYPE_NAMES[getType()];
}

string Creature::toString() const {
    ostringstream row;

    row << left << setw(ID_COL) << name
        << setw(TYPE_COL) << getTypeName()
        << right << setw(STAT_COL) << strength
        << setw(STAT_COL) << health;

    return row.str();
}

int Creature::getDamage() const {
    return randomInRange(MIN_DAMAGE, strength);
}