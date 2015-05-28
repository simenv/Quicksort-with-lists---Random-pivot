# Quicksort-with-lists---Random-pivot
This is a school project with the following requirements:

"Modify Quicksort to sort a sequence of variable-length strings stored 
one after the other in a character array, with a second array (storing 
pointers to strings) used to index the strings. Your function should 
modify the index array so that the first pointer points to the beginning 
of the lowest valued string, and so on."

The character array should look like this: char String_array[] = {“one\0two\0three\0”};

I've used structs to store the information about each word in the string. 
The struct looks like this:

struct word{
    int value = 0;
    char* stringPtr = NULL;
    size_t wordLength = 0;
};
