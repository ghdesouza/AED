/*
GABRIEL BRANDAO DE MIRANDA 102190180
GABRIEL HENRIQUE DE SOUZA 102190173
*/

#include "Include/Grafo.h"

int main(int argc, char* argv[]){
	
	
	if(argc!=3 || ( *argv[2]!= 'G' && *argv[2]!= 'D' ) ){
        printf("Uso:	./main <arquivo_de_entrada.txt> <G-Grafo, D-Digrafo>");
        return 1;
    }
	
	char *nome_arq = argv[1];
	Grafo *grafo = new Grafo(nome_arq, *argv[2]);
	grafo->topologia();
	grafo->menor_caminho();
	
	delete grafo;
	return 0;
}

