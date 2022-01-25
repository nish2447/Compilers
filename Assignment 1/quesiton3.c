/*
Write a program that counts the number constants in the program. Constant
can be integer, float, character or string (literal).
*/

/*  B-15 Group Members

BT19CSE087  Ashok Karwa
BT19CSE088  Shiv Kumar Sakhre
BT19CSE136  Nischay Yadav
BT19CSE137  Rudransh Tripathi

*/


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isDelimiter(char ch)
{
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
		ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
		ch == '[' || ch == ']' || ch == '{' || ch == '}')
		return (true);
	return (false);
}

bool isDecimal(char *str)
{
	int i, len = strlen(str);
	bool hasDecimal = false;

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' ||
			(str[i] == '-' && i > 0))
			return (false);
		if (str[i] == '.')
			hasDecimal = true;
	}
	return (hasDecimal);
}
bool isCharacterConstant(char *s)
{
	if (s[0] == '\'')
		if (s[strlen(s) - 1] = '\'')
			return true;

	return false;
}

bool isConstant(char *s)
{

	int len = strlen(s);
	int c = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			c++;
		else
			return false;
	}
	return true;
}

bool isHexaConstant(char *s)
{
	if (strlen(s) > 1 && s[0] == '0' && s[1] == 'X')
		return true;
	if (strlen(s) > 1 && s[0] == '0' && s[1] == 'x')
		return true;
	return false;
}
bool isBinaryConstant(char *s)
{
	if (strlen(s) > 1 && s[0] == '0' && s[1] == 'b')
		return true;

	return false;
}

char *subString(char *str, int left, int right)
{
	int i;
	char *subStr = (char *)malloc(
		sizeof(char) * (right - left + 2));

	for (i = left; i <= right; i++)
		subStr[i - left] = str[i];
	subStr[right - left + 1] = '\0';
	return (subStr);
}

void parseForConstant(char *str)
{
	int left = 0, right = 0;
	int len = strlen(str);

	while (right <= len && left <= right)
	{
		if (isDelimiter(str[right]) == false)
			right++;

		if (isDelimiter(str[right]) == true && left == right)
		{

			right++;
			left = right;
		}
		else if (isDelimiter(str[right]) == true && left != right || (right == len && left != right))
		{
			char *subStr = subString(str, left, right - 1);

			if (isCharacterConstant(subStr) == true)
				printf("'%s' IS A CHARACTER CONSTANT\n", subStr);

			else if (isDecimal(subStr) == true)
				printf("'%s' IS A FLOAT CONSTANT\n", subStr);
			else if (isConstant(subStr) == true)
				printf("'%s' IS A INTEGER CONSTANT\n", subStr);
			else if (isHexaConstant(subStr) == true)
				printf("'%s' IS A HEXADECIMAL CONSTANT\n", subStr);
			else if (isBinaryConstant(subStr) == true)
				printf("'%s' IS A BINARY CONSTANT\n", subStr);

			left = right;
		}
	}
	return;
}

int main()
{
	FILE *filePointer;
	int bufferLength = 255;
	char buffer[bufferLength];

    filePointer = fopen("inputFile.c", "r");

	while (fgets(buffer, bufferLength, filePointer))
	{
		int len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
		{
			buffer[len - 1] = 0;
			
		}
		parseForConstant(buffer);
	}
	fclose(filePointer);
}