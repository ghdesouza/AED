#### Intruções básicas de uso do programa ####

### COMPILAR ###
	Executar o comando "make" no terminal um executável
	"main" será gerado após a compilação

### EXECUCÃO DO CÓDIGO ###
	Digitar "./main" no terminal passando o arquivo e o tipo do grafo como parâmetros:
	./main <arquivo_de_entrada.txt> <G-Grafo, D-Digrafo>

### ARQUIVO DE ENTRADA ###
	O arquivo de entrada do programa segue o seguinte formato:
	"nome_do_arquivo.txt"
	
	Com os dados no formato:
	
	-número de nós (N);
	-número de arestas (M);
	-nó origem (s);
	-nó destino (t);
	-horário de saída;
	//Restrições de janela de tempo de cada um dos N nós
	- 1 <inicio> <fim>
	- .    .       .
	- .    .       .
	- .    .       .
	- N <inicio> <fim>
	//Se não houver restrições, colocar 0000 0000;

	// M arestas com nós origem e destino e seus pesos
	- 1 <no_origem> <no_destino> <peso>
	- .      .           .         .
	- .      .           .         .
	- .      .           .         .
	- M <no_origem> <no_destino> <peso>

### DOCUMENTACAO ###
	Há ainda uma pasta com uma documentação do código elaborado em /Docs,
	visando tornar mais fácil o entendimento da implementação do programa.

