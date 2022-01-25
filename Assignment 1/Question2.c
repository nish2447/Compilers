/*
Write a program that counts the number of keywords in the program.
Create a Symbol Table consisting of the list of C keywords and then use it
in the program.
*/


#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdbool.h>

const char search[6] = "const";

int constantCount(FILE* filePointer) {
    int constCount=0;
    int bufferLength = 255;
    char line[bufferLength];
    int i, j, found= 0, strLen, wordLen;
    bool quoteBool = false;
    

    while(fgets(line, bufferLength, filePointer))
    {
        char *ptr = strstr(line, search);
        if (ptr != NULL) 
        {
            strLen = strlen(ptr);
            wordLen = strlen(search);

            for(i=0; i<strLen; i++)
            {
                found = 0;
                if (ptr[i] == '\"'){
                    if (quoteBool == false)
                        quoteBool = true;
                    else
                        quoteBool = false;
                }

                if(quoteBool == false)
                {
                    found = 1;
                    for(j = 0; j<wordLen; j++)
                    {
                        // If word is not matched
                        if(ptr[i + j] != search[j])
                        {
                            found = 0;
                            break;
                        }
                    }
                    if(ptr[i + wordLen] != ' ')
                        found = 0;

                    if(found == 1)
                    {
                        constCount++;
                    }
                }

                // If word have been found then update counter
            } 
        }
    }
    return constCount;
}

void main()
{
    FILE* filePointer;
    char filename[100];

    printf("Enter the filename to open: ");
    scanf("%s", filename);

    filePointer = fopen(filename, "r");
    int constCount = constantCount(filePointer);
    printf("Total no. of constant variables are: %d\n", constCount);
    fclose(filePointer);
}
