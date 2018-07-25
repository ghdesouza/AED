/*
GABRIEL BRANDAO DE MIRANDA 102190180
GABRIEL HENRIQUE DE SOUZA 102190179
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Libs/Grafo.h"

int main(int argc, char* argv[]){

	if(argc!=2){
        printf("Uso:  ./main <arquivo_de_entrada.txt> ");
        return 1;
    }
	
	char *nome_arq = argv[1];
	Grafo *grafo = new Grafo(nome_arq);
	grafo->topologia();
	
	delete grafo;
	return 0;
}
