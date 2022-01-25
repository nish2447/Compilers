/*
Simulate a DFA that recognizes an unsigned number
*/


#include<stdio.h>
#include<ctype.h>
char digits[] = "0123456789";
char sign[] = "+-";
char dot[] = ".";
char expo[] = "eE";
int mat[11][5];

int find(char *s,char fd) {
	int i;
    for(i = 0; s[i] != '\0'; i++) {
    	if(s[i]==fd) return 1;
	}
	return 0;
}

void buildDFA()
{
    int i,j;
    for ( i = 0; i < 11; i++)
        for (j = 0; j < 5; j++)
            mat[i][j] = 10;

    mat[0][0]=1;
    mat[1][0]=1;
    mat[1][2]=3;
    mat[1][3]=2;
    mat[1][4]=6;
    mat[3][0]=4;
    mat[4][0]=4;
    mat[4][3]=5;
    mat[4][4]=6;
    mat[6][0]=8;
    mat[6][1]=7;
    mat[7][0]=8;
    mat[8][0]=8;
    mat[8][3]=9;

}

void checkDFA(char *s,int n)
{
    buildDFA();
    int pos=0;
    int i;
    for (i=0; i<n; i++) {
        if (find(digits,s[i])) pos=mat[pos][0];
        else if (find(sign,s[i])) pos=mat[pos][1];
        else if (find(dot,s[i])) pos=mat[pos][2];
        else if (find(expo,s[i])) pos=mat[pos][4];
        else pos=mat[pos][3];
    }
    if (pos == 1 || pos == 4 || pos == 8) printf("Unsigned integer\n");
    else printf("Not an unsigned integer\n");
}
 
int main()
{
	char a[] = "28484";
	char b[] = "0.11111";
	char c[] = "-138459";
    int i;
    for(i = 0; a[i] != '\0'; i++);
    checkDFA(a,i);
    for(i = 0; b[i] != '\0'; i++);
    checkDFA(b,i);
    for(i = 0; c[i] != '\0'; i++);
    checkDFA(c,i);
    return 0;
}
