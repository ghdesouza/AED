#include <stdio.h>
#include <stdlib.h>

#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED


//! No da Lista de Nos do Grafo
/*!
  Estrutura que armazena as informacoes do No do grafo de forma a serem armazenados em uma lista.
*/
struct No_lista_no;

//! No da Lista de Aresta do No
/*!
  Estrutura que armazena as informacoes das Arestas que saem de um determidado No de forma a serem armazenados em uma lista.
*/
struct No_lista_aresta;

//! Lista de Nos do Grafo
/*!
  Lista que contem os Nos pertencentes ao Grafo.
*/
class Lista_no;

//! Lista de Arestas do No
/*!
  Lista que contem as arestas pertencentes a um determinado No.
*/
class Lista_aresta;


struct No_lista_no{
	int identificador; /*!< Valor que indentifica um No. */
	int predecessor; /*!< Valor que informa qual o melhor predecessor para atingir o No. */
	int distancia; /*!< Indica a distancia do No de partida do Grafo ate o No atual. */
	bool avaliado; /*!< Informa se o No ja foi avaliado. */
	int chegada; /*!< Indica o Horario inicial da janela de tempo do No em minutos do inicio. */
	int saida; /*!< Indica o Horario final da janela de tempo do No em minutos do final. */
	No_lista_no *anterior; /*!< Ponteiro para o No anterior da Lista. */
	No_lista_no *proximo; /*!< Ponteiro para o No seguinte da Lista. */
	Lista_aresta *lista_aresta;	/*! Lista de Arestas que estao conectadas ao No. */
};

struct No_lista_aresta{
	int destino; /*!< Identificador do No de destino. */
	int peso; /*!< Peso da Aresta. */
	No_lista_aresta *anterior; /*!< Ponteiro para a Aresta anterior da Lista. */
	No_lista_aresta *proximo; /*!< Ponteiro para a Aresta seguinte da Lista. */
};

class Lista_no{

	private:
		No_lista_no* raiz; /*!< Ponteiro para o primeiro No da lista. */
		No_lista_no* fim; /*!< Ponteiro para o ultimo No da lista. */
		
	public:
	
        /*! \brief Construtor
         *  Inicializa a Lista de Nos vazia.
         *  \return Sem Retorno
         */
		Lista_no();
		
        /*! \brief Destrutor
         *  Desaloca a memoria dinamica alocada para a criacao da Lista de Nos.
         *  \return Sem Retorno
         */
		~Lista_no();
		
        /*! \brief Get Raiz
         *  Informa qual o primeiro No da Lista.
         *  \return Raiz da Lista
         */
		No_lista_no* get_raiz();
		
        /*! \brief Adicionar No
         *  \param ident - Identificador do No.
         *  \param cheg - Horario de inicio da janela de tempo do No.
         *  \param said - Horario de termino da janela de tempo do No.
         *  Adiciona um novo No na Lista.
         *  \return Sem Retorno
         */
		void Add_no(int ident, int cheg, int said);
		
        /*! \brief Get Raiz
         *  \param ident - Identificador do No.
         *  Informa qual o No pertencente a Lista que possui um determinado Identificador.
         *  \return No Buscado
         */
		No_lista_no* busca_no(int ident);
};

class Lista_aresta{

	private:
		No_lista_aresta* raiz; /*!< Ponteiro para a primeira Aresta da lista. */
		
	public:
	
        /*! \brief Construtor
         *  Inicializa a Lista de Arestas vazia.
         *  \return Sem Retorno
         */
		Lista_aresta();
		
        /*! \brief Destrutor
         *  Desaloca a memoria dinamica alocada para a criacao da Lista de Arestas.
         *  \return Sem Retorno
         */
		~Lista_aresta();
		
        /*! \brief Get Raiz
         *  Informa qual a primeira Aresta da Lista.
         *  \return Raiz da Lista
         */
		No_lista_aresta* get_raiz();
		
        /*! \brief Adicionar Aresta
         *  \param dest - Identificador do No de destino.
         *  \param pes - Peso da Aresta.
         *  Adiciona uma nova Aresta na Lista.
         *  \return Sem Retorno
         */
		void Add_aresta(int dest, int pes);
		
};

#endif // LISTAS_H_INCLUDED

