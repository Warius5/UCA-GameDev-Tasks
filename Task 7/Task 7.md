# Task 7 Data Driven Movement
Advanced Programming

Ben Powell

2204331

Data Driven Movement task





## Research 

Need to look into how decorators are set up in C++ 
Decorators are an abstract class that adds new behaviours to an object.

```
  // Create a vanilla ice cream
    IceCream* vanillaIceCream = new VanillaIceCream();
    cout << "Order: " << vanillaIceCream->getDescription()
         << ", Cost: Rs." << vanillaIceCream->cost()
         << endl;

    // Wrap it with ChocolateDecorator
    IceCream* chocolateIceCream
        = new ChocolateDecorator(vanillaIceCream);
    cout << "Order: " << chocolateIceCream->getDescription()
         << ", Cost: Rs." << chocolateIceCream->cost()
         << endl;

    // Wrap it with CaramelDecorator
    IceCream* caramelIceCream
        = new CaramelDecorator(chocolateIceCream);
    cout << "Order: " << caramelIceCream->getDescription()
         << ", Cost: Rs." << caramelIceCream->cost()
         << endl;

    delete vanillaIceCream;
    delete chocolateIceCream;
    delete caramelIceCream;

    return 0;

```
used this example as a base to create my own decorator
(Introduction to Decorator Pattern in C++ | Design Patterns, 2023)




```cpp
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>

// Define the character classes
enum class CharacterClass
{
    Warrior,
    Rogue,
    Mage,
    Wizard,
    Ranger,
    Monk,
    Bard,
    Paladin,
    Cleric
};

// Character base class
class Character
{
public:
    std::string name;
    CharacterClass characterClass;
    int strength, agility, endurance, intelligence, willpower, speed, luck;

    Character(std::string n, CharacterClass c)
        : name(n), characterClass(c), strength(5), agility(5), endurance(5),
          intelligence(5), willpower(5), speed(5), luck(5) {}

    virtual void PrintCharacterInfo()
    {
        std::cout << "Name: " << name << ", Class: " << static_cast<int>(characterClass) << std::endl;
        std::cout << "Strength: " << strength << ", Agility: " << agility
                  << ", Endurance: " << endurance << ", Intelligence: " << intelligence
                  << ", Willpower: " << willpower << ", Speed: " << speed
                  << ", Luck: " << luck << std::endl;
        
    }

    virtual ~Character() = default;
};

// Factory for character creation
class CharacterFactory
{
public:
    static Character* CreateCharacter(const std::string& name, CharacterClass charClass)
    {
        Character* character = new Character(name, charClass);

        // Task for student: Implement factory logic to create character with different stats based on class
        switch (charClass)
        {
            case CharacterClass::Warrior: 
            character->strength = 10;
            character->intelligence = 3;
            
            break;
            case CharacterClass::Rogue: 
            character->agility = 10;
            character->luck = 7;
            character->strength = 4;
            break;
            case CharacterClass::Mage: 
            character->agility = 4;
            character->intelligence = 8;
            
            break;
            case CharacterClass::Wizard: 
            character->agility = 3;
            character->intelligence = 10;
            break;
            case CharacterClass::Ranger: 
            character->speed = 7;
            character->intelligence = 10;
            break;
            case CharacterClass::Monk: 
            character->agility = 6;
            character->endurance = 7;
            break;
            case CharacterClass::Bard: 
            character->luck = 15;
            character->willpower = 7;
            break;
            case CharacterClass::Paladin: 
            character->willpower = 8;
            character->strength = 8;
            character->endurance = 9;
            break;
            case CharacterClass::Cleric: 
            character->willpower = 8;
            character->strength = 4;
            break;
            
            
        }
        return character;
    }
};

// Decorator for adding abilities or modifiers to characters
class CharacterDecorator : public Character
{
protected:
    Character* character;

public:
    std::string ability;

    CharacterDecorator(Character* c, const std::string& ab) : Character(c->name, c->characterClass), character(c), ability(ab) {}

    virtual void changeStats() {}

    virtual void addAbility() {}

    void PrintCharacterInfo() override {
        character->PrintCharacterInfo();
        std::cout << "Ability: " << ability << std::endl;
    }
    
    
    
    
};


class SwordDecorator : public CharacterDecorator
{
    
   public:
    SwordDecorator(Character* character)
        : CharacterDecorator(character, "Slash") {} // Pass ability "Slash" to the constructor

    void changeStats() override {
        character->strength += 5;  // Increase strength by 5
    }

    void addAbility() override {
        ability = "Slash"; // Modify the ability
    }
};

class ShieldDecorator : public CharacterDecorator {
public:
    ShieldDecorator(Character* character)
        : CharacterDecorator(character, "Block") {}

    void changeStats() override {
        character->endurance += 5;  // Increase endurance by 5
    }

    void addAbility() override {
        ability = "Block"; // Modify the ability
    }
};



// class Decorator 
// {
//     public:
//         void updateStats();
        
//         virtual void Statchange();
        
    
    
    
// }


// Task for student: Implement a concrete decorator (e.g., EnchantedArmor, SpecialWeapon) to modify character stats
int main() {
    Character* firstGuy = CharacterFactory::CreateCharacter("GuyDude", CharacterClass::Warrior);

     // Print the character info before decorating
    firstGuy->PrintCharacterInfo();

       // Now decorate the character with a sword and shield
    SwordDecorator* decoratedWithSword = new SwordDecorator(firstGuy);
    ShieldDecorator* decoratedWithShield = new ShieldDecorator(decoratedWithSword);
    ShieldDecorator* decoratedWithOnlyShield = new ShieldDecorator(firstGuy);
    
    
    decoratedWithOnlyShield->changeStats();
    decoratedWithOnlyShield->addAbility();
    decoratedWithOnlyShield->PrintCharacterInfo();
    // Apply all decorators' changes
    decoratedWithSword->changeStats();  // Apply sword stats
    decoratedWithSword->addAbility();  // Apply sword ability
    
    decoratedWithSword->PrintCharacterInfo();
    
    decoratedWithShield->changeStats();  // Apply shield stats
    decoratedWithShield->addAbility();  // Apply shield ability
        
    // Print the updated character info
    decoratedWithShield->PrintCharacterInfo();
    // Clean up memory
    delete firstGuy;
    delete decoratedWithSword;
    delete decoratedWithShield;
    delete decoratedWithOnlyShield;
    return 0;

    // This creates a character, and then decorates it with the different items. 
    // the stat changes for these items stack together if a character is decorated with multiple of them.
}
```




