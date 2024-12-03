# Task 3 Health Potion Optimisation
Advanced Programming

Ben Powell

2204331

Health potion tasks



## Research
While there was not much theory to reseach, i did not know much about vectors in C++ so an overview of what they are, and how they work was useful to then use them properly.

#### Vectors
Resizeable array, that store elements of the same data type.
Requires < Vector>
Access by using [(num)]
vector<T> vec_name; Where T is the type 



(C++ Vectors, s.d.)
We broke down the problem and likened it to other computational problems, where you use coins to get to a certain amount. 
We deduced that it would start with the potion with the highest volume and then use as many as it could before the amount left was less than that, and then go to the next smallest.
We realised that the potions were stored in a vector struct. 
As we were not completely familiar with vectors in C++, we wanted to look at the documentation.

Created a while loop to add potion health value to the current health
It went on for ever as we had not properly set up the while loop to end,
```cpp
 while (player.currentHealth < 100)
    {
        while (healthNeeded >= potions[potionindex].healingValue)
            {
                healthNeeded = healthNeeded - potions[potionindex].healingValue;
                player.currentHealth = player.currentHealth + potions[potionindex].healingValue;    

                }
                std::cout << healthNeeded << std::endl;
                potionindex++;
            }
            std::cout << healthNeeded << std::endl;    
    }    
```
Unfortunately if the answer gets to more than 90 (less than the 10 potion amount) it would get stuck.
We then instead calculated the lowest healing potion ( making it so its scalable for any types of potions.
Used that to make the while loop to go down to until there were no potions left to get it to exactly 100.
Then output the amount of health if it didn’t go to 100.
```cpp
    void HealPlayers(std::vector<Player>& players)
    {
        for (auto& player : players)
        {
            int totalPotions = 0;
            int potionindex = 0;
            int healthNeeded = player.maxHealth - player.currentHealth;
            if (healthNeeded <= 0)
            
            {
                std::cout << player.name << " is already at max health!" << std::endl;
                continue;
            }

            // Sort potions by their healing value in descending order
            std::sort(potions.begin(), potions.end(), [](const Potion& p1, const Potion& p2) {
                return p1.healingValue > p2.healingValue;
            });

            std::cout << "Healing " << player.name << ": Current Health = " << player.currentHealth << ", Max Health = " << player.maxHealth << std::endl;

            // Implement your solution here to consume potions optimally based on healthNeeded for each player
            int size = potions.size();
            Potion lastIndex = potions[size - 1];
            int lowestHeal = lastIndex.healingValue;
            
            
            while (player.currentHealth <= player.maxHealth - lowestHeal)
            {
                std::cout << healthNeeded << std::endl;
                while (healthNeeded >= potions[potionindex].healingValue)
                {
                    totalPotions++;
                    healthNeeded = healthNeeded - potions[potionindex].healingValue;
                    player.currentHealth = player.currentHealth + potions[potionindex].healingValue;
                    
                }
                potionindex++;
                

                
            }
            
            std::cout << "Total number of potions for " << player.name << " is " << totalPotions << std::endl;
            
            

            if (player.currentHealth < player.maxHealth)
            {
                std::cout << "Not enough potions to fully heal " << player.name << "!" << std::endl;
                std::cout << "Current health is: " << player.currentHealth << std::endl;
            }
            else
            {
                std::cout << player.name << " is fully healed!" << std::endl;
            }
        }
    }
```

## Addition
As an addition i want to give differnet ways of using up the health potions in different ways.
Such as doing it by weight or by money value.
I might try do the weight by an inputted value to get rid of. So uses heaviest -> lightest to use up a number of potions closest to that value.
I added a weight value to the potions and added a new subroutine in the HealPlayers ( aswell as split up the ccurrent one)
Although i was having issues with the healing by weight





## Outcome
```cs
#include <iostream>
#include <vector>
#include <algorithm>

class Potion
{
public:
    std::string name;
    int healingValue;
    float weight;
    Potion(std::string n, int h, float w) : name(n), healingValue(h), weight(w) {}
};

class Player
{
public:
    std::string name;
    int currentHealth;
    int maxHealth;
    float currentWeight;
    Player(std::string n, int current, int max, float w) : name(n), currentHealth(current), maxHealth(max), currentWeight(w) {}
};






class HealthPotionSystem
{
public:
    std::vector<Potion> potions;

    HealthPotionSystem()
    {
        // Adding multiple potions
        potions.push_back(Potion("Large Potion", 50, 20.0));
        potions.push_back(Potion("Small Potion", 10, 5.0));
        potions.push_back(Potion("Medium Potion", 20, 10.0));
       
    }
    
    
    void HealByWeight(std::vector<Player>& players)
    {
        for (auto& player : players)
        {
            // Prompt player for weight input
            float dropWeight = 0.0f;
            std::cout << player.name << std::endl;
            std::cout << "How much weight do you want to drop?" << std::endl;
            std::cin >> dropWeight;
    
            // Calculate target and needed weights
            float targetWeight = player.currentWeight - dropWeight;
    
            // Ensure target weight is valid
            if (targetWeight < 0.0f)
            {
                std::cout << "Cannot drop more weight than the player currently has!" << std::endl;
                continue; // Skip to the next player
            }
    
            float neededWeight = player.currentWeight - targetWeight;
    
            // Sort potions by weight in descending order
            std::sort(potions.begin(), potions.end(), [](const Potion& a, const Potion& b) {
                return a.weight > b.weight;
            });
    
            // Drop potions to reduce weight
            int potionIndex = 0;
            while (player.currentWeight > targetWeight && potionIndex < potions.size())
            {
                const Potion& currentPotion = potions[potionIndex];
    
                if (neededWeight >= currentPotion.weight)
                {
                    // Drop the potion
                    player.currentWeight -= currentPotion.weight;
                    neededWeight -= currentPotion.weight;
    
                    std::cout << "Dropped potion with weight: " << currentPotion.weight << std::endl;
    
                    // Remove the potion from inventory
                    
                }
                else
                {
                    // Move to the next potion
                    potionIndex++;
                }
    
                // Display current weight
                std::cout << "Current Weight: " << player.currentWeight << std::endl;
            }
    
            // Output results
            if (player.currentWeight <= targetWeight)
            {
                std::cout << player.name << " reached the target weight!" << std::endl;
            }
            else
            {
                std::cout << player.name << " could not reach the target weight. Not enough potions!" << std::endl;
            }
        }
    }
    /* Allow the dropping of potions depending on the weight of the potion, such as in a game where you need to make weight space in your inventory. it then says if it got to the weight or not.     */

    // Method to determine the optimal potions to consume for each player
    void HealPlayers(std::vector<Player>& players)
    {
        for (auto& player : players)
        {
            int totalPotions = 0;
            int potionindex = 0;
            int healthNeeded = player.maxHealth - player.currentHealth;
            if (healthNeeded <= 0)
            
            {
                std::cout << player.name << " is already at max health!" << std::endl;
                continue;
            }

            // Sort potions by their healing value in descending order
            std::sort(potions.begin(), potions.end(), [](const Potion& p1, const Potion& p2) {
                return p1.healingValue > p2.healingValue;
            });

            std::cout << "Healing " << player.name << ": Current Health = " << player.currentHealth << ", Max Health = " << player.maxHealth << std::endl;

            // Implement your solution here to consume potions optimally based on healthNeeded for each player
            int size = potions.size();
            Potion lastIndex = potions[size - 1];
            int lowestHeal = lastIndex.healingValue;
            
            
            while (player.currentHealth <= player.maxHealth - lowestHeal)
            {
                std::cout << healthNeeded << std::endl;
                while (healthNeeded >= potions[potionindex].healingValue)
                {
                    totalPotions++;
                    healthNeeded = healthNeeded - potions[potionindex].healingValue;
                    player.currentHealth = player.currentHealth + potions[potionindex].healingValue;
                    
                }
                potionindex++;
                

                
            }
            
            std::cout << "Total number of potions for " << player.name << " is " << totalPotions << std::endl;
            
            

            if (player.currentHealth < player.maxHealth)
            {
                std::cout << "Not enough potions to fully heal " << player.name << "!" << std::endl;
                std::cout << "Current health is: " << player.currentHealth << std::endl;
            }
            else
            {
                std::cout << player.name << " is fully healed!" << std::endl;
            }
        }
    }
};
/* This method heals players by consuming potions, in order of their healing value. If the current potion is too big to get to that amount, it goes to the next healing potion. Then reports on the updated health. */

int main()
{
    // List of multiple players
    std::vector<Player> players = {
        Player("Mage", 50, 100, 50.0),
        Player("Knight", 70, 100, 80.0),
        Player("Rogue", 65, 100, 60.0),
        Player("Cleric", 85, 100, 70.0)
    };

    HealthPotionSystem potionSystem;
    potionSystem.HealPlayers(players); // Heal all players optimally using available potions
    potionSystem.HealByWeight(players);

    return 0;
}



```

## Output
Healing Mage: Current Health = 50, Max Health = 100 <br>
50 <br>
Total number of potions for Mage is 1<br>
Mage is fully healed!<br>
Healing Knight: Current Health = 70, Max Health = 100<br>
30<br>
30<br>
10<br>
Total number of potions for Knight is 2<br>
Knight is fully healed!<br>
Healing Rogue: Current Health = 65, Max Health = 100<br>
35<br>
35<br>
15<br>
Total number of potions for Rogue is 2<br>
Not enough potions to fully heal Rogue!<br>
Current health is: 95<br>
Healing Cleric: Current Health = 85, Max Health = 100<br>
15<br>
15<br>
15<br>
Total number of potions for Cleric is 1<br>
Not enough potions to fully heal Cleric!<br>
Current health is: 95<br>
Mage<br>
How much weight do you want to drop?<br>
40<br>
Dropped potion with weight: 20<br>
Current Weight: 30<br>
Dropped potion with weight: 20<br>
Current Weight: 10<br>
Mage reached the target weight!<br>
Knight<br>
How much weight do you want to drop?<br>
65<br>
Dropped potion with weight: 20<br>
Current Weight: 60<br>
Dropped potion with weight: 20<br>
Current Weight: 40<br>
Dropped potion with weight: 20<br>
Current Weight: 20<br>
Current Weight: 20<br>
Current Weight: 20<br>
Dropped potion with weight: 5<br>
Current Weight: 15<br>
Knight reached the target weight!<br>
Rogue<br>
How much weight do you want to drop?<br>
42<br>
Dropped potion with weight: 20<br>
Current Weight: 40<br>
Dropped potion with weight: 20<br>
Current Weight: 20<br>
Current Weight: 20<br>
Current Weight: 20<br>
Current Weight: 20<br>
Rogue could not reach the target weight. Not enough potions!<br>
Cleric<br>
How much weight do you want to drop?<br>
43<br>
Dropped potion with weight: 20<br>
Current Weight: 50<br>
Dropped potion with weight: 20<br>
Current Weight: 30<br>
Current Weight: 30<br>
Current Weight: 30<br>
Current Weight: 30<br>
Cleric could not reach the target weight. Not enough potions!<br>




Reflection

This task definitely gave me insight into what vectors are and ways to use that in storing data, especailly using it to store multiple objects and then go through those objects using a for loop. <br>
I think in the begining likening the task to one i already knew about meant that i had a basic idea of what should be happening, but i think with some of the while loop logic, planning or diagramming it a bit better would make the translation into code cleaner and also easier. 


Bibliography
C++ Vectors (s.d.) At: https://www.w3schools.com/cpp/cpp_vectors.asp (Accessed  03/12/2024).
