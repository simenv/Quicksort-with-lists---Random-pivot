//
//  quicksortLib.h
//  Quicksort with lists
//
//  Created by Simen  Valla on 19/05/15.
//  Copyright (c) 2015 Simen  Valla. All rights reserved.
//

#ifndef __Quicksort_with_lists__quicksortLib__
#define __Quicksort_with_lists__quicksortLib__

#include <stdio.h>

// Declaration and definition of the struct used in the list
struct word{
    int value = 0;
    char* stringPtr = NULL;
    size_t wordLength = 0;
};

void randomString(char* stringArray, int* numOfWords, int stringLength);

void initializingWords(char* stringOfWords, std::list<word>& words, int stringLength);

void countingWordValues(std::list<word>& words);

void quicksort(std::list<word>& words, size_t low, size_t high);

void swapListItems( std::list<word>& words, std::list<word>::iterator a, std::list<word>::iterator b);

int partition(std::list<word>& words, size_t low, size_t high);

#endif /* defined(__Quicksort_with_lists__quicksortLib__) */