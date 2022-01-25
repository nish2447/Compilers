/*
. Write a program that will count the total number of identifiers in the
program and will also display the identifiers in the program. (Simulate the
DFA that recognizes an identifier)
*/


/*  B-15 Group Members

BT19CSE087  Ashok Karwa
BT19CSE088  Shiv Kumar Sakhre
BT19CSE136  Nischay Yadav
BT19CSE137  Rudransh Tripathi

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_limit 1000

// Global variable to keep count of no of identifiers
int identifiers_count =0;

/**
    A function to check if the character is special symbol or not.
    @param ch : character.
    @return True if it is special character else false.
*/
int  isSymbol(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
            ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
            ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (1);
    return (0);
}

/**
    A function to check if character is number or not.
    @param str : ptr to characters.
    @return False if it is number else true.
*/
int  is_number(char* str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
            str[0] == '3' || str[0] == '4' || str[0] == '5' ||
            str[0] == '6' || str[0] == '7' || str[0] == '8' ||
            str[0] == '9' || isSymbol(str[0]) == 1)
        return (0);
    return (1);
}

/**
    A function to simulate DFA
    @param str: ptr to characters denoting identifier.
    @return True if it is identifier else false.
*/
int DFAtoIdentifier(char *str)
{

    char state = 'i';
    // If the beginning character is number or symbol, it is not identifier
    if(str[0] == '0'||str[0] == '1' || str[0] == '2'
            || str[0] == '3'|| str[0] == '4'|| str[0] == '5'
            || str[0] == '6'|| str[0] == '7'|| str[0] == '8'
            || str[0] == '9'|| isSymbol(str[0]))
    {
        state = 'd';
    }
    else
    {
        state = 'f';
    }

    for(int c = 1; c < strlen(str); c++)
    {
        if(state == 'd'){       //  if it reaches dead state it will remain there.
            continue;
        }
        if(!isSymbol(str[c]))
        {
            state = 'f';
        }
        else
        {
            state = 'd';
        }

    }
    // return True if final state is reached else false
    return state == 'f' ? 1 : 0;
}

/**
    A function to check if the character is operator or not.
    @param ch : character.
    @return True if it is operator else false.
*/
int  is_operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=')
        return (1);
    return (0);
}

/**
    Function to check if the read string is keyword in C or not.
    @param : str - read string.
    @return : True if it is keyword else False.
*/
int isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else")
            || !strcmp(str, "while") || !strcmp(str, "do")
            || !strcmp(str, "break") || !strcmp(str, "continue")
            || !strcmp(str, "int")   || !strcmp(str, "double")
            || !strcmp(str, "float") || !strcmp(str,"malloc")
            || !strcmp(str, "return")|| !strcmp(str, "char")
            || !strcmp(str, "case")  || !strcmp(str, "char")
            || !strcmp(str, "sizeof")|| !strcmp(str, "long")
            || !strcmp(str, "short") || !strcmp(str, "typedef")
            || !strcmp(str, "switch")|| !strcmp(str, "unsigned")
            || !strcmp(str, "void")  || !strcmp(str, "static")
            || !strcmp(str, "struct")|| !strcmp(str, "goto"))
        return (1);
    return (0);
}

/**
    Function to check if the read chunk is integer.
    @param read string.
    @return True is it is integer else False.
*/
int  isInteger(char* str)
{
    int i, len = strlen(str);

    if (len == 0)
        return (0);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
                && str[i] != '3' && str[i] != '4' && str[i] != '5'
                && str[i] != '6' && str[i] != '7' && str[i] != '8'
                && str[i] != '9' || (str[i] == '-' && i > 0))
            return (0);
    }
    return (1);
}


int  isRealNumber(char* str)
{
    int i, len = strlen(str);
    int  hasDecimal = 0;

    if (len == 0)
        return (0);
    for (i = 0; i < len; i++)
    {
        if (  str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5'
                && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' || (str[i] == '-' && i > 0)  )
            return (0);
        if (str[i] == '.')
            hasDecimal = 1;
    }
    return (hasDecimal);
}

/**
    A function to form substring between left and right pointer.
    @param left - starting pointer , right- end pointer.
    @return substring
*/
char* subString(char* str, int left, int right)
{
    int i;
    // +1 to incorporate string ending character
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

/**
    Function to find and list identifiers.
    @param: read line.
    @return: None
*/
void find_indentifiers (char* str)
{
    int left = 0, right = 0;
    int len = strlen(str);

    while (right <= len && left <= right)
    {
        if (isSymbol(str[right]) == 0)
            right++;

        if (isSymbol(str[right]) == 1 && left == right)
        {
            right++;
            left = right;
        }
        else if (isSymbol(str[right]) == 1 && left != right || (right == len && left != right))
        {
            char* subStr = subString(str, left, right - 1);
            if (is_number(subStr) == 1 && isSymbol(str[right - 1]) == 0 && isKeyword(subStr) == 0 &&
                    isInteger(subStr) == 0 && isRealNumber(subStr) == 0 && is_operator(str[right]) == 0 )
            {
                if(strcmp(subStr,"main")!=0)
                {
                    printf("\n   %d -  %s ", identifiers_count+1, subStr);
                    identifiers_count++;
                }
            }
            left = right;
        }
    }

    return ;
}


int main()
{
    int n=0;
    printf("Type 'end' in last line after completing your code\n");
    printf("Caution : Do not use end as any identifier in your code \n");
    printf("Type your Code below \n");
    char str[max_limit][max_limit] ;

    while(n<max_limit)
    {
        scanf("%s[^\n]",str[n]);
        if(strcmp(str[n],"end")==0)
            break;
        n++;
    }
    printf("\n-----------------------------------------------");

    for(int i =0; i<n; i++)
    {
        find_indentifiers(str[i]);
    }

    printf("\n\nTotal Identifiers = %d",identifiers_count);
    printf("\n---------------OUTPUT-------------------------------");

    char *s = "1abd";
    char * result  = DFAtoIdentifier(s) ? "True" : "False";
    printf(" \n\nIs %s an Identifier? -------> %s", s, result );

    s = "_abd";
    result  = DFAtoIdentifier(s) ? "True" : "False";
    printf(" \n\nIs %s an Identifier? -------> %s", s, result );

    s = "a1b-d==";
    result  = DFAtoIdentifier(s) ? "True" : "False";
    printf(" \n\nIs %s an Identifier? -------> %s", s, result );

    return (0);
}
