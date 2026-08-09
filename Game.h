// Aiden Tsang
// CS216 Lab 8 - definition of the Game class

#ifndef GAME_H
#define GAME_H

#include <string>

#include "Army.h"
#include "Creature.h"

using namespace std;

const string NAMES_FILE = "in_creature_names.txt";

const int ARMIES_PER_BATTLE = 2;
const int FIRST_STRIKE_CHANCE = 50;

const int FIGHTER_COL = 23;
const int ARMY_COL = 10;
const int NUM_COL = 7;
const int COLUMN_GAP_WIDTH = 2;
const int DUEL_WIDTH = FIGHTER_COL * 2 + ARMY_COL * 2 + NUM_COL * 3
                       + COLUMN_GAP_WIDTH;

const string SIZE_RULE = " (" + to_string(MIN_ARMY_SIZE) + " to "
                         + to_string(MAX_ARMY_SIZE) + "): ";
const string SIZE_PROMPT = "\nEnter the number of creatures in each army"
                           + SIZE_RULE;
const string ARMY_ONE_PROMPT = "Enter the name of army #1" + NAME_RULE;
const string ARMY_TWO_PROMPT = "Enter the name of army #2" + NAME_RULE;
const string REMATCH_PROMPT = "\n\nRematch Menu:\n"
                              "1. Fight again with the same creatures\n"
                              "2. Back to the main menu\n"
                              "Enter your choice: ";
const string BEFORE_LABEL = "before the Battle";
const string AFTER_LABEL = "after the Battle";

enum RematchOption { REMATCH_YES = 1, REMATCH_NO };

class Game {
  private:
    Army armyOne;
    Army armyTwo;

    string *loadNames(int neededCount) const;
    bool buildArmies(int armySize, const string *pNames);
    void runBattleSeries(int armySize);
    void runBattle(int armySize);
    void runDuel(int position);
    void exchangeBlows(Creature *pAttacker, const string &attackerArmy,
                       Creature *pDefender,
                       const string &defenderArmy) const;
    void strike(Creature *pAttacker, const string &attackerArmy,
                Creature *pDefender, const string &defenderArmy) const;
    void printDuelHeader() const;
    void announceDuelWinner(const Creature *pFirst,
                            const Creature *pSecond) const;
    void announceWinner() const;

  public:
    Game();

    void play();
};

#endif
