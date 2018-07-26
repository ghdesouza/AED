#include "Listas.h"

#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

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
	 *  \param tipo_grafo  -  Define se o grafo é direcionado ou não
         *  Constroi o Grafo de acordo com as informações do arquivo.
         *  \return Sem Retorno
         */
		Grafo(char nome_arquivo[], char tipo_grafo);
		
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


#endif // GRAFO_H_INCLUDED

