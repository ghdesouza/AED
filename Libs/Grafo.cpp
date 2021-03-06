#include "../Include/Grafo.h"

Grafo::Grafo(char nome_arquivo[], char tipo_grafo){
	
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
		this->hora = (((int)(this->hora/100))*60)+this->hora%100;
        
        for(int i = 0; i < this->quant_nos; i++){
			fscanf(arq, "%d", &temp1);
			fscanf(arq, "%d", &temp2);
			fscanf(arq, "%d", &temp3);
			this->lista_no->Add_no(temp1, temp2, temp3);			
		}
	
	if(tipo_grafo == 'G' ){
	        for(int i = 0; i < this->quant_arestas; i++){
			fscanf(arq, "%d", &temp1);
			fscanf(arq, "%d", &temp2);
			fscanf(arq, "%d", &temp3);
			this->lista_no->busca_no(temp1)->lista_aresta->Add_aresta(temp2, temp3);
			this->lista_no->busca_no(temp2)->lista_aresta->Add_aresta(temp1, temp3);
		}
	}else{
		for(int i = 0; i < this->quant_arestas; i++){
			fscanf(arq, "%d", &temp1);
			fscanf(arq, "%d", &temp2);
			fscanf(arq, "%d", &temp3);
			this->lista_no->busca_no(temp1)->lista_aresta->Add_aresta(temp2, temp3);
		}	
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
	
	FILE *arq = fopen("Grafo.csv", "w");

	printf("\nQuantidade de Nos: %d\n", this->quant_nos);
	printf("Quantidade de Aresta: %d\n", this->quant_arestas);
	printf("No Inicial: %d\n", this->id_inicio);
	printf("No Final: %d\n", this->id_final);
	printf("Horario de Saida: %d:%d\n\n", (int)this->hora/60, this->hora%60);
	
	printf("Janelas de tempo:\n");
	No_lista_no *temp = lista_no->get_raiz();
	while(temp != NULL){
		printf("\t%2d\t%02d:%02d\t%02d:%02d\n", temp->identificador, (int)temp->chegada/60, temp->chegada%60, (int)temp->saida/60, temp->saida%60);
		temp = temp->proximo;
	}
	
	printf("Arestas:\n");
	temp = lista_no->get_raiz();
	No_lista_aresta *temp2;
	while(temp != NULL){
		temp2 = temp->lista_aresta->get_raiz();
		while(temp2 != NULL){
			printf("\t( %02d, %02d )\t%02d:%02d\n", temp->identificador, temp2->destino, (int)temp2->peso/60, (int)temp2->peso%60);
			fprintf(arq, "%02d, %02d, 01", temp->identificador, temp2->destino);
			if(temp2->proximo != NULL || temp->proximo != NULL) fprintf(arq, "\n"); 
			temp2 = temp2->proximo;
		}
		temp = temp->proximo;
	}
	printf("\n");

	fclose(arq);

	return;
}

void Grafo::menor_caminho(){
	
	FILE *arq2 = fopen("Caminho.csv", "w");

	No_lista_no *no_temp;
	int dist_temp;	

	no_temp = this->lista_no->busca_no(this->id_inicio);
	no_temp->distancia = 0;
	dist_temp = soma_com_janela(no_temp, no_temp, 0);
	no_temp->distancia = dist_temp;
	this->broadcast_distancia(no_temp);
	
	no_temp = this->lista_no->busca_no(this->id_final);
	printf("Tempo total: %02d:%02d\tCaminho: ", (int)no_temp->distancia/60, no_temp->distancia%60);
	while(no_temp->identificador != id_inicio){
		printf("%02d <- ", no_temp->identificador);
		fprintf(arq2, "%02d\n", no_temp->identificador);
		no_temp = this->lista_no->busca_no(no_temp->predecessor);
	}	
	printf("%02d\n\n", no_temp->identificador);
	fprintf(arq2, "%02d", no_temp->identificador);

	fclose(arq2);
}

void Grafo::broadcast_distancia(No_lista_no *no){
	
	No_lista_no *no_temp;
	No_lista_aresta *aresta_temp = no->lista_aresta->get_raiz();
	int dist_temp;
	
	while(aresta_temp != NULL){
		no_temp = this->lista_no->busca_no(aresta_temp->destino);
		dist_temp = this->soma_com_janela(no, no_temp, aresta_temp->peso);
//		printf("%d \t%d \t%d \t%d \n", no->identificador, no_temp->identificador, dist_temp, no_temp->distancia);
		if(no_temp->distancia > dist_temp){
			no_temp->distancia = dist_temp;
			no_temp->predecessor = no->identificador;
			broadcast_distancia(no_temp);
		}		
		aresta_temp = aresta_temp->proximo;
	}	
}

int Grafo::soma_com_janela(No_lista_no *inicial, No_lista_no *fim, int peso){
	int tempo_viagem = inicial->distancia+peso;
	int tempo_parado = 0;
	int hora_viagem = (this->hora+tempo_viagem)%1440;
	if(fim->chegada != 0 || fim->saida != 0){
		if(hora_viagem < fim->chegada) tempo_parado = fim->chegada-hora_viagem;
		else if(hora_viagem > fim->saida) tempo_parado = 1440-(hora_viagem-fim->chegada);
	}
//	printf("%d \t%d \t %d \t %d \n", inicial->identificador, tempo_viagem, tempo_parado, hora_viagem);
	return (tempo_viagem+tempo_parado);
}

