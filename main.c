#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentlibrary/mystudent.h"
#include "studentlibrary/mystring.h"

int main(){

    createBackup("list.txt","backuplist.txt");      // First we create a backup of the same file before changing its values
    struct DynamicArray students;                   // Creating a dynamicArray
    InitializeDynamicArray(&students);              // Giving the dynamicArray values
    ReadData(&students, "list.txt");                // Reading data from the .txt file,changing the value of student.grade and storing its values to the DynamicArray struct
    PrintDynamicArray(&students);                   // Prints the array of structs stored from the file
    fPrintDynamicArray(&students, "list.txt");      // Stores the changed values from the DynamicArray to the same .txt file
    
    return 0;
}