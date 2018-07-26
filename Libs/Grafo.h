#include <stdio.h>
#include <stdlib.h>

#include "Listas.h"

//! Grafo
/*!
  Estrutura de um Grafo para o problema de caminho minimo com janelas de tempo.
*/
class Grafo;


class Grafo{
	
	private:
		int hora; /*!< Hora de inicio do percurso. */
		int quant_nos; /*!< Quantidade de Nos do Grafo. */
		int quant_arestas; /*!< Quantidade de Arestas do Grafo. */
		Lista_no* lista_no; /*!< Lista de Nos do Grafo. */
		int id_inicio; /*! Identificador do No de partida do percurso. */
		int id_final; /*! Identificador do No final do percurso. */
		
		/*! \brief Soma com Janela de Tempo
         *  \param inicial - No de partida.
         *  \param fim - No de destino.
         *  \param peso - Tempo de viagem entre os 2 nos em minutos.
         *  Calcula o tempo em minutos de viagem entre 2 nos considerando a janela de tempo do No de destino.
         *  \return Tempo em minutos de viagem
         */
		int soma_com_janela(No_lista_no *inicial, No_lista_no *fim, int peso);
		
		/*! \brief Informacao para vizinhos
         *  \param no - No que ira enviar seu tempo aos vizinhos.
         *  Atualiza a distancia de todos os vizinhos de um No caso essa seja menor.
         *  \return void
         */
		void broadcast_distancia(No_lista_no *no);
	
	public:
	
        /*! \brief Construtor
         *  \param nome_arquivo - Nome do arquivo que possui a topologia do Grafo.
         *  Constroi o Grafo de acordo com as informações do arquivo.
         *  \return Sem Retorno
         */
		Grafo(char nome_arquivo[]);
		
        /*! \brief Destrutor
         *  Desaloca a memoria dinamica alocada para a criacao do Grafo.
         *  \return Sem Retorno
         */
		~Grafo();
		
        /*! \brief Topologia
         *  Informa as informacoes referentes a topologia do Grafo:
         *	Quantidade de Nos, Arestas, Pesos das arestas e janelas de tempo dos Nós.
         *  \return Void
         */
		void topologia();
		
        /*! \brief Menor Caminho
         *	Encontra o menor caminho entre o No de Origem e o No de Destino usando o algoritmo de Dijkstra considerando as janelas de tempo.
         *  \return Void
         */
		void menor_caminho();
};

/// ------------------------------------------------------------------------------------------------------------------ ///

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
		this->hora = (((int)(this->hora/100))*60)+this->hora%100;
        
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
			this->lista_no->busca_no(temp1)->lista_aresta->Add_aresta(temp2, temp3);
			//this->lista_no->Busca_no(temp2)->lista_aresta->Add_aresta(temp1, temp3);	// Descomentar Essa linha se for Nao direcionado
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
			temp2 = temp2->proximo;
		}
		temp = temp->proximo;
	}
	printf("\n");
	return;
}

void Grafo::menor_caminho(){
	
	No_lista_no *no_temp;
	
	no_temp = this->lista_no->busca_no(this->id_inicio);
	no_temp->distancia = 0;
	soma_com_janela(no_temp, no_temp, 0);
	this->broadcast_distancia(no_temp);
	
	no_temp = this->lista_no->busca_no(this->id_final);
	printf("Tempo total: %02d:%02d\tCaminho: ", (int)no_temp->distancia/60, no_temp->distancia%60);
	while(no_temp->identificador != id_inicio){
		printf("%02d <- ", no_temp->identificador);
		no_temp = this->lista_no->busca_no(no_temp->predecessor);
	}	
	printf("%02d\n\n", no_temp->identificador);
}

void Grafo::broadcast_distancia(No_lista_no *no){
	
	No_lista_no *no_temp;
	No_lista_aresta *aresta_temp = no->lista_aresta->get_raiz();
	int dist_temp;
	
	while(aresta_temp != NULL){
		no_temp = this->lista_no->busca_no(aresta_temp->destino);
		dist_temp = this->soma_com_janela(no, no_temp, aresta_temp->peso);
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
	
	return (tempo_viagem+tempo_parado);
}

