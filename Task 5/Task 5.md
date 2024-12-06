# Task 5 Data Driven Movement
Advanced Programming

Ben Powell

2204331

Spellbook Search task
 

## Research
C++ string / input functions that could be useful
Due to doing previous validation of inputs in the past, making sure that the search is all lower case and of the same type helps with search for things, and reduces the amount of user error caused by using capital letters.

Found the use of the std transform function which performs functions on strings. (std::transform - cppreference.com, s.d.)
The lowername parameters are then use to show the start and end of the range of characters the string will be transformed on.
The toLower is then use to determine the funciton that will happen onto the characters in the range set.(std::tolower - cppreference.com, s.d.)
string::npos is used to determine whether the search item has been found as it represnets the largest possible value.


```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Define the target types
enum class TargetType
{
    SingleTarget,
    AOE,
    Self
};

// Define the spell types
enum class SpellType
{
    Damage,
    Heal,
    Buff,
    Debuff
};

// The Spell class represents a single spell with attributes
class Spell
{
public:
    std::string name;
    int manaCost;
    int power;
    TargetType target;
    SpellType type;

    Spell(std::string n, int mCost, int p, TargetType t, SpellType st)
        : name(n), manaCost(mCost), power(p), target(t), type(st) {}

    void PrintSpell() const
    {
        std::cout << "Name: " << name << ", Mana Cost: " << manaCost
                  << ", Power: " << power << ", Target: " << GetTargetTypeAsString()
                  << ", Type: " << GetSpellTypeAsString() << std::endl;
    }

    std::string GetTargetTypeAsString() const
    {
        switch (target)
        {
        case TargetType::SingleTarget: return "Single Target";
        case TargetType::AOE: return "AOE";
        case TargetType::Self: return "Self";
        default: return "Unknown";
        }
    }

    std::string GetSpellTypeAsString() const
    {
        switch (type)
        {
        case SpellType::Damage: return "Damage";
        case SpellType::Heal: return "Heal";
        case SpellType::Buff: return "Buff";
        case SpellType::Debuff: return "Debuff";
        default: return "Unknown";
        }
    }
};

// Function to create a list of spells
std::vector<Spell> CreateSpells()
{
    return {
        {"Fireball", 50, 100, TargetType::SingleTarget, SpellType::Damage},
        {"Healing Aura", 30, 50, TargetType::AOE, SpellType::Heal},
        {"Shield", 20, 0, TargetType::Self, SpellType::Buff},
        {"Curse", 40, 60, TargetType::SingleTarget, SpellType::Debuff},
        {"Blizzard", 70, 80, TargetType::AOE, SpellType::Damage},
        {"Regenerate", 25, 30, TargetType::Self, SpellType::Heal},
        {"Lightning Strike", 55, 120, TargetType::SingleTarget, SpellType::Damage},
        {"Mass Shield", 60, 0, TargetType::AOE, SpellType::Buff},
        {"Flame Burst", 45, 110, TargetType::AOE, SpellType::Damage},
        {"Light Aura", 30, 0, TargetType::AOE, SpellType::Buff},
        {"Dark Curse", 40, 70, TargetType::SingleTarget, SpellType::Debuff},
        {"Water Wave", 35, 90, TargetType::AOE, SpellType::Damage},
        {"Thunderbolt", 60, 130, TargetType::SingleTarget, SpellType::Damage},
        {"Earthquake", 65, 150, TargetType::AOE, SpellType::Damage},
        {"Magic Barrier", 50, 0, TargetType::Self, SpellType::Buff},
        {"Invisibility", 30, 0, TargetType::Self, SpellType::Buff},
        {"Meteor Shower", 90, 200, TargetType::AOE, SpellType::Damage},
        {"Ice Spike", 35, 80, TargetType::SingleTarget, SpellType::Damage},
        {"Hurricane", 75, 140, TargetType::AOE, SpellType::Damage},
        {"Holy Light", 20, 40, TargetType::Self, SpellType::Heal},
        {"Lightning Storm", 80, 180, TargetType::AOE, SpellType::Damage},
        {"Sacred Flame", 60, 100, TargetType::SingleTarget, SpellType::Damage},
        {"Venom Strike", 30, 70, TargetType::SingleTarget, SpellType::Debuff},
        {"Frost Nova", 70, 90, TargetType::AOE, SpellType::Damage},
        {"Mana Shield", 40, 0, TargetType::Self, SpellType::Buff},
        {"Arcane Missiles", 45, 85, TargetType::SingleTarget, SpellType::Damage},
        {"Healing Rain", 35, 60, TargetType::AOE, SpellType::Heal},
        {"Divine Protection", 50, 0, TargetType::Self, SpellType::Buff},
        {"Poison Cloud", 50, 100, TargetType::AOE, SpellType::Debuff},
        {"Stone Skin", 25, 0, TargetType::Self, SpellType::Buff},
        {"Life Drain", 50, 70, TargetType::SingleTarget, SpellType::Debuff},
        {"Phoenix Fire", 100, 250, TargetType::AOE, SpellType::Damage},
        {"Raging Inferno", 90, 210, TargetType::AOE, SpellType::Damage},
        {"Whirlwind", 55, 85, TargetType::AOE, SpellType::Damage},
        {"Blessing of Light", 30, 0, TargetType::Self, SpellType::Buff},
        {"Shadow Bolt", 40, 90, TargetType::SingleTarget, SpellType::Damage},
        {"Serpent's Bite", 45, 65, TargetType::SingleTarget, SpellType::Debuff},
        {"Cleansing Wave", 25, 0, TargetType::AOE, SpellType::Heal},
        {"Chill Touch", 35, 50, TargetType::SingleTarget, SpellType::Damage},
        {"Blood Pact", 60, 0, TargetType::Self, SpellType::Buff},
        {"Lunar Strike", 75, 160, TargetType::SingleTarget, SpellType::Damage},
        {"Solar Flare", 65, 140, TargetType::AOE, SpellType::Damage},
        {"Nature's Grasp", 50, 80, TargetType::SingleTarget, SpellType::Buff},
        {"Wrath of the Ancients", 100, 250, TargetType::AOE, SpellType::Damage},
        {"Ethereal Form", 40, 0, TargetType::Self, SpellType::Buff},
        {"Radiant Heal", 30, 70, TargetType::SingleTarget, SpellType::Heal},
        {"Stormcall", 80, 150, TargetType::AOE, SpellType::Damage},
        {"Chain Lightning", 70, 130, TargetType::AOE, SpellType::Damage},
        // Add more spells here
    };
}

// Task for student: Implement a search function to find spells based on keywords
std::vector<Spell> SearchSpells(const std::vector<Spell>& spellList, const std::string& keyword)
{
    std::vector<Spell> results;

    // Student solution should be placed here:
    // Implement a search algorithm (e.g., linear search, binary search)
    
    
    // Convert the keyword to lowercase for case-insensitive matching
    std::string searchKeyword = keyword;
    std::transform(searchKeyword.begin(), searchKeyword.end(), searchKeyword.begin(), ::tolower);

    for (const auto& spell : spellList)
    {
        // Convert attributes to lowercase for case-insensitive comparison
        std::string lowerName = spell.name;
        std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        // Makes the current spell info all lower case
        std::string lowerTargetType = spell.GetTargetTypeAsString();
        std::transform(lowerTargetType.begin(), lowerTargetType.end(), lowerTargetType.begin(), ::tolower);

        std::string lowerSpellType = spell.GetSpellTypeAsString();
        std::transform(lowerSpellType.begin(), lowerSpellType.end(), lowerSpellType.begin(), ::tolower);

        // Check if the keyword matches the spell's name, target type, or spell type
        if (lowerName.find(lowerKeyword) != std::string::npos ||
            lowerTargetType.find(lowerKeyword) != std::string::npos ||
            lowerSpellType.find(lowerKeyword) != std::string::npos)
        {
            results.push_back(spell);
        }
    }
    
    
    return results;
}

int main()
{
    std::vector<Spell> spells = CreateSpells();

    std::string keyword;
    std::cout << "Search terms: Damage, Heal, Buff, Debuff, SingleTarget, AOE, Self" << std::endl;
    std::cout << "Enter a search keyword:" << std::endl;
    std::getline(std::cin, keyword);

    // Search for spells based on the keyword
    std::vector<Spell> matchingSpells = SearchSpells(spells, keyword);

    // Display the results
    if (!matchingSpells.empty())
    {
        std::cout << "Matching Spells:" << std::endl;
        for (const auto& spell : matchingSpells)
        {
            spell.PrintSpell();
        }
    }
    else
    {
        std::cout << "No spells matched the search criteria." << std::endl;
    }

    return 0;
}
```



## Reflection
It was interesting to look at the different string functions and also other functions within C++.
It makes it easier to get desired outcomes from the code without having to make up everything from scratch. And once you know one exists it can then be put to use in the future, lowering the need to remake something.
I think had i worked on this in class i would have taken a more investigative approach to this problem, as i would have been able to speak to others for ideas, but just searching for ways to do something on the internet comes up with probably the more straightforward answer. 


## Bibliography
std::transform - cppreference.com (s.d.) At: https://en.cppreference.com/w/cpp/algorithm/transform (Accessed  06/12/2024).
std::tolower - cppreference.com (s.d.) At: https://en.cppreference.com/w/cpp/string/byte/tolower (Accessed  06/12/2024).
