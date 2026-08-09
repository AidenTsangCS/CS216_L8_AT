// Aiden Tsang
// CS216 Lab 8 - member functions of the Game class

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "Army.h"
#include "Creature.h"
#include "Game.h"
#include "Utilities.h"

using namespace std;

Game::Game() {
}

void Game::play() {
    int armySize = readInt(SIZE_PROMPT, MIN_ARMY_SIZE, MAX_ARMY_SIZE);
    string *pNames = loadNames(armySize * ARMIES_PER_BATTLE);

    if (pNames != nullptr) {
        bool isReady = buildArmies(armySize, pNames);

        delete[] pNames;
        pNames = nullptr;

        if (isReady) {
            runBattleSeries(armySize);
        }
    }
}

string *Game::loadNames(int neededCount) const {
    string *pNames = nullptr;
    string oneName = DEFAULT_NAME;
    int nameCount = 0;
    ifstream namesFile(NAMES_FILE.c_str());

    if (!namesFile.is_open()) {
        cout << "\nCould not open " << NAMES_FILE << endl;
    }
    else {
        try {
            pNames = new string[neededCount];

            while (nameCount < neededCount
                   && getline(namesFile, oneName)) {
                if (countAlphabetic(oneName) > 0) {
                    pNames[nameCount] = oneName;
                    ++nameCount;
                }
            }

            if (nameCount < neededCount) {
                delete[] pNames;
                pNames = nullptr;
                cout << "\n" << NAMES_FILE << " holds only " << nameCount
                     << " of the " << neededCount << " names needed"
                     << endl;
            }
        }
        catch (const bad_alloc &error) {
            pNames = nullptr;
            cout << "\nThere is not enough memory to read the creature "
                    "names" << endl;
        }

        namesFile.close();
    }

    return pNames;
}

bool Game::buildArmies(int armySize, const string *pNames) {
    string nameOne = readArmyName(ARMY_ONE_PROMPT);
    string nameTwo = readArmyName(ARMY_TWO_PROMPT);
    bool isReady = armyOne.createArmy(nameOne, armySize, pNames,
                                      FIRST_NAME_INDEX);

    if (isReady) {
        isReady = armyTwo.createArmy(nameTwo, armySize, pNames, armySize);
    }

    return isReady;
}

void Game::runBattleSeries(int armySize) {
    int rematchChoice = REMATCH_YES;

    while (rematchChoice == REMATCH_YES) {
        runBattle(armySize);
        rematchChoice = readInt(REMATCH_PROMPT, REMATCH_YES, REMATCH_NO);

        switch (rematchChoice) {
        case REMATCH_YES:
            armyOne.resetCreatures();
            armyTwo.resetCreatures();
            cout << "\nBoth armies recovered; every strength and health "
                    "was rolled again" << endl;
            break;
        case REMATCH_NO:
            cout << "\nReturning to the main menu" << endl;
            break;
        }
    }
}

void Game::runBattle(int armySize) {
    cout << "\n";
    printDivider(DUEL_WIDTH);
    cout << "NEW BATTLE" << endl;
    printDivider(DUEL_WIDTH);

    armyOne.print(BEFORE_LABEL);
    armyTwo.print(BEFORE_LABEL);
    printDuelHeader();

    for (int position = 0; position < armySize; ++position) {
        runDuel(position);
    }

    armyOne.print(AFTER_LABEL);
    armyTwo.print(AFTER_LABEL);
    announceWinner();
}

void Game::printDuelHeader() const {
    cout << "\n" << left << setw(FIGHTER_COL) << "Attacker"
         << setw(ARMY_COL) << "Army"
         << right << setw(NUM_COL) << "Damage"
         << setw(COLUMN_GAP_WIDTH) << ""
         << left << setw(FIGHTER_COL) << "Defender"
         << setw(ARMY_COL) << "Army"
         << right << setw(NUM_COL) << "Before"
         << setw(NUM_COL) << "After" << endl;
}

void Game::runDuel(int position) {
    Creature *pFirst = armyOne.getCreature(position);
    Creature *pSecond = armyTwo.getCreature(position);

    if (pFirst == nullptr || pSecond == nullptr) {
        cout << "\nDuel " << (position + 1)
             << " could not start; a creature is missing" << endl;
    }
    else {
        cout << "\n-- Duel " << (position + 1) << ": " << pFirst->getName()
             << " of " << armyOne.getName() << " vs "
             << pSecond->getName() << " of " << armyTwo.getName() << " --"
             << endl;

        if (isChanceHit(FIRST_STRIKE_CHANCE)) {
            exchangeBlows(pFirst, armyOne.getName(), pSecond,
                          armyTwo.getName());
        }
        else {
            exchangeBlows(pSecond, armyTwo.getName(), pFirst,
                          armyOne.getName());
        }

        announceDuelWinner(pFirst, pSecond);
    }
}

void Game::exchangeBlows(Creature *pAttacker, const string &attackerArmy,
                         Creature *pDefender,
                         const string &defenderArmy) const {
    Creature *pCurrent = pAttacker;
    Creature *pTarget = pDefender;
    string currentArmy = attackerArmy;
    string targetArmy = defenderArmy;

    while (pCurrent->getHealth() > MIN_VALID_HEALTH
           && pTarget->getHealth() > MIN_VALID_HEALTH) {
        strike(pCurrent, currentArmy, pTarget, targetArmy);

        Creature *pNextAttacker = pTarget;
        string nextArmy = targetArmy;

        pTarget = pCurrent;
        targetArmy = currentArmy;
        pCurrent = pNextAttacker;
        currentArmy = nextArmy;
    }
}

void Game::strike(Creature *pAttacker, const string &attackerArmy,
                  Creature *pDefender,
                  const string &defenderArmy) const {
    int damage = pAttacker->getDamage();
    int healthBefore = pDefender->getHealth();

    pDefender->takeDamage(damage);

    cout << left << setw(FIGHTER_COL) << pAttacker->getName()
         << setw(ARMY_COL) << attackerArmy
         << right << setw(NUM_COL) << damage
         << setw(COLUMN_GAP_WIDTH) << ""
         << left << setw(FIGHTER_COL) << pDefender->getName()
         << setw(ARMY_COL) << defenderArmy
         << right << setw(NUM_COL) << healthBefore
         << setw(NUM_COL) << pDefender->getHealth() << endl;
}

void Game::announceDuelWinner(const Creature *pFirst,
                              const Creature *pSecond) const {
    const Creature *pWinner = pSecond;
    const Creature *pLoser = pFirst;

    if (pFirst->getHealth() > MIN_VALID_HEALTH) {
        pWinner = pFirst;
        pLoser = pSecond;
    }

    cout << ">> " << pWinner->getName() << " defeated "
         << pLoser->getName() << endl;
}

void Game::announceWinner() const {
    int totalOne = armyOne.getTotalHealth();
    int totalTwo = armyTwo.getTotalHealth();
    string resultMessage = ">>> The battle ends in a tie <<<";

    if (totalOne > totalTwo) {
        resultMessage = ">>> " + armyOne.getName()
                        + " wins the battle <<<";
    }
    else if (totalTwo > totalOne) {
        resultMessage = ">>> " + armyTwo.getName()
                        + " wins the battle <<<";
    }

    printDivider(DUEL_WIDTH);
    cout << resultMessage
         << "\n" << armyOne.getName() << " overall health: " << totalOne
         << "\n" << armyTwo.getName() << " overall health: " << totalTwo
         << endl;
    printDivider(DUEL_WIDTH);
}