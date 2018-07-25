#include <stdio.h>
#include <stdlib.h>

#include "Listas.h"

class Grafo{
	
	private:
		int hora;
		int quant_nos;
		int quant_arestas;
		Lista_no* lista_no;
		int id_inicio;
		int id_final;
	
	public:
		Grafo(char nome_arquivo[]);
		~Grafo();
		void topologia();
};

Grafo::Grafo(char nome_arquivo[]){
	
	this->lista_no = new Lista_no();
	
    FILE* arq;
    arq = fopen(nome_arquivo, "r");
    int temp1, temp2, temp3;
    if(arq != NULL){
        fscanf(arq, "%d", &this->quant_nos);
        fscanf(arq, "%d", &this->quant_arestas);
        fscanf(arq, "%d", &this->id_inicio);
        fscanf(arq, "%d", &this->id_final);
        fscanf(arq, "%d", &this->hora);
        
        for(int i = 0; i < this->quant_nos; i++){
			fscanf(arq, "%d", &temp1);
			fscanf(arq, "%d", &temp2);
			fscanf(arq, "%d", &temp3);
			this->lista_no->Add_no(temp1, temp2, temp3);			
		}
		
        for(int i = 0; i < this->quant_arestas; i++){
			fscanf(arq, "%d", &temp1);
			fscanf(arq, "%d", &temp2);
			fscanf(arq, "%d", &temp3);
			this->lista_no->Busca_no(temp1)->lista_aresta->Add_aresta(temp2, temp3);			
		}
        
        fclose(arq);
    }else{
        printf("ERRO: NAO FOI POSSIVEL ABRIR A ENTRADA!\n");
    }
}

Grafo::~Grafo(){
	delete this->lista_no;
}

void Grafo::topologia(){
	
	printf("\nQuantidade de Nos: %d\n", this->quant_nos);
	printf("Quantidade de Aresta: %d\n", this->quant_arestas);
	printf("No Inicial: %d\n", this->id_inicio);
	printf("No Final: %d\n", this->id_final);
	printf("Horario de Saida: %d:%d\n\n", (int)this->hora/100, this->hora%100);
	
	printf("Janelas de tempo:\n");
	No_lista_no *temp = lista_no->get_raiz();
	while(temp != NULL){
		printf("\t%2d\t%02d:%02d\t%02d:%02d\n", temp->identificador, temp->chegada[0], temp->chegada[1], temp->saida[0], temp->saida[1]);
		temp = temp->proximo;
	}
	
	printf("Arestas:\n");
	temp = lista_no->get_raiz();
	No_lista_aresta *temp2;
	while(temp != NULL){
		temp2 = temp->lista_aresta->get_raiz();
		while(temp2 != NULL){
			printf("\t( %02d, %02d )\t%02d\n", temp->identificador, temp2->destino, temp2->peso);
			temp2 = temp2->proximo;
		}
		temp = temp->proximo;
	}
	printf("\n");
	return;
}
