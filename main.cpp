// Aiden Tsang
// CS216 Lab 8 - driver of the battle arena

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>

#include "Game.h"
#include "Utilities.h"

using namespace std;

const string MENU_PROMPT = "\n\nBattle Arena Menu:\n"
                           "1. Battle\n"
                           "2. Quit\n"
                           "Enter your choice: ";
const string INVALID_CHOICE_MESSAGE = "Invalid menu choice; please pick a "
                                      "listed option";

enum MenuOption { BATTLE = 1, QUIT };

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    try {
        Game battleGame;
        int menuChoice = QUIT;

        do {
            menuChoice = readInt(MENU_PROMPT, numeric_limits<int>::min(),
                                 numeric_limits<int>::max());

            switch (menuChoice) {
            case BATTLE:
                battleGame.play();
                break;
            case QUIT:
                cout << "\nThanks for playing. Goodbye!" << endl;
                break;
            default:
                clearFailedCin(INVALID_CHOICE_MESSAGE);
            }
        } while (menuChoice != QUIT);
    }
    catch (const bad_alloc &error) {
        cout << "\nThe program ran out of memory and cannot continue" << endl;
    }

    return 0;
}

/* Test runs

Test run #1 - menu validation, army size and army name validation,
an army of one creature, a rematch with the same creatures, and a
second battle with a full army of twelve creatures

Battle Arena Menu:
1. Battle
2. Quit
Enter your choice: abc

Invalid entry; please enter a whole number


Battle Arena Menu:
1. Battle
2. Quit
Enter your choice: 7

Invalid menu choice; please pick a listed option


Battle Arena Menu:
1. Battle
2. Quit
Enter your choice: 1

Enter the number of creatures in each army (1 to 12): 0

Please enter a whole number from 1 to 12

Enter the number of creatures in each army (1 to 12): 13

Please enter a whole number from 1 to 12

Enter the number of creatures in each army (1 to 12): x

Invalid entry; please enter a whole number

Enter the number of creatures in each army (1 to 12): 1
Enter the name of army #1 (3 to 9 letters): Ab

An army name needs from 3 to 9 letters
Enter the name of army #1 (3 to 9 letters): Reinforcements

An army name needs from 3 to 9 letters
Enter the name of army #1 (3 to 9 letters): 12345

An army name needs from 3 to 9 letters
Enter the name of army #1 (3 to 9 letters): Red
Enter the name of army #2 (3 to 9 letters): Battalion

=========================================================================================
NEW BATTLE
=========================================================================================

Red Stats before the Battle
Creature    Type          Strength    Health
============================================
Morgas      demon               76        97
============================================
Overall health of Red: 97

Battalion Stats before the Battle
Creature    Type          Strength    Health
============================================
Thorfin     elf                 53       147
============================================
Overall health of Battalion: 147

Attacker               Army       Damage  Defender               Army       Before  After

-- Duel 1: Morgas the Demon of Red vs Thorfin the Elf of Battalion --
Thorfin the Elf        Battalion      41  Morgas the Demon       Red            97     56
Morgas the Demon       Red            58  Thorfin the Elf        Battalion     147     89
Thorfin the Elf        Battalion      10  Morgas the Demon       Red            56     46
Morgas the Demon       Red            75  Thorfin the Elf        Battalion      89     14
Thorfin the Elf        Battalion       8  Morgas the Demon       Red            46     38
Morgas the Demon       Red            30  Thorfin the Elf        Battalion      14      0
>> Morgas the Demon defeated Thorfin the Elf

Red Stats after the Battle
Creature    Type          Strength    Health
============================================
Morgas      demon               76        38
============================================
Overall health of Red: 38

Battalion Stats after the Battle
Creature    Type          Strength    Health
============================================
Thorfin     elf                 53         0
============================================
Overall health of Battalion: 0
=========================================================================================
>>> Red wins the battle <<<
Red overall health: 38
Battalion overall health: 0
=========================================================================================


Rematch Menu:
1. Fight again with the same creatures
2. Back to the main menu
Enter your choice: 3

Please enter a whole number from 1 to 2


Rematch Menu:
1. Fight again with the same creatures
2. Back to the main menu
Enter your choice: !

Invalid entry; please enter a whole number


Rematch Menu:
1. Fight again with the same creatures
2. Back to the main menu
Enter your choice: 1

Both armies recovered; every strength and health was rolled again

=========================================================================================
NEW BATTLE
=========================================================================================

Red Stats before the Battle
Creature    Type          Strength    Health
============================================
Morgas      demon              114       146
============================================
Overall health of Red: 146

Battalion Stats before the Battle
Creature    Type          Strength    Health
============================================
Thorfin     elf                 54        49
============================================
Overall health of Battalion: 49

Attacker               Army       Damage  Defender               Army       Before  After

-- Duel 1: Morgas the Demon of Red vs Thorfin the Elf of Battalion --
Thorfin the Elf        Battalion      80  Morgas the Demon       Red           146     66
Morgas the Demon       Red            94  Thorfin the Elf        Battalion      49      0
>> Morgas the Demon defeated Thorfin the Elf

Red Stats after the Battle
Creature    Type          Strength    Health
============================================
Morgas      demon              114        66
============================================
Overall health of Red: 66

Battalion Stats after the Battle
Creature    Type          Strength    Health
============================================
Thorfin     elf                 54         0
============================================
Overall health of Battalion: 0
=========================================================================================
>>> Red wins the battle <<<
Red overall health: 66
Battalion overall health: 0
=========================================================================================


Rematch Menu:
1. Fight again with the same creatures
2. Back to the main menu
Enter your choice: 2

Returning to the main menu


Battle Arena Menu:
1. Battle
2. Quit
Enter your choice: 1

Enter the number of creatures in each army (1 to 12): 12
Enter the name of army #1 (3 to 9 letters): Ironhelm
Enter the name of army #2 (3 to 9 letters): Aid

=========================================================================================
NEW BATTLE
=========================================================================================

Ironhelm Stats before the Battle
Creature    Type          Strength    Health
============================================
Morgas      cyberelf           198       231
Thorfin     cyberelf           227        50
Petra       elf                236       150
Karan       demon              258       206
Seren       elf                262        95
Lunara      demon              227       188
Lagnar      balrog             163        89
Orrin       cyberelf           157       144
Quillon     cyberelf            55       213
Morwen      balrog             188       181
Chester     cyberelf           144       236
Ragnar      cyberelf           147       132
============================================
Overall health of Ironhelm: 1915

Aid Stats before the Battle
Creature    Type          Strength    Health
============================================
Kaelith     balrog             253        73
Aldric      cyberelf           181       195
Grisha      balrog             232       257
Isolde      elf                144       223
Dorian      demon              186        62
Hollis      cyberelf            55       102
Faelan      elf                221       220
Cassia      balrog             126       221
Bricta      elf                 86       177
Varek       demon              173        55
Nimue       cyberelf           200       114
Osric       balrog             119       133
============================================
Overall health of Aid: 1832

Attacker               Army       Damage  Defender               Army       Before  After

-- Duel 1: Morgas the Cyberelf of Ironhelm vs Kaelith the Balrog of Aid --
Kaelith the Balrog     Aid           167  Morgas the Cyberelf    Ironhelm      231     64
Morgas the Cyberelf    Ironhelm       74  Kaelith the Balrog     Aid            73      0
>> Morgas the Cyberelf defeated Kaelith the Balrog

-- Duel 2: Thorfin the Cyberelf of Ironhelm vs Aldric the Cyberelf of Aid --
Thorfin the Cyberelf   Ironhelm       25  Aldric the Cyberelf    Aid           195    170
Aldric the Cyberelf    Aid           102  Thorfin the Cyberelf   Ironhelm       50      0
>> Aldric the Cyberelf defeated Thorfin the Cyberelf

-- Duel 3: Petra the Elf of Ironhelm vs Grisha the Balrog of Aid --
Grisha the Balrog      Aid           452  Petra the Elf          Ironhelm      150      0
>> Grisha the Balrog defeated Petra the Elf

-- Duel 4: Karan the Demon of Ironhelm vs Isolde the Elf of Aid --
Karan the Demon        Ironhelm      253  Isolde the Elf         Aid           223      0
>> Karan the Demon defeated Isolde the Elf

-- Duel 5: Seren the Elf of Ironhelm vs Dorian the Demon of Aid --
Dorian the Demon       Aid           166  Seren the Elf          Ironhelm       95      0
>> Dorian the Demon defeated Seren the Elf

-- Duel 6: Lunara the Demon of Ironhelm vs Hollis the Cyberelf of Aid --
Lunara the Demon       Ironhelm      106  Hollis the Cyberelf    Aid           102      0
>> Lunara the Demon defeated Hollis the Cyberelf

-- Duel 7: Lagnar the Balrog of Ironhelm vs Faelan the Elf of Aid --
Faelan the Elf         Aid           260  Lagnar the Balrog      Ironhelm       89      0
>> Faelan the Elf defeated Lagnar the Balrog

-- Duel 8: Orrin the Cyberelf of Ironhelm vs Cassia the Balrog of Aid --
Orrin the Cyberelf     Ironhelm       97  Cassia the Balrog      Aid           221    124
Cassia the Balrog      Aid            71  Orrin the Cyberelf     Ironhelm      144     73
Orrin the Cyberelf     Ironhelm       64  Cassia the Balrog      Aid           124     60
Cassia the Balrog      Aid            84  Orrin the Cyberelf     Ironhelm       73      0
>> Cassia the Balrog defeated Orrin the Cyberelf

-- Duel 9: Quillon the Cyberelf of Ironhelm vs Bricta the Elf of Aid --
Bricta the Elf         Aid           124  Quillon the Cyberelf   Ironhelm      213     89
Quillon the Cyberelf   Ironhelm       55  Bricta the Elf         Aid           177    122
Bricta the Elf         Aid            75  Quillon the Cyberelf   Ironhelm       89     14
Quillon the Cyberelf   Ironhelm       11  Bricta the Elf         Aid           122    111
Bricta the Elf         Aid           152  Quillon the Cyberelf   Ironhelm       14      0
>> Bricta the Elf defeated Quillon the Cyberelf

-- Duel 10: Morwen the Balrog of Ironhelm vs Varek the Demon of Aid --
Varek the Demon        Aid           129  Morwen the Balrog      Ironhelm      181     52
Morwen the Balrog      Ironhelm       75  Varek the Demon        Aid            55      0
>> Morwen the Balrog defeated Varek the Demon

-- Duel 11: Chester the Cyberelf of Ironhelm vs Nimue the Cyberelf of Aid --
Nimue the Cyberelf     Aid            96  Chester the Cyberelf   Ironhelm      236    140
Chester the Cyberelf   Ironhelm      141  Nimue the Cyberelf     Aid           114      0
>> Chester the Cyberelf defeated Nimue the Cyberelf

-- Duel 12: Ragnar the Cyberelf of Ironhelm vs Osric the Balrog of Aid --
Ragnar the Cyberelf    Ironhelm       49  Osric the Balrog       Aid           133     84
Osric the Balrog       Aid           166  Ragnar the Cyberelf    Ironhelm      132      0
>> Osric the Balrog defeated Ragnar the Cyberelf

Ironhelm Stats after the Battle
Creature    Type          Strength    Health
============================================
Morgas      cyberelf           198        64
Thorfin     cyberelf           227         0
Petra       elf                236         0
Karan       demon              258       206
Seren       elf                262         0
Lunara      demon              227       188
Lagnar      balrog             163         0
Orrin       cyberelf           157         0
Quillon     cyberelf            55         0
Morwen      balrog             188        52
Chester     cyberelf           144       140
Ragnar      cyberelf           147         0
============================================
Overall health of Ironhelm: 650

Aid Stats after the Battle
Creature    Type          Strength    Health
============================================
Kaelith     balrog             253         0
Aldric      cyberelf           181       170
Grisha      balrog             232       257
Isolde      elf                144         0
Dorian      demon              186        62
Hollis      cyberelf            55         0
Faelan      elf                221       220
Cassia      balrog             126        60
Bricta      elf                 86       111
Varek       demon              173         0
Nimue       cyberelf           200         0
Osric       balrog             119        84
============================================
Overall health of Aid: 964
=========================================================================================
>>> Aid wins the battle <<<
Ironhelm overall health: 650
Aid overall health: 964
=========================================================================================


Rematch Menu:
1. Fight again with the same creatures
2. Back to the main menu
Enter your choice: 2

Returning to the main menu


Battle Arena Menu:
1. Battle
2. Quit
Enter your choice: 2

Thanks for playing. Goodbye!


Test run #2 - the input file does not hold enough creature names

Battle Arena Menu:
1. Battle
2. Quit
Enter your choice: 1

Enter the number of creatures in each army (1 to 12): 3

in_creature_names.txt holds only 3 of the 6 names needed


Battle Arena Menu:
1. Battle
2. Quit
Enter your choice: 2

Thanks for playing. Goodbye!


Test run #3 - the input file is missing

Battle Arena Menu:
1. Battle
2. Quit
Enter your choice: 1

Enter the number of creatures in each army (1 to 12): 2

Could not open in_creature_names.txt


Battle Arena Menu:
1. Battle
2. Quit
Enter your choice: 2

Thanks for playing. Goodbye!

*/
