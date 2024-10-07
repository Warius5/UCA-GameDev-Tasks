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
Bubble sort is a simple sorting algorithm that involves swapping adjacent elements to get the list in the right order, starting with the first number and going through multiple passes for each item, until its all sorted.
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


```c++
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
```

```c++
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
```
![output](BubbleOutput.png)
Took 1.569 sec(s)

## Insertion Sort
An insertion sort builds a sorted array one at a time from an unsorted list.
It takes the first item and puts it in a seperate list, and then takes the next and positions it to the left until the next one left is smaller or larger depending.
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
    
```c++
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
```
```c++
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
```
Took 1.532 sec(s)

### Quick sort
Quick sort is a divide and conquer algortihm which uses a pivot, often the last item, and putting it in the middle by comparing anything smaller to the left, and anything bigger to the right. It is not sorted yet. 
It then takes more pivots in the two list; the smaller and the larger. going until 
### Advantages
- Effiicient on large sets
- Small amount of memory

## Disadvantages
- Poor ability for small data sets
- O(N^2) if poor pivot

### Merge sort
A divide and conquer algorithm that divides the list into halves until it cannot be divided more. The smaller parts are then merged back together in order until the ordered list is completed

### Advantages
- worst case of O(N log n)
-  simple to implement
### Disadvantages
- additional space requreid
- not an in place so may be slower 


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
