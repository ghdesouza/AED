
struct No_lista_no;
struct No_lista_aresta;

class Lista_aresta{

	private:
		No_lista_aresta* raiz;
		
	public:
		Lista_aresta(){ this->raiz = NULL; }
		~Lista_aresta();
		No_lista_aresta* get_raiz(){ return this->raiz; }
		void Add_aresta(int dest, int pes);
		
};

struct No_lista_no{
	int identificador, predecessor, distacia, avaliado;
	int chegada[2], saida[2];
	No_lista_no *anterior;
	No_lista_no *proximo;
	Lista_aresta *lista_aresta;
};

class Lista_no{

	private:
		No_lista_no* raiz;
		
	public:
		Lista_no(){ this->raiz = NULL;}
		~Lista_no();
		No_lista_no* get_raiz(){ return this->raiz; }
		void Add_no(int ident, int cheg, int said);
		No_lista_no* Busca_no(int ident);
};

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

No_lista_no* Lista_no::Busca_no(int ident){
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
	novo_no->predecessor = 0;
	novo_no->distacia = 0;
	novo_no->avaliado = 0;
	novo_no->chegada[0] = (int)cheg/100;
	novo_no->chegada[1] = cheg%100;
	novo_no->saida[0] = (int)said/100;
	novo_no->saida[1] = said%100;
	
	novo_no->anterior = NULL;
	if( this->raiz == NULL ) novo_no->proximo = NULL;
	else{
		this->raiz->anterior = novo_no;
		novo_no->proximo = this->raiz;
	}
	this->raiz = novo_no;

	return;
}

struct No_lista_aresta{
	int destino;
	int peso;
	No_lista_aresta *proximo;
	No_lista_aresta *anterior;	
};

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

void Lista_aresta::Add_aresta(int dest, int pes){
	
	No_lista_aresta *nova_aresta = new No_lista_aresta;
	nova_aresta->destino = dest;
	nova_aresta->peso = pes;
	
	nova_aresta->anterior = NULL;
	if( this->raiz == NULL ) nova_aresta->proximo = NULL;
	else{
		this->raiz->anterior = nova_aresta;
		nova_aresta->proximo = this->raiz;
	}
	this->raiz = nova_aresta;
	
	return;
}
