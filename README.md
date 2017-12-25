# c-in-v-tad
Leitura e validação de dados em c.


<h2>Funções estaticas dos TADs</h2>

<h3>match</h3>
<p>descrição</p>
Compilação e validação de expressão regular
<p>protótipo</p>
<i>static int match( char* str, char* regex );</i>

<h3>cleanBuffer</h3>
<p>descrição</p>
Limpa o buffer do techado e arquivos
<p>protótipo</p>
<i>static void cleanBuffer( void );</i>

<h3>readChar</h3>
<p>descrição</p>
ler um char atendendo a validação de uma função de callback
<p>protótipo</p>
<i>static char readChar( char* msg, int (*cb)( char ) );</i>
