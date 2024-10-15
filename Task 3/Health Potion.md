

Health potion tasks

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
```
unfortunately if the answer gets to more than 90 (less than the 10 potion amount) it would get stuck.
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

Addition
As an addition i want to give differnet ways of using up the health potions in different ways.
Such as doing it by weight or by money value.
I might try do the weight by an inputted value to get rid of. So uses heaviest -> lightest to use up a number of potions closest to that value.
I added a weight value to the potions and added a new subroutine in the HealPlayers ( aswell as split up the ccurrent one)
