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