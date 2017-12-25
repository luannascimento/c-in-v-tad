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

//ler strings
static char* readString()
{
    size_t size = 1;
    char v[120];
    char* str;
    scanf("%119[^\n]s",v);
    cleanBuffer();
    size += strlen(v);
    str = (char*)calloc(size,sizeof(char));
    if( !str )
    {
	fprintf(stdout,"Erro Memoria Insuficinete\n");
	exit(1);
    }
    strcpy(str,v);
    return str;
}

//função generica ler e valida valores
static char* readValue(char* msg,int (*cb)(char*))
{
    int v;
    char* value = NULL;
    do{
	fprintf(stdout,"%s",msg);
	value = readString();
	if( !( v = cb( value ) ) )
	{
	    printf("\e[H\e[2J");
	    fprintf(stdout,"%s",INVALID_MSG);
	    free(value);
	    value = NULL;
	}
    }while( !v );	
    return value;
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

//ler um nome de uma pessoa
char* readName( char* msg )
{
    return readValue( msg, isName );
}
