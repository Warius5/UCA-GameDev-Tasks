 #include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
class Item
{
public:
    std::string name;
    int value;

    Item(std::string n, int v) : name(n), value(v) {}
};

// Function to display the inventory
void DisplayInventory(const std::vector<Item>& items)
{
    for (const auto& item : items)
    {
        std::cout << item.name << ": " << item.value << std::endl;
    }
}

// Function to sort items by name (alphabetically)
void SortByName(std::vector<Item>& items, bool ascending = true)
{
    
   //else
    //    swapped = false; // checking whether a swap has happened
    //    for  (int currentIndex = 0; currentIndex < listSize-1; currentIndex++ )
    //        {
     //           swapped = false;
    //            for (int nextIndex = 0; nextIndex < listSize- currentIndex - 1; nextIndex++)
    //            {
    //                std::swap(items[nextIndex], items[nextIndex+1]); // C++ swap function
   //                 swapped = true;
    //            }
   //         }    
    //   std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) { return a.name < b.name; });
    
    
    
   //   std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) { return a.name > b.name; });
   
   
   
   
}

// Function to sort items by value (ascending/descending)
void SortByValue(std::vector<Item>& items, bool ascending = true)
{
    int listSize = items.size();
    bool swapped;
   if (ascending)
    {
        swapped = false; // checking whether a swap has happened
        for  (int currentIndex = 0; currentIndex < listSize-1; currentIndex++ )
        {
            swapped = false;
            for (int nextIndex = 0; nextIndex < listSize- currentIndex - 1; nextIndex++)
            {
                
                if ((items[nextIndex,1]) >  (items[(nextIndex + 1),1])); 
                {
                    std::swap(items[nextIndex,1], items[nextIndex+1,1] );// C++ swap function
                    swapped = true;
                }
                
            }
            if (!swapped)
            {
                break;
            }
        }
    }
    else
        std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) { return a.value > b.value; });
}

int main()
{
    std::vector<Item> items = {
        Item("Sword", 150),
        Item("Potion", 50),
        Item("Shield", 100),
        Item("Bow", 120),
        Item("Helmet", 80)
    };

    std::cout << "Original Inventory:" << std::endl;
    DisplayInventory(items);

    std::cout << "\nSorted by Name (Ascending):" << std::endl;
    SortByName(items, true); // Sort by name in ascending order
    DisplayInventory(items);

    std::cout << "\nSorted by Value (Descending):" << std::endl;
    SortByValue(items, false); // Sort by value in descending order
    DisplayInventory(items);

    return 0;
}