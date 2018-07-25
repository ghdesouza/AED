#include <stdio.h>
#include <stdlib.h>

#include "Libs/Grafo.h"

int main(){

	char nome_arq[] = "entrada.txt";
	Grafo *grafo = new Grafo(nome_arq);
	grafo->topologia();
	
	delete grafo;
	return 0;
}

