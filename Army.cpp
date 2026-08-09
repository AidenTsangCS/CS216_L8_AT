// Aiden Tsang
// CS216 Lab 8 - member functions of the Army class

#include <iomanip>
#include <iostream>
#include <string>

#include "Army.h"
#include "Balrog.h"
#include "Creature.h"
#include "Cyberelf.h"
#include "Demon.h"
#include "Elf.h"
#include "Utilities.h"

using namespace std;

Army::Army() {
    setArmy(DEFAULT_ARMY_NAME, DEFAULT_ARMY_SIZE, nullptr);
}

Army::Army(const Army &rhs) {
    copyArmy(rhs);
}

Army::~Army() {
    releaseCreatures(ppCreatures, size);
    setArmy(INVALID_ARMY_NAME, INVALID_ARMY_SIZE, nullptr);
}

Army &Army::operator=(const Army &rhs) {
    if (this != &rhs) {
        copyArmy(rhs);
    }

    return *this;
}

void Army::setArmy(const string &newName, int newSize,
                   Creature **ppNewCreatures) {
    name = newName;
    size = newSize;
    ppCreatures = ppNewCreatures;
}

void Army::copyArmy(const Army &rhs) {
    if (rhs.ppCreatures == nullptr || rhs.size < MIN_ARMY_SIZE) {
        releaseCreatures(ppCreatures, size);
        setArmy(rhs.name, DEFAULT_ARMY_SIZE, nullptr);
    }
    else {
        Creature **ppTemp = buildCreatures(rhs.size, &rhs, nullptr,
                                           FIRST_NAME_INDEX);

        if (ppTemp != nullptr) {
            releaseCreatures(ppCreatures, size);
            setArmy(rhs.name, rhs.size, ppTemp);
        }
    }
}

CreatureType Army::randomType() const {
    return static_cast<CreatureType>(randomInRange(DEMON, CYBERELF));
}

Creature *Army::createCreature(CreatureType type, const string &newName,
                               int newStrength, int newHealth) const {
    Creature *pNew = nullptr;

    switch (type) {
    case DEMON:
        pNew = new Demon(newName, newStrength, newHealth);
        break;
    case BALROG:
        pNew = new Balrog(newName, newStrength, newHealth);
        break;
    case ELF:
        pNew = new Elf(newName, newStrength, newHealth);
        break;
    case CYBERELF:
        pNew = new Cyberelf(newName, newStrength, newHealth);
        break;
    }

    return pNew;
}

Creature **Army::buildCreatures(int newSize, const Army *pSource,
                                const string *pNames,
                                int startIndex) const {
    Creature **ppTemp = nullptr;

    try {
        ppTemp = new Creature *[newSize] { nullptr };

        for (int i = 0; i < newSize; ++i) {
            if (pSource == nullptr) {
                ppTemp[i] = createCreature(
                    randomType(), pNames[startIndex + i],
                    randomInRange(MIN_ARMY_STAT, MAX_ARMY_STAT),
                    randomInRange(MIN_ARMY_STAT, MAX_ARMY_STAT));
            }
            else {
                Creature *pOriginal = pSource->ppCreatures[i];

                ppTemp[i] = createCreature(pOriginal->getType(),
                                           pOriginal->getId(),
                                           pOriginal->getStrength(),
                                           pOriginal->getHealth());
            }
        }
    }
    catch (const bad_alloc &error) {
        releaseCreatures(ppTemp, newSize);
        cout << "\nThere is not enough memory for an army of " << newSize
             << " creatures; the army was left unchanged" << endl;
    }

    return ppTemp;
}

void Army::releaseCreatures(Creature **&ppList, int count) const {
    if (ppList != nullptr) {
        for (int i = 0; i < count; ++i) {
            delete ppList[i];
            ppList[i] = nullptr;
        }

        delete[] ppList;
        ppList = nullptr;
    }
}

bool Army::createArmy(const string &newName, int newSize,
                      const string *pNames, int startIndex) {
    bool isSuccess = false;
    bool isValid = countAlphabetic(newName) >= MIN_ARMY_NAME_LETTERS
                   && newSize >= MIN_ARMY_SIZE && newSize <= MAX_ARMY_SIZE
                   && pNames != nullptr && startIndex >= FIRST_NAME_INDEX;

    if (!isValid) {
        cout << "\nInvalid army record; the army was not created" << endl;
    }
    else {
        Creature **ppTemp = buildCreatures(newSize, nullptr, pNames,
                                           startIndex);

        if (ppTemp != nullptr) {
            releaseCreatures(ppCreatures, size);
            setArmy(newName, newSize, ppTemp);
            isSuccess = true;
        }
    }

    return isSuccess;
}

void Army::resetCreatures() {
    if (ppCreatures != nullptr) {
        for (int i = 0; i < size; ++i) {
            ppCreatures[i]->reset();
        }
    }
}

string Army::getName() const {
    return name;
}

int Army::getSize() const {
    return size;
}

int Army::getTotalHealth() const {
    int total = 0;

    if (ppCreatures != nullptr) {
        for (int i = 0; i < size; ++i) {
            total = total + ppCreatures[i]->getHealth();
        }
    }

    return total;
}

Creature *Army::getCreature(int index) const {
    Creature *pFound = nullptr;

    if (ppCreatures != nullptr && index >= FIRST_NAME_INDEX
        && index < size) {
        pFound = ppCreatures[index];
    }

    return pFound;
}
void Army::print(const string &label) const {
    cout << "\n" << name << " Stats " << label << endl;

    if (ppCreatures == nullptr || size < MIN_ARMY_SIZE) {
        cout << "This army is empty" << endl;
    }
    else {
        cout << left << setw(ID_COL) << "Creature"
             << setw(TYPE_COL) << "Type"
             << right << setw(STAT_COL) << "Strength"
             << setw(STAT_COL) << "Health" << endl;
        printDivider(STATS_WIDTH);

        for (int i = 0; i < size; ++i) {
            cout << ppCreatures[i]->toString() << endl;
        }

        printDivider(STATS_WIDTH);
        cout << "Overall health of " << name << ": " << getTotalHealth()
             << endl;
    }
}
