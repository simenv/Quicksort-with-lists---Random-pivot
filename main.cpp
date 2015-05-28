#include <iostream>
#include <list>
#include <ctime>
#include <random>
#include "quicksortLib.h"
#include <chrono>

int main()
{
    using namespace std::chrono;
    
    int timesRun = 10000, stringLength = 1000;
    size_t runningTimes[timesRun];
    size_t numberOfWords[timesRun];
    
    //  // Constant seed for testing the same sequence over and over again, for testing parts of functions
    //    uint randSeed = 1432720747;

    //  // Constant seed during the loop, but will differ the next time you run the program, for testing parts over and over again
    //    uint randSeed = (unsigned) time(NULL);
    for(int i = 0; i < timesRun; i++)
    {
        // List with "struct word" elements (see header file)
        std::list<word> words;
        
        // Different seed each cycle of the loop, for testing the whole program and for gathering data for analysis
        uint randSeed = (unsigned) time(NULL) + i;
        srand(randSeed);
        
        int numOfWords = 0;
        char stringOfWords[stringLength];
        
        randomString(stringOfWords, &numOfWords, stringLength);
        
        // Getting pointers to the beginning of each word and storing them in "list<word> words"
        initializingWords(stringOfWords, words, stringLength);
        
        // Counting word integer values
        countingWordValues(words);
        
//        // To see what happens when quicksort has to sort arrays which come pre-sorted
//        quicksort(words, 0, words.size()-1);
        
        // Starting timer
        auto begin = high_resolution_clock::now();
        
        // This is where quicksort is called
        quicksort(words, 0, words.size()-1);
        
        // Ending timer
        auto end = high_resolution_clock::now();
        
        // Calculating running time
        auto ticks = duration_cast<microseconds>(end-begin);
        
//        // Code used to display sorted list. Place above quicksort() to display unsorted list
        for(auto &ii : words)
            std::cout << (ii).value << " " << (ii).stringPtr << std::endl;
        std::cout << std::endl;
        
        // Storing data
        runningTimes[i] = ticks.count();
        numberOfWords[i] = words.size();
    }
    
    // Calculating data
    size_t sumDuration = 0, sumWords = 0;
    size_t min = runningTimes[0], max = runningTimes[0];
    for(int i = 0; i < timesRun; i++)
    {
        sumDuration += runningTimes[i];
        sumWords += numberOfWords[i];
        
        if(min > runningTimes[i]) min = runningTimes[i];
        if(max < runningTimes[i]) max = runningTimes[i];
    }
    
    
    // Displaying data
    std::cout << "Random pivot" << "\nCharacters:    " << stringLength  << "\nAvg word-count:" << sumWords/timesRun /*<< "\nRandom seed: " << randSeed  */<< "\nTimes run:     " << timesRun << "\nAverage time:  " << sumDuration/timesRun << "\nBest case:     " << min << "\nWorst case:    " << max << std::endl;
    
    return 0;
}