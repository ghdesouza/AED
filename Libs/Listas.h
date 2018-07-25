
struct No_lista_no;
class Lista_no;
struct No_lista_aresta;
class Lista_aresta;

struct No_lista_no{
	int identificador, predecessor, distacia, avaliado;
	int chegada, saida;
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
		void Add_no(int indent, int predec, int dist, int cheg, int said);
};

void Lista_no::Add_no(int ident, int predec, int dist, int cheg, int said){
	
	No_lista_no *novo_no = new No_lista_no;
	novo_no->lista_aresta = new Lista_aresta;
	novo_no->identificador = ident;
	novo_no->predecessor = predec;
	novo_no->distacia = dist;
	novo_no->avaliado = 0;
	novo_no->chegada = cheg;
	novo_no->saida = said;
	
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
}

class Lista_aresta{

	private:
		No_lista_aresta* raiz;
		
	public:
		Lista_aresta(){ this->raiz = NULL; }
		~Lista_aresta();
		void Add_aresta(int dest, int pes);
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
