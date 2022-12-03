#include "NoDuplo.h"

class ListaD
{
private:
    NoDuplo *primeiro;
    NoDuplo *ultimo;
    int n;

public:
    ListaD();
    ~ListaD();

    void insereInicio(int val);      // Insere no inicio da Lista
    void insereFinal(int val);       // Insere no Final da Lista
    void insereK(int k, int val);    // cria um novo nó e insere o valor na posição
    void removeInicio();             // Remove o inicio da lista
    void removeFinal();              // Remove o final da lista
    void removeK(int k);             // Remove o nó "k" da lista
    bool busca(int val);             // Procura um valor na Lista
    int get(int k);                  // Retorna o valor inserido no indice K
    void set(int k, int val);        // Insere um valor no indice K
    void imprime();                  // Imprime a Lista
    void imprimeReverso();           // Imprime a Lista de tras pra frente
    void limpar();                   // Limpa a Lista
    ListaD *concatena(ListaD *l2);    // Concatena duas Listas
    ListaD *partirInd(int x);        // Parte uma lista em 2 a partir do indice x
    ListaD *partirInf(int x);        // Parte uma lista em 2 a partir do valor x
    void removeOcorrencias(int val); // Remove todas as ocorrencias de um valor
};
