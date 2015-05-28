//
//  quicksortLib.cpp
//  Quicksort with lists
//
//  Created by Simen  Valla on 19/05/15.
//  Copyright (c) 2015 Simen  Valla. All rights reserved.
//

#include <random>
#include <list>
#include "quicksortLib.h"

// Creating the random string of characters, distributing '\0''s
void randomString(char* stringArray, int* numOfWords, int stringLength)
{
    int checkingForEos = 10;
    
    for(int i = 0; i < stringLength; i++)
    {
        
        if(i == 0)
            stringArray[i] = 'a' + rand()%26;
        
        if(i > 0 && i < stringLength - 1)
        {
            stringArray[i] = 'a' + rand()%26;;
            
            if(rand()%10 == 0 && checkingForEos < 5 && i < (stringLength - 5)){
                stringArray[i] = '\0';
                checkingForEos = 10;
            }
        }
        
        if (i == stringLength - 1){
            stringArray[i] = '\0';
            break;
        }
        
        checkingForEos--;
    }
}

// Initializing the list with values
void initializingWords(char* stringOfWords, std::list<word>& words, int stringLength)
{
    word n;
    n.value = 0;
    n.stringPtr = &stringOfWords[0];
    n.wordLength = strlen(&stringOfWords[0]);
    
    words.push_back(n);
    
    // Filling in the list elements
    for(int i = 0; i < stringLength - 1; i++)
    {
        if(stringOfWords[i] == '\0')
        {
            n.stringPtr = &stringOfWords[i+1];
            n.wordLength = strlen(n.stringPtr);
            n.value = 0;
            words.push_back(n);
        }
    }
}
// Counting integer values of words
void countingWordValues(std::list<word>& words)
{
    for(auto &ii : words)
    {
        char* tempPtr = (ii).stringPtr;
        for(size_t i = 0; i < (ii).wordLength; i++)
            (ii).value += *tempPtr++;
    }
}

void quicksort(std::list<word>& words, size_t low, size_t high)
{
    int pivot;
    
    if(high > low)
    {
        pivot = partition(words, low, high);
        quicksort(words, low, pivot);
        quicksort(words, pivot+1, high);
    }
}

int partition(std::list<word>& words, size_t low, size_t high)
{
    int left = 0, right = 0, pivotValue = 0;
    
    // Random pivot
    int randPivot = (int)low + rand()%(high-low);
    auto itPivot = std::next(words.begin(), randPivot);
    int tempValue = itPivot->value;
    char* tempPtr = itPivot->stringPtr;
    size_t tempLength = itPivot->wordLength;
    
    pivotValue = itPivot->value;
    
    // Removing the element from the list
    itPivot = words.erase(itPivot);
    high--;
    
    // Initializing the left and right selectors
    std::list<word>::iterator itLeft = std::next(words.begin(), low);
    std::list<word>::iterator itRight = std::next(words.begin(), high);
    
    left = (int)low;
    right = (int)high;
    while(1)
    {
        
        
        // Find left element that is greater than or equal to pivot
        while(itLeft->value < pivotValue && left < high)
        {
            itLeft = std::next(words.begin(), ++left);
        }
        
        // Find right element that is less than pivot
        while(itRight->value >= pivotValue && right > left)
        {
            itRight = std::next(words.begin(), --right);
        }
        
        
        if (left >= right)
        {
            break;
        }
        
        // swap them
        std::iter_swap(itLeft, itRight);
    }
    
    word n;
    n.value = tempValue;
    n.stringPtr = tempPtr;
    n.wordLength = tempLength;
    
    
    // Left boundary control
    if(left == low && itLeft->value > n.value)
    {
        words.insert (itLeft,n);;
        return left;
    }
    
    // Right boundary control
    if(left == high && itLeft->value < n.value)
    {
        words.insert (++itRight,n);;
        return right+1;
    }
    
    words.insert (itLeft,n);
    
    return left;

}