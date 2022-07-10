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

    void insereInicio(int val); // Insere no inicio da Lista
    void insereFinal(int val);  // Insere no Final da Lista
    void removeInicio();        // Remove o inicio da lista
    void removeFinal();         // Remove o final da lista
    bool busca(int val);        // Procura um valor na Lista
    void imprime();             // Imprime a Lista
    void imprimeReverso();      // Imprime a Lista de tras pra frente
};
