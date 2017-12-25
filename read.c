#include "libs/headers.h"
#define INVALID_MSG "O valor digitado foi invalido, por favor tente novamente\n"

//função limpa o buffer
static void cleanBuffer()
{
    int c;
    do{
	c = getchar();	
    }while(c != '\n' && c != EOF);
}

//função generica para ler um char
static char readChar( char* msg, int(*cb)(char) )
{
    int v;
    char c;
    do{
	fprintf(stdout,"%s",msg);
	scanf("%c",&c);
	cleanBuffer();
	if(!(v = cb(c)))
	{
	    printf("\e[H\e[2J");
	    fprintf(stdout,"%s",INVALID_MSG);
	}
    }while(!v);
    return c;
}

//ler um caractere do alfabeto
char readAlpha(char* msg)
{
    return readChar( msg, isAlpha );
}

//ler um digito
char readDigit(char* msg)
{
    return readChar( msg, isDigit );
}
