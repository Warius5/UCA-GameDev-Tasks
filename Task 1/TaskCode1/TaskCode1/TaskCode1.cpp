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
    if (ascending)
    {
        for  (int X = 1; X < listSize; ++X ) // going through each element in the list
        {
            std::string sortSpace = items[X].name; // gets the value of the to be sorted element, to be used to compare to the sorted elements
            int sortedKey = X -1; // gets the value of the nearest sorted 
            while (sortedKey >= 0 && items[sortedKey].name < sortSpace) // compares through the sorted list until it gets to where it is either too big or toom small
            {
                
                std::swap(items[sortedKey+1],items[sortedKey]); // swaps the places of the two elements if the current one is not in the right place
                sortedKey = sortedKey - 1;
            }
            items[sortedKey+1].name = sortSpace; // goes to next element to be sorted (moves the sorted list along)
        }
    }
    else
    {
        for  (int X = 1; X < listSize; ++X ) // going through each element in the list
        {
            std::string sortSpace = items[X].name;
            int sortedKey = X -1;
            while (sortedKey >= 0 && items[sortedKey].name > sortSpace)
            {
                
                std::swap(items[sortedKey+1],items[sortedKey]);
                sortedKey = sortedKey - 1;
            }
            items[sortedKey+1].name = sortSpace;
        }
    }
   
   
}

// Function to sort items by value (ascending/descending)
void SortByValue(std::vector<Item>& items, bool ascending = true)
{
    int listSize = items.size();
    if (ascending)
    {
        for  (int X = 1; X < listSize; ++X ) // going through each element in the list
        {
            int sortSpace = items[X].value; // gets the value of the to be sorted element, to be used to compare to the sorted elements
            int sortedKey = X -1; // gets the value of the nearest sorted 
            while (sortedKey >= 0 && items[sortedKey].value < sortSpace) // compares through the sorted list until it gets to where it is either too big or toom small
            {
                
                std::swap(items[sortedKey+1],items[sortedKey]);  // swaps the places of the two elements if the current one is not in the right place
                sortedKey = sortedKey - 1;
            }
            items[sortedKey+1].value = sortSpace; // goes to next element to be sorted (moves the sorted list along)
        }
    }
    else
    {
        for  (int X = 1; X < listSize; ++X ) // going through each element in the list
        {
            int sortSpace = items[X].value;
            int sortedKey = X -1;
            while (sortedKey >= 0 && items[sortedKey].value > sortSpace)
            {
                
                std::swap(items[sortedKey+1],items[sortedKey]);
                sortedKey = sortedKey - 1;
            }
            items[sortedKey+1].value = sortSpace;
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
    
    std::cout << "\nSorted by Name (Antiaplphabetically):" << std::endl;
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



/*// Function to sort items by name (alphabetically)
void SortByName(std::vector<Item>& items, bool ascending = true)
{
    int listSize = items.size();
    bool swapped;
    if (ascending)
    {
        swapped = false; // checking whether a swap has happened
        for  (int X = 0; X < listSize-1; X++ ) // going through each element in the list
        {
            swapped = false;
            for (int Y = 0; Y < listSize- X - 1; Y++) // getting element and going through rest of list checking
            {
                
                if ( items[(Y)].name >  items[(Y+1)].name) // comparing the item object attributes
                {
                    std::swap(items[Y], items[Y+1]);// C++ vector swap function
                    swapped = true;
                }
                
            }
            if (!swapped) // if no swaps end 
            {
                break;
            }
        }
    }
    else
    {
        swapped = false; // checking whether a swap has happened
        for  (int X = 0; X < listSize-1; X++ ) // going through each element in the list
        {
            swapped = false;
            for (int Y = 0; Y < listSize- X - 1; Y++) // getting element and going through rest of list checking
            {
                
                if ( items[(Y)].name <  items[(Y+1)].name) // comparing the item object attributes
                {
                    std::swap(items[Y], items[Y+1]);// C++ vector swap function
                    swapped = true;
                }
                
            }
            if (!swapped) // if no swaps end
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
        for  (int X = 0; X < listSize-1; X++ ) // going through each element in the list
        {
            swapped = false;
            for (int Y = 0; Y < listSize- X - 1; Y++) // getting element and going through rest of list checking
            {
                
                if ( items[(Y)].value <  items[(Y+1)].value) // comparing the item object attributes
                {
                    std::swap(items[Y], items[Y+1]);// C++ vector swap function
                    swapped = true;
                }
                
            }
            if (!swapped) // if no swaps end
            {
                break;
            }
        }
    }
    else
    {
        swapped = false; // checking whether a swap has happened
        for  (int X = 0; X < listSize-1; X++ ) // going through each element in the list
        {
            swapped = false;
            for (int Y = 0; Y < listSize- X - 1; Y++) // getting element and going through rest of list checking
            {
                
                if ( items[(Y)].value >  items[(Y+1)].value) // comparing the item object attributes
                {
                    std::swap(items[Y], items[Y+1]);// C++ vector swap function
                    swapped = true;
                }
                
            }
            if (!swapped) // if no swaps end
            {
                break;
            }
        }
    }
}*/