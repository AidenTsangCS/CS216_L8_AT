// Aiden Tsang
// CS216 Lab 8 - definition of the Army class

#ifndef ARMY_H
#define ARMY_H

#include <string>

#include "Creature.h"

using namespace std;

const string DEFAULT_ARMY_NAME = "n/a";
const int DEFAULT_ARMY_SIZE = 0;
const string INVALID_ARMY_NAME = "";
const int INVALID_ARMY_SIZE = -1;
const int MIN_ARMY_SIZE = 1;
const int MAX_ARMY_SIZE = 12;
const int MIN_ARMY_STAT = 45;
const int MAX_ARMY_STAT = 275;
const int FIRST_NAME_INDEX = 0;
const int STATS_WIDTH = ID_COL + TYPE_COL + STAT_COL + STAT_COL;

class Army {
  private:
    string name = DEFAULT_ARMY_NAME;
    int size = DEFAULT_ARMY_SIZE;
    Creature **ppCreatures = nullptr;

    void setArmy(const string &newName, int newSize,
                 Creature **ppNewCreatures);
    void copyArmy(const Army &rhs);
    CreatureType randomType() const;
    Creature *createCreature(CreatureType type, const string &newName,
                             int newStrength, int newHealth) const;
    Creature **buildCreatures(int newSize, const Army *pSource,
                              const string *pNames, int startIndex) const;
    void releaseCreatures(Creature **&ppList, int count) const;

  public:
    Army();
    Army(const Army &rhs);
    ~Army();

    Army &operator=(const Army &rhs);

    bool createArmy(const string &newName, int newSize,
                    const string *pNames, int startIndex);
    void resetCreatures();

    string getName() const;
    int getSize() const;
    int getTotalHealth() const;
    Creature *getCreature(int index) const;
    void print(const string &label) const;
};

#endif