This is a first version of the user inputted version, but it had issues with actually changing the stats.
``` Cpp
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <map>

// Define the character classes
enum class CharacterClass
{
    Warrior,
    Rogue,
    Mage,
    Wizard,
    Ranger,
    Monk,
    Bard,
    Paladin,
    Cleric,
    Invalid
};

// Character base class
class Character
{
public:
    std::string name;
    CharacterClass characterClass;
    int strength, agility, endurance, intelligence, willpower, speed, luck;

    Character(std::string n, CharacterClass c)
        : name(n), characterClass(c), strength(5), agility(5), endurance(5),
          intelligence(5), willpower(5), speed(5), luck(5) {}

    virtual void PrintCharacterInfo()
    {
        std::cout << "Name: " << name << ", Class: " << static_cast<int>(characterClass) << std::endl;
        std::cout << "Strength: " << strength << ", Agility: " << agility
                  << ", Endurance: " << endurance << ", Intelligence: " << intelligence
                  << ", Willpower: " << willpower << ", Speed: " << speed
                  << ", Luck: " << luck << std::endl;
        
    }

    virtual ~Character() = default;
};

// Factory for character creation
class CharacterFactory
{
public:
    static Character* CreateCharacter(const std::string& name, CharacterClass charClass)
    {
        Character* character = new Character(name, charClass);

        // Task for student: Implement factory logic to create character with different stats based on class
        switch (charClass)
        {
            case CharacterClass::Warrior: 
            character->strength = 10;
            character->intelligence = 3;
            
            break;
            case CharacterClass::Rogue: 
            character->agility = 10;
            character->luck = 7;
            character->strength = 4;
            break;
            case CharacterClass::Mage: 
            character->agility = 4;
            character->intelligence = 8;
            
            break;
            case CharacterClass::Wizard: 
            character->agility = 3;
            character->intelligence = 10;
            break;
            case CharacterClass::Ranger: 
            character->speed = 7;
            character->intelligence = 10;
            break;
            case CharacterClass::Monk: 
            character->agility = 6;
            character->endurance = 7;
            break;
            case CharacterClass::Bard: 
            character->luck = 15;
            character->willpower = 7;
            break;
            case CharacterClass::Paladin: 
            character->willpower = 8;
            character->strength = 8;
            character->endurance = 9;
            break;
            case CharacterClass::Cleric: 
            character->willpower = 8;
            character->strength = 4;
            break;
            
            
        }
        return character;
    }
};

// Decorator for adding abilities or modifiers to characters
class CharacterDecorator : public Character
{
protected:
    Character* character;

public:
    std::string ability;

    CharacterDecorator(Character* c, const std::string& ab) : Character(c->name, c->characterClass), character(c), ability(ab) {}

    virtual void changeStats() {}

    virtual void addAbility() {}

    void PrintCharacterInfo() override {
        character->PrintCharacterInfo();
        std::cout << "Ability: " << ability << std::endl;
    }
    
    
    
    
};


class SwordDecorator : public CharacterDecorator
{
    
   public:
    SwordDecorator(Character* character)
        : CharacterDecorator(character, "Slash") {} // Pass ability "Slash" to the constructor

    void changeStats() override {
        character->strength += 5;  // Increase strength by 5
    }

    void addAbility() override {
        ability = "Slash"; // Modify the ability
    }
};

class ShieldDecorator : public CharacterDecorator {
public:
    ShieldDecorator(Character* character)
        : CharacterDecorator(character, "Block") {}

    void changeStats() override {
        character->endurance += 5;  // Increase endurance by 5
    }

    void addAbility() override {
        ability = "Block"; // Modify the ability
    }
};

class HermesBootsDecorator : public CharacterDecorator {
public:
    HermesBootsDecorator(Character* character)
        : CharacterDecorator(character, "Dash") {}

    void changeStats() override {
        character->speed += 5;  // Increase speed by 5
    }

    void addAbility() override {
        ability = "Dash"; // Modify the ability
    }
};



// Function to map user input to CharacterClass
CharacterClass stringToClass(const std::string& input) {
    static std::map<std::string, CharacterClass> classMap = {
        {"Warrior", CharacterClass::Warrior},
        {"Rogue", CharacterClass::Rogue},
        {"Mage", CharacterClass::Mage},
        {"Wizard", CharacterClass::Wizard},
        {"Ranger", CharacterClass::Ranger},
        {"Monk", CharacterClass::Monk},
        {"Bard", CharacterClass::Bard},
        {"Paladin", CharacterClass::Paladin},
        {"Cleric", CharacterClass::Cleric}
    };

    auto it = classMap.find(input);
    if (it != classMap.end()) {
        return it->second;
    } else {
        return CharacterClass::Invalid; // Return invalid if input doesn't match
    }
}
// Map that takes the user selection, and searches it through to assign the correct characterclass for the player class.

// Task for student: Implement a concrete decorator (e.g., EnchantedArmor, SpecialWeapon) to modify character stats
int main() {
    Character* firstGuy = CharacterFactory::CreateCharacter("GuyDude", CharacterClass::Warrior);

     
    
    // Start of player input
    std::string className;
    std::cout << "Enter a character class (Warrior, Rogue, Mage, Wizard, Ranger, Monk, Bard, Paladin, Cleric): ";
    std::getline(std::cin, className);

    // Map user input to the corresponding CharacterClass
    CharacterClass selectedClass = stringToClass(className);

    if (selectedClass == CharacterClass::Invalid) {
        std::cout << "Invalid class name entered. Please choose a valid class." << std::endl;
        return 1; // Exit the program if the class is invalid
    }

    // Get player name
    std::string playerName;
    std::cout << "Enter your character name: ";
    std::getline(std::cin, playerName);

    // Create the character using the selected class
    Character* playerCharacter = CharacterFactory::CreateCharacter(playerName, selectedClass);

    playerCharacter->PrintCharacterInfo();
    
    
    
    
    // Giving player choice of item to pick up.
    int itemchoice;
    std::cout << "Would you like to pick up: Sword(1), Shield(2), Hermes Boots, (3)";
    std::cin >> itemchoice;
    switch (itemchoice) {
        case 1:
            playerCharacter = new SwordDecorator(playerCharacter);s
            break;
        case 2:
            playerCharacter = new ShieldDecorator(playerCharacter);
            break;
        case 3:
            playerCharacter = new HermesBootsDecorator(playerCharacter);
            break;
        default:
            std::cout << "Invalid choice! No decoration applied." << std::endl;
            return 1;  // Exit with an error code
    }
    
    
    playerCharacter->PrintCharacterInfo();
    
    delete playerCharacter;
    
    return 0;
}
```

