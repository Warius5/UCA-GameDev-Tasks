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
    if (ascending)
        std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) { return a.name < b.name; });
    else
        std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) { return a.name > b.name; });
}

// Function to sort items by value (ascending/descending)
void SortByValue(std::vector<Item>& items, bool ascending = true)
{
    if (ascending)
        std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) { return a.value < b.value; });
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