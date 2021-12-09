#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "mystudent.h"
#include "mystring.h"

void InitializeDynamicArray(struct DynamicArray* a){
    a->i=0;
    a->n=1;
    a->arr=(struct Student*)malloc(a->n*sizeof(Student));
}

void createBackup(char *path1, char *path2){

    FILE *fptr;
	fptr=fopen(path1,"r");
    FILE *fptr2;
    fptr2=fopen(path2,"w");
    char c = fgetc(fptr);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr);
    }
}

void addMemoryToArray(struct DynamicArray* a){
    int n=a->n*2;
    struct Student* arr=(struct Student*)malloc(n*sizeof(Student));
    for(int i=0;i<a->i;i++)
    {
        arr[i]=a->arr[i];
    }
    free(a->arr);
    a->arr=arr;
    a->n=n;

}

void AddDataToDynamicArray(struct DynamicArray* a,struct Student student){
    if(a->i>=a->n)
        addMemoryToArray(a);
    a->arr[a->i]=student;
    a->i++;
}

void RemoveLastDataFromDynamicArray(struct DynamicArray* a){
	a->i--;
}

void ReadData(struct DynamicArray* array, char* path){
   
    struct Student student1;
    int num[50];
	int i=0;
	char *line=NULL;
	size_t len = 0;
	int read;

	FILE *fptr;
	fptr=fopen(path,"r");

    while ((read = getline(&line, &len, fptr)) != -1) {
            char * token = strtok(line, ",");

            struct myString name;
            InitializeString(&name);
            newString(&name, token);
            student1.name = name;

            token = strtok(NULL, ",");
            struct myString lastname;
            InitializeString(&lastname);
            newString(&lastname, token);
            student1.lastname = lastname;

            token = strtok(NULL, ",");
            student1.grade = atoi(token);
            student1.grade+=1000;

            AddDataToDynamicArray(array, student1);
    }
}
// Functions for printing struct student
void printStudent(struct Student student){
    printf("Student Details: \n");
    printMyString(student.name);
    printf(",");
    printMyString(student.lastname);
    printf(",");
    printf("%d\n",student.grade);
}

void fprintStudent(struct Student student, FILE* fptr){
    fprintMyString(student.name,fptr);
    fprintf(fptr, ",");
    fprintMyString(student.lastname,fptr);
    fprintf(fptr, ",");
    fprintf(fptr, "%d\n",student.grade);
}

void fprintStudentDescriptor(struct Student student){
    printMyString(student.name);
    printf(",");
    printMyString(student.lastname);
    printf(",");
    printf("%d\n",student.grade);
}

// Functions for printing struct DynamicArray
void PrintDynamicArray(struct DynamicArray* a){ 
    for(int i=0; i < a->i; i++)
    {
        printStudent(a->arr[i]);
	}
}
void fPrintDynamicArray(struct DynamicArray* a, char *path){ 
    FILE *fptr;
	fptr=fopen(path,"w");
    for(int i=0; i < a->i; i++)
    {
        fprintStudent(a->arr[i],fptr);
	}
}

void fPrintDynamicArrayDescriptor(struct DynamicArray* a, char *path){ 
    int file_descriptor_for_file=open(path, O_WRONLY | O_CREAT | O_TRUNC | O_SYNC, 0666);
    if(file_descriptor_for_file<0)
    printf("Error on open");
    int duplicate = dup(STDOUT_FILENO);
    int returnvalue=dup2(file_descriptor_for_file, STDOUT_FILENO);
    if(returnvalue<0)
    printf("Error on dup2");

    for(int i=0; i < a->i; i++)
    {
        fprintStudentDescriptor(a->arr[i]);
	}

     close(file_descriptor_for_file);
    dup2(duplicate,STDOUT_FILENO);
}