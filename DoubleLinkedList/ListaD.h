/**
 * @file ListaD.h
 * @brief Definição da classe ListaD e seus métodos.
 */

#include "NoDuplo.h"

class ListaD
{
private:
    NoDuplo *primeiro;
    NoDuplo *ultimo;
    int n;

public:
    /**
     * @brief Construtor da classe ListaD.
     *
     * Inicializa uma nova lista duplamente encadeada.
     */
    ListaD();

    /**
     * @brief Destrutor da classe ListaD.
     *
     * Libera a memória alocada para todos os nós da lista.
     */
    ~ListaD();

    /**
     * @brief Insere um novo elemento no início da lista.
     *
     * @param val O valor a ser inserido.
     */
    void insereInicio(int val);

    /**
     * @brief Insere um novo elemento no final da lista.
     *
     * @param val O valor a ser inserido.
     */
    void insereFinal(int val);

    /**
     * @brief Insere um novo elemento na posição k da lista.
     *
     * @param k A posição onde o elemento será inserido.
     * @param val O valor a ser inserido.
     */
    void insereK(int k, int val);

    /**
     * @brief Remove o primeiro elemento da lista.
     */
    void removeInicio();

    /**
     * @brief Remove o último elemento da lista.
     */
    void removeFinal();

    /**
     * @brief Remove o elemento na posição k da lista.
     *
     * @param k A posição do elemento a ser removido.
     */
    void removeK(int k);

    /**
     * @brief Verifica se um valor está presente na lista.
     *
     * @param val O valor a ser buscado.
     * @return true se o valor estiver na lista, false caso contrário.
     */
    bool busca(int val);

    /**
     * @brief Obtém o valor do elemento na posição k da lista.
     *
     * @param k A posição do elemento na lista.
     * @return O valor do elemento na posição k.
     */
    int get(int k);

    /**
     * @brief Define o valor do elemento na posição k da lista.
     *
     * @param k A posição do elemento na lista.
     * @param val O novo valor a ser definido.
     */
    void set(int k, int val);

    /**
     * @brief Imprime os valores da lista.
     */
    void imprime();

    /**
     * @brief Imprime os valores da lista em ordem reversa.
     */
    void imprimeReverso();

    /**
     * @brief Limpa todos os elementos da lista, liberando a memória.
     */
    void limpar();

    /**
     * @brief Concatena a lista atual com outra lista e retorna a nova lista resultante.
     *
     * @param l2 A lista a ser concatenada com a lista atual.
     * @return Um ponteiro para a nova lista resultante.
     */
    ListaD *concatena(ListaD *l2);

    /**
     * @brief Divide a lista atual em duas a partir da posição x e retorna a segunda parte.
     *
     * @param x A posição a partir da qual a lista será dividida.
     * @return Um ponteiro para a segunda parte da lista original.
     */
    ListaD *partirInd(int x);

    /**
     * @brief Divide a lista atual em duas a partir do valor x e retorna a segunda parte.
     *
     * @param x O valor a partir do qual a lista será dividida.
     * @return Um ponteiro para a segunda parte da lista original.
     */
    ListaD *partirInf(int x);

    /**
     * @brief Remove todas as ocorrências de um valor da lista.
     *
     * @param val O valor a ser removido da lista.
     */
    void removeOcorrencias(int val);
};
