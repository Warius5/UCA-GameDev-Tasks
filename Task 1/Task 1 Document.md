# Task 1 Inventory Sorting

Advanced Programming

Ben Powell

2204331



# Research

## Sorting

The task requests for a list to be sorted in ascending and descending order. Both for the alphabetical name of the item, as well as the numerical value of the item.
I want to look at the different types of sorts that could be used to solve this problem and see what the pros are cons are for each one.
The list is an inventory meaning it will probably be a small list to sort so extensive and longwinded sorts may not be the best choice.

## Bubble Sort 
Bubble sort is a simple sorting algorithm that involves swapping adjacent elements to get the list in the right order, starting with the first number and going through multiple passes for each item, until its all sorted. (Bubble Sort Algorithm, 2014)
### Advantages
- Easy to use
- No extra memory needed
### Disadvantages
- O(N^2) means its slow for larger data sets

### Plan

> - Take in list and size
    > - Compare current and next item, swap if bigger
    > - loop through entire list
    > - end if no swaps

### Outcome
```c++
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
```



### Result
Original Inventory:
Sword: 150
Potion: 50
Shield: 100
Bow: 120
Helmet: 80

Sorted by Name (Alphabetically):
Bow: 120
Helmet: 80
Potion: 50
Shield: 100
Sword: 150

Sorted by Name (Antiaplphabetically):
Sword: 150
Shield: 100
Potion: 50
Helmet: 80
Bow: 120

Sorted by Value (Descending):
Sword: 150
Bow: 120
Shield: 100
Helmet: 80
Potion: 50

Sorted by Value (Ascending):
Potion: 50
Helmet: 80
Shield: 100
Bow: 120
Sword: 150
## Insertion Sort
An insertion sort builds a sorted array one at a time from an unsorted list.
It takes the first item and puts it in a seperate list, and then takes the next and positions it to the left until the next one left is smaller or larger depending. (Insertion Sort Algorithm, 2013)
### Advantages
- Easy to implement for most lists
- Space efficient
- Good for short lists

### Disadvantages
- Inefficient for large lists

### Plan

>   - get list
>   - assign space to build sorted list around ( 2nd space)
>   - move and compare with previous items in the sorted list until right place is found.

### Outcome
```c++
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
```
### Output
Original Inventory:
Sword: 150
Potion: 50
Shield: 100
Bow: 120
Helmet: 80

Sorted by Name (Alphabetically):
Sword: 150
Shield: 100
Potion: 50
Helmet: 80
Bow: 120

Sorted by Name (Antiaplphabetically):
Bow: 120
Helmet: 80
Potion: 50
Shield: 100
Sword: 150

Sorted by Value (Descending):
Sword: 150
Bow: 120
Shield: 100
Helmet: 80
Potion: 50

Sorted by Value (Ascending):
Potion: 50
Helmet: 80
Shield: 100
Bow: 120
Sword: 150
Took 1.532 sec(s)


### Quick sort
Quick sort is a divide and conquer algortihm which uses a pivot, often the last item, and putting it in the middle by comparing anything smaller to the left, and anything bigger to the right. It is not sorted yet. 
It then takes more pivots in the two list; the smaller and the larger. going until its sorted. (Quick Sort, 2014)
### Advantages
- Effiicient on large sets
- Small amount of memory

## Disadvantages
- Poor ability for small data sets
- O(N^2) if poor pivot

### Merge sort
A divide and conquer algorithm that divides the list into halves until it cannot be divided more. The smaller parts are then merged back together in order until the ordered list is completed. (Merge Sort - Data Structure and Algorithms Tutorials, 2013)

### Advantages
- worst case of O(N log n)
-  simple to implement
### Disadvantages
- additional space requreid
- not an in place so may be slower 


### Testing Decision 
Due to the task only having a smaller list size, the more complex sort algorithms may not be neccesary, so i will do a bubble and insertion sort to see which one will be faster in this instance.

## Conclusion
The Instertion sort was the fastest one compared to the bubble sort, making it the more suitable one for this inventory size and style. I can assume that is was faster due to not having to go though the whole list each time to compare, removing redundant actions. The times may be affected by the best/worst cases but for this context insertion sort will probably be always faster.


## Reflection 
For a first attempt in the new format i think i did an ok job researching on the theory and then implementing code.
I made use of the debugging features to check errors and i feel that i commented an adequate amount explaining the parts and what they did.
<br>
I think i need to look over the whole code snippet before acting as i misinterpreted one item object as part of the vector and got stuck in places i didnt need to be stuck in. 
<br> Making good use of the theory and documentation of different functions better in the future will help me out as i look at more complicated stuff.

## Bibliography
Bubble Sort Algorithm (2014) At: https://www.geeksforgeeks.org/bubble-sort-algorithm/ (Accessed  26/09/2024).

Quick Sort (2014) At: https://www.geeksforgeeks.org/quick-sort-algorithm/ (Accessed  26/09/2024).

Merge Sort - Data Structure and Algorithms Tutorials (2013) At: https://www.geeksforgeeks.org/merge-sort/ (Accessed  26/09/2024).

Insertion Sort Algorithm (2013) At: https://www.geeksforgeeks.org/insertion-sort-algorithm/ (Accessed  26/09/2024).
