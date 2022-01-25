/*
Write a program to count the number of newlines in the program
*/

/*  B-15 Group Members

BT19CSE087  Ashok Karwa
BT19CSE088  Shiv Kumar Sakhre
BT19CSE136  Nischay Yadav
BT19CSE137  Rudransh Tripathi

*/


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>


//for const
bool isConst(char *str)
{
    if(strcmp(str,"const") || strcmp(str,"#define"))
    return (true);

    return (false);
}

int main()
{
    FILE *filepointer;

    filepointer = fopen("input.txt","r");
    int count= 0;
    if(filepointer == NULL)
    {
        printf("file didn't open");
    }
    else
    {
    
        char ch;
        while ((ch = fgetc(filepointer)) != EOF)
        {
           if(ch=='\n')
           count++;

        }
        printf("No of New Lines: %d", count);

    }

    fclose(filepointer);
    getchar();

    return 0;
    
    
}