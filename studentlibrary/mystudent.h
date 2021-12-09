#ifndef MYSTUDENT
#define MYSTUDENT
#include "mystring.h"

struct Student{                                 
    struct myString name;      // struct mystring from library mystring.h
    struct myString lastname;  // struct mystring from library mystring.h
    int grade;
}Student;

struct DynamicArray{
    struct Student *arr;  // array
    int n;                // size of array
    int i;                // last element in array
}DynamicArray;

void InitializeDynamicArray(struct DynamicArray* a);                            // initializing data to dynamic array
void addMemoryToArray(struct DynamicArray* a);                                  // adds memory to dynamic array struct
void AddDataToDynamicArray(struct DynamicArray* a,struct Student student);      // transfers student details from struct student to struct dynamicArray
void RemoveLastDataFromDynamicArray(struct DynamicArray* a);                    // removes last student from dynamicArray

void ReadData(struct DynamicArray* array, char* path);      // function reads data from file line by line using a delimiter, and changes the value student.grade
void createBackup(char *path1, char *path2);                // function makes a backup file (path2) with the same content as the first file (path1)

void printStudent(struct Student student);                  // prints student details 
void PrintDynamicArray(struct DynamicArray* a);             // prints the dynamicArray with the student details
void fPrintDynamicArray(struct DynamicArray* a,char *path); // functions prints dynamic array to a file
void fprintStudent(struct Student student,FILE* fptr);      // function prints the struct student into the same file but with changed values

#endif