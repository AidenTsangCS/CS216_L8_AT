// Aiden Tsang
// CS216 Lab 8 - definition of the abstract Creature class

#ifndef CREATURE_H
#define CREATURE_H

#include <string>

#include "Utilities.h"

using namespace std;

const string INVALID_NAME = "";
const int INVALID_STAT = -1;
const int MIN_DAMAGE = 1;
const int MIN_RESET_STAT = 30;
const int MAX_RESET_STAT = 150;
const int MIN_VALID_STRENGTH = 1;
const int MIN_VALID_HEALTH = 0;
const int DEFAULT_STAT = MIN_RESET_STAT;

const int ID_COL = 12;
const int TYPE_COL = 12;
const int STAT_COL = 10;

enum CreatureType { DEMON, BALROG, ELF, CYBERELF };

const string CREATURE_TYPE_NAMES[] = {"demon", "balrog", "elf", "cyberelf"};

class Creature {
  protected:
    string name = DEFAULT_NAME;
    int strength = DEFAULT_STAT;
    int health = DEFAULT_STAT;

    string composeName(CreatureType type) const;

  private:
    void assignCreature(const string &newName, int newStrength,
                        int newHealth);

  public:
    Creature();
    Creature(const string &newName, int newStrength, int newHealth);
    virtual ~Creature();

    void setCreature(const string &newName, int newStrength, int newHealth);
    void reset();
    void takeDamage(int damageTaken);

    string getId() const;
    int getStrength() const;
    int getHealth() const;
    string getTypeName() const;
    string toString() const;

    virtual CreatureType getType() const = 0;
    virtual string getName() const = 0;
    virtual int getDamage() const;
};

#endif