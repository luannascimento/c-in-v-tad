#include "libs/headers.h"

//função responsavel por fazer a validação da explessão regular
static int match( char* str, char* regex )
{
    regex_t reg;
	
    if( regcomp(&reg, regex, REG_EXTENDED|REG_NOSUB ) != 0 )
    {
	fprintf(stdout,"Erro expressão regular invalida\n");
	exit(1);
    }
				
    if( (regexec( &reg, str, 0, (regmatch_t*)NULL, 0)) != 0 )
    {
	return 0;
    }
						    
    return 1;
}

//verifica se o caractere e uma letra do alfabeto
int isAlpha( char c )
{
    return isalpha( c ) ? 1 : 0;
}

//verifica se o caractere e um digito numerico
int isDigit( char d )
{
    return isdigit( d ) ? 1 : 0;
}

//valida se o name so possui letras do alfabeto e espaços com no minimo 2 letras
int isName( char* name )
{
    return match( name, "^([A-Z a-z À-ú]{1}[A-Z a-z À-ú]+)$" );
}

//valida se um numero e float ou double
int isFloat( char* real )
{
    return match( real, "^([-]?[0-9]+([.][0-9]+)?)$" );
}


