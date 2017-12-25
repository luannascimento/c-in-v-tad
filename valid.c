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
