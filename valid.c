#include "libs/headers.h"

int peso = 10;

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

static int* cpfArray( char* cpf )
{
  int* v = (int *) calloc(11,sizeof(int));
  if( !v )
  {
    fprintf(stdout,"Erro!, Memoria Insuficinete\n");
    exit(1);
  }
  int i;
  for(i = 0; i < 11; i++)
  {
    v[i] = cpf[i] - '0';
  }
  return v;
}

static int cpfDigit( int* cpf )
{
  int i, j, sum = 0;
  for(i = 0, j = peso; i < peso - 1; i++, j--)
  {
    sum += j * cpf[i];
  }

  int digit = (11 - sum%11) > 9 ? 0 : (11 - sum%11);

  if( cpf[peso - 1] != digit )
  {
    peso = 10;
    return 0;
  }

  if(peso == 11)
  {
    peso = 10;
    return 1;
  }
  peso = 11;
  return cpfDigit( cpf );
}

static int cpfIgualDigits( char* cpf )
{
  int i, igual = 0;
  for(i = 1; i < 11; i++ )
  {
    if(cpf[0] == cpf[i])
    {
      igual++;
    }
  }
  if(igual == 10)
    return 0;
  
  return 1;
}

int isCpf( char* cpf )
{
  int v = match( cpf, "^([0-9]{11})$");
  int v1 = cpfIgualDigits( cpf );

  if( v && v1 )
  {
    int* array = cpfArray( cpf );
    v = cpfDigit( array );
    free( array );
    return v;
  }
  return 0;
}