Dev Journal: character creator

To start it is important to define certain stats of each class, using switches to set these class differences. 



Creating a decorator class to have the items within, as this would allow the stats items and stats called in from one place for efficiency. 
A virtual function was thought to be used with this but it was decided to revert back to the decorator as a subclass of the character as this will allow the decorator to add/functions to the character.

With this new setup, a decorator base with an ability attached to it. A child decorator for sword was added which passed “slash” as the ability. Following this, a shield decorator could be added for further testing of the decorator function. This would then, in theory, give the player a block ability.

Created examples of the different characters with items for testing to ensure it all works as necessary. 
Tye shield stats didn't work as intended until reimplementation.

Realised that the changestats of the first way i was doing it wouldn't work for the user input version.

```cpp
 switch (itemchoice) {
        case 1:
            playerCharacter = new SwordDecorator(playerCharacter);
            playerCharacter->changeStats();
            break;
        case 2:
            playerCharacter = new ShieldDecorator(playerCharacter);
            playerCharacter->changeStats();
            break;
        case 3:
            playerCharacter = new HermesBootsDecorator(playerCharacter);
            playerCharacter->changeStats();
            break;
        default:
```
to fix this i needed to change it so that:
```cpp
case 1: {
        auto swordDecorator = new SwordDecorator(playerCharacter);
        swordDecorator->changeStats();
        playerCharacter = swordDecorator; 
        break;
    }
    case 2: {
        auto shieldDecorator = new ShieldDecorator(playerCharacter);
        shieldDecorator->changeStats();
        playerCharacter = shieldDecorator; 
        break;
    }
    case 3: {
        auto bootsDecorator = new HermesBootsDecorator(playerCharacter);
        bootsDecorator->changeStats();
        playerCharacter = bootsDecorator; 
        break;
    }
```
this makes the boots decorator use the change stats method, before then turning it back into the player character.



