#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

void InitializeString(struct myString* a){
    a->n=2;
    a->i=0;
    a->arr=(char*)malloc(a->n);
}

void addMemory(struct myString* a){
    
    int n=a->n*2;
    char* arr=(char*)malloc(n);
    for(int i=0;i<a->i;i++){
        arr[i]=a->arr[i];
    }
    free(a->arr);
    a->arr=arr;

}

void newString(struct myString* a,char* str){ 
    if(a->i>=a->n){     
    addMemory(a);
    }
    for(int i=0;i<strlen(str);i++){
    a->arr[i]=str[i];
    a->i++;
    if(a->i>=a->n){
    addMemory(a);}
    }
 
}

void PrintMyDynamicArray(struct myString a){
	for(int i=0; i < a.i; i++){
		printf("%c", a.arr[i]);
	}
}

void replaceString(struct myString* a,char* str){
    free(a->arr);
    if(a->i>=a->n)
    {addMemory(a);}
    for(int i=0;i<strlen(str);i++){
    a->arr[i]=str[i];
    a->i++;
    if(a->i>=a->n){
    addMemory(a);}
    }
}

void printMyString(struct myString a){
    printf("%s \n", a.arr);
}

void fprintMyString(struct myString a, FILE *fptr){
    fprintf(fptr,"%s,", a.arr);
}