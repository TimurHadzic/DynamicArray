#ifndef MYSTRING
#define MYSTRING

struct myString{
char *arr;  
int i;
int n;
}myString;

void InitializeString(struct myString* a);        // initializes string
void addMemory(struct myString* a);               // adds memory to struct myString
void newString(struct myString* a,char* str);     // adds string value to struct myString
void replaceString(struct myString* a,char* str); // frees memory and adds another string value to the struct

void PrintMyDynamicArray(struct myString a);            // prints dynamicArray
void printMyString(struct myString a);                  // prints the string value from the struct
void fprintMyString(struct myString a, FILE* fptr);     // prints the struct to a .txt file

#endif