 #include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
    int listSize = items.size();
    bool swapped;
    if (ascending)
    {
        swapped = false; // checking whether a swap has happened
        for  (int X = 0; X < listSize-1; X++ )
        {
            swapped = false;
            for (int Y = 0; Y < listSize- X - 1; Y++)
            {
                
                if ( items[(Y)].name >  items[(Y+1)].name)
                {
                    std::swap(items[Y], items[Y+1]);// C++ vector swap function
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
    {
        swapped = false; // checking whether a swap has happened
        for  (int X = 0; X < listSize-1; X++ )
        {
            swapped = false;
            for (int Y = 0; Y < listSize- X - 1; Y++)
            {
                
                if ( items[(Y)].name <  items[(Y+1)].name)
                {
                    std::swap(items[Y], items[Y+1]);// C++ vector swap function
                    swapped = true;
                }
                
            }
            if (!swapped)
            {
                break;
            }
        }
    }
   
   
   
   
   
}

// Function to sort items by value (ascending/descending)
void SortByValue(std::vector<Item>& items, bool ascending = true)
{
    int listSize = items.size();
    bool swapped;
    if (ascending)
    {
        swapped = false; // checking whether a swap has happened
        for  (int X = 0; X < listSize-1; X++ )
        {
            swapped = false;
            for (int Y = 0; Y < listSize- X - 1; Y++)
            {
                
                if ( items[(Y)].value <  items[(Y+1)].value)
                {
                    std::swap(items[Y], items[Y+1]);// C++ vector swap function
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
    {
        swapped = false; // checking whether a swap has happened
        for  (int X = 0; X < listSize-1; X++ )
        {
            swapped = false;
            for (int Y = 0; Y < listSize- X - 1; Y++)
            {
                
                if ( items[(Y)].value >  items[(Y+1)].value)
                {
                    std::swap(items[Y], items[Y+1]);// C++ vector swap function
                    swapped = true;
                }
                
            }
            if (!swapped)
            {
                break;
            }
        }
    }
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
    
    std::cout << "\nSorted by Name (Alphabetically):" << std::endl;
    SortByName(items, true); // Sort by name in ascending order
    DisplayInventory(items);
    
    std::cout << "\nSorted by Name (Unaplphabetically):" << std::endl;
    SortByName(items, false); // Sort by name in ascending order
    DisplayInventory(items);

    std::cout << "\nSorted by Value (Descending):" << std::endl;
    SortByValue(items, true); // Sort by value in descending order
    DisplayInventory(items);
    
    std::cout << "\nSorted by Value (Ascending):" << std::endl;
    SortByValue(items, false); // Sort by value in descending order
    DisplayInventory(items);

    return 0;
}