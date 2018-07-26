#include "../Include/Listas.h"

Lista_no::Lista_no(){
	this->raiz = NULL;	
}

Lista_no::~Lista_no(){
	No_lista_no* temp = raiz;
	while(temp->proximo != NULL){
		temp = temp->proximo;
		delete temp->anterior->lista_aresta;
		delete temp->anterior;
	}
	delete temp->lista_aresta;
	delete temp;
}

No_lista_no* Lista_no::get_raiz(){
	return this->raiz;
}

No_lista_no* Lista_no::busca_no(int ident){
	No_lista_no *temp = this->raiz;
	
	while(temp != NULL){	
		if(temp->identificador == ident) return temp;
		temp = temp->proximo;
	}
	
	printf("ERRO: Nao existe o ID buscado!\n");
	return NULL;
}

void Lista_no::Add_no(int ident, int cheg, int said){
	
	No_lista_no *novo_no = new No_lista_no;
	novo_no->lista_aresta = new Lista_aresta();
	novo_no->identificador = ident;
	novo_no->predecessor = -1;
	novo_no->distancia = RAND_MAX;
	novo_no->avaliado = 0;
	novo_no->chegada = (((int)cheg/100)*60)+cheg%100;
	novo_no->saida = (((int)said/100)*60)+said%100;

	if( this->raiz == NULL ){
		this->raiz = novo_no;
		this->raiz->anterior = NULL;
	}
	else{
		this->fim->proximo = novo_no;
		novo_no->anterior = this->fim;
		novo_no->proximo = NULL;
	}
	this->fim = novo_no;
}

Lista_aresta::Lista_aresta(){
	this->raiz = NULL;
}

Lista_aresta::~Lista_aresta(){
	No_lista_aresta* temp = raiz;
	if(temp != NULL){
		while(temp->proximo != NULL){
			temp = temp->proximo;
			delete temp->anterior;
		}
		delete temp;
	}
}

No_lista_aresta* Lista_aresta::get_raiz(){
	return this->raiz;
}

void Lista_aresta::Add_aresta(int dest, int pes){
	
	No_lista_aresta *nova_aresta = new No_lista_aresta;
	nova_aresta->destino = dest;
	nova_aresta->peso = 60*pes;
	
	nova_aresta->anterior = NULL;
	if( this->raiz == NULL ) nova_aresta->proximo = NULL;
	else{
		this->raiz->anterior = nova_aresta;
		nova_aresta->proximo = this->raiz;
	}
	this->raiz = nova_aresta;
	
	return;
}