### Full code
```cpp
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <map>

// Define the character classes
enum class CharacterClass
{
    Warrior,
    Rogue,
    Mage,
    Wizard,
    Ranger,
    Monk,
    Bard,
    Paladin,
    Cleric,
    Invalid
};

// Character base class
class Character
{
public:
    std::string name;
    CharacterClass characterClass;
    int strength, agility, endurance, intelligence, willpower, speed, luck;

    Character(std::string n, CharacterClass c)
        : name(n), characterClass(c), strength(5), agility(5), endurance(5),
          intelligence(5), willpower(5), speed(5), luck(5) {}

    virtual void PrintCharacterInfo()
    {
        std::cout << "Name: " << name << ", Class: " << static_cast<int>(characterClass) << std::endl;
        std::cout << "Strength: " << strength << ", Agility: " << agility
                  << ", Endurance: " << endurance << ", Intelligence: " << intelligence
                  << ", Willpower: " << willpower << ", Speed: " << speed
                  << ", Luck: " << luck << std::endl;
        
    }

    virtual ~Character() = default;
};
// sets up character, and has output method

// Factory for character creation
class CharacterFactory
{
public:
    static Character* CreateCharacter(const std::string& name, CharacterClass charClass)
    {
        Character* character = new Character(name, charClass);

        // Task for student: Implement factory logic to create character with different stats based on class
        switch (charClass)
        {
            case CharacterClass::Warrior: 
            character->strength = 10;
            character->intelligence = 3;
            
            break;
            case CharacterClass::Rogue: 
            character->agility = 10;
            character->luck = 7;
            character->strength = 4;
            break;
            case CharacterClass::Mage: 
            character->agility = 4;
            character->intelligence = 8;
            
            break;
            case CharacterClass::Wizard: 
            character->agility = 3;
            character->intelligence = 10;
            break;
            case CharacterClass::Ranger: 
            character->speed = 7;
            character->intelligence = 10;
            break;
            case CharacterClass::Monk: 
            character->agility = 6;
            character->endurance = 7;
            break;
            case CharacterClass::Bard: 
            character->luck = 15;
            character->willpower = 7;
            break;
            case CharacterClass::Paladin: 
            character->willpower = 8;
            character->strength = 8;
            character->endurance = 9;
            break;
            case CharacterClass::Cleric: 
            character->willpower = 8;
            character->strength = 4;
            break;
            
            
        }
        return character;
    }
};
// setting up the characters 
// Decorator for adding abilities or modifiers to characters
class CharacterDecorator : public Character
{
protected:
    Character* character;

public:
    std::string ability;

    CharacterDecorator(Character* c, const std::string& ab) : Character(c->name, c->characterClass), character(c), ability(ab) {}

    virtual void changeStats() {}

    virtual void addAbility() {}

    void PrintCharacterInfo() override {
        character->PrintCharacterInfo();
        std::cout << "Ability: " << ability << std::endl;
    }
    
    
    
    
};
// Decorator adding the extra methods; giving ability, changing the stats to give the updated items stats.

class SwordDecorator : public CharacterDecorator
{
    
   public:
    SwordDecorator(Character* character)
        : CharacterDecorator(character, "Slash") {} // Pass ability "Slash" to the constructor

    void changeStats() override {
        character->strength = character->strength + 5;  // Increase strength by 5
    }

    void addAbility() override {
        ability = "Slash"; // Modify the ability
    }
};

class ShieldDecorator : public CharacterDecorator {
public:
    ShieldDecorator(Character* character)
        : CharacterDecorator(character, "Block") {}

    void changeStats() override {
        character->endurance += 5;  // Increase endurance by 5
    }

    void addAbility() override {
        ability = "Block"; // Modify the ability
    }
};

class HermesBootsDecorator : public CharacterDecorator {
public:
    HermesBootsDecorator(Character* character)
        : CharacterDecorator(character, "Dash") {}

    void changeStats() override {
        character->speed += 5;  // Increase speed by 5
    }

    void addAbility() override {
        ability = "Dash"; // Modify the ability
    }
};



// Function to map user input to CharacterClass
CharacterClass stringToClass(const std::string& input) {
    static std::map<std::string, CharacterClass> classMap = {
        {"Warrior", CharacterClass::Warrior},
        {"Rogue", CharacterClass::Rogue},
        {"Mage", CharacterClass::Mage},
        {"Wizard", CharacterClass::Wizard},
        {"Ranger", CharacterClass::Ranger},
        {"Monk", CharacterClass::Monk},
        {"Bard", CharacterClass::Bard},
        {"Paladin", CharacterClass::Paladin},
        {"Cleric", CharacterClass::Cleric}
    };

    auto it = classMap.find(input);
    if (it != classMap.end()) {
        return it->second;
    } else {
        return CharacterClass::Invalid; // Return invalid if input doesn't match
    }
}


// Task for student: Implement a concrete decorator (e.g., EnchantedArmor, SpecialWeapon) to modify character stats
int main() {
    Character* firstGuy = CharacterFactory::CreateCharacter("GuyDude", CharacterClass::Warrior);

     // Print the character info before decorating
    /*firstGuy->PrintCharacterInfo();

       // Now decorate the character with a sword and shield
    SwordDecorator* decoratedWithSword = new SwordDecorator(firstGuy);
    ShieldDecorator* decoratedWithShield = new ShieldDecorator(decoratedWithSword);
    ShieldDecorator* decoratedWithOnlyShield = new ShieldDecorator(firstGuy);
    
    
    decoratedWithOnlyShield->changeStats();
    decoratedWithOnlyShield->addAbility();
    decoratedWithOnlyShield->PrintCharacterInfo();
    // Apply all decorators' changes
    decoratedWithSword->changeStats();  // Apply sword stats
    decoratedWithSword->addAbility();  // Apply sword ability
    
    decoratedWithSword->PrintCharacterInfo();
    
    decoratedWithShield->changeStats();  // Apply shield stats
    decoratedWithShield->addAbility();  // Apply shield ability
        
    // Print the updated character info
    decoratedWithShield->PrintCharacterInfo();
    // Clean up memory
    delete firstGuy;
    delete decoratedWithSword;
    delete decoratedWithShield;
    delete decoratedWithOnlyShield;*/
    
    
    // Start of player input
    std::string className;
    std::cout << "Enter a character class (Warrior, Rogue, Mage, Wizard, Ranger, Monk, Bard, Paladin, Cleric): ";
    std::getline(std::cin, className);

    // Map user input to the corresponding CharacterClass
    CharacterClass selectedClass = stringToClass(className);

    if (selectedClass == CharacterClass::Invalid) {
        std::cout << "Invalid class name entered. Please choose a valid class." << std::endl;
        return 1; // Exit the program if the class is invalid
    }

    // Get player name
    std::string playerName;
    std::cout << "Enter your character name: ";
    std::getline(std::cin, playerName);

    // Create the character using the selected class
    Character* playerCharacter = CharacterFactory::CreateCharacter(playerName, selectedClass);

    playerCharacter->PrintCharacterInfo();
    
    
    
    
    // Giving player choice of item to pick up.
    int itemchoice;
    std::cout << "Would you like to pick up: Sword(1), Shield(2), Hermes Boots, (3)";
    std::cin >> itemchoice;
    switch (itemchoice) {
    case 1: {
        auto swordDecorator = new SwordDecorator(playerCharacter);
        swordDecorator->changeStats();
        playerCharacter = swordDecorator; // Update the pointer to the decorated character
        break;
    }
    case 2: {
        auto shieldDecorator = new ShieldDecorator(playerCharacter);
        shieldDecorator->changeStats();
        playerCharacter = shieldDecorator; // Update the pointer to the decorated character
        break;
    }
    case 3: {
        auto bootsDecorator = new HermesBootsDecorator(playerCharacter);
        bootsDecorator->changeStats();
        playerCharacter = bootsDecorator; // Update the pointer to the decorated character
        break;
    }
    default:
        std::cout << "Invalid choice! No decoration applied." << std::endl;
        break;
}
    
    
    playerCharacter->PrintCharacterInfo();
    
    delete playerCharacter;
    
    return 0;
}
```
```
Enter a character class (Warrior, Rogue, Mage, Wizard, Ranger, Monk, Bard, Paladin, Cleric): Bard
Enter your character name: Ben
Name: Ben, Class: 6
Strength: 5, Agility: 5, Endurance: 5, Intelligence: 5, Willpower: 7, Speed: 5, Luck: 15
Would you like to pick up: Sword(1), Shield(2), Hermes Boots, (3)1
Name: Ben, Class: 6
Strength: 10, Agility: 5, Endurance: 5, Intelligence: 5, Willpower: 7, Speed: 5, Luck: 15
Ability: Slash
```


## Reflection 

Learning about and implementing a bit more of an advanced object oriented conecpt was interesting. I found it slightly difficult to see what the main factors of implementation were to what a decorator looked like and could do. But after seeing how useful it could be to create modular additions to objects, it gives a good idea on the possibilities of using it scale wise.

## Bibliography
Introduction to Decorator Pattern in C++ | Design Patterns (2023) At: https://www.geeksforgeeks.org/introduction-to-decorator-pattern-in-c-design-patterns/ (Accessed  06/12/2024).
