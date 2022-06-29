#include "NoDuplo.h"

class ListaDupla
{
public:
    ListaDupla();
    ~ListaDupla();
    bool busca(int val);
    int get(int k);
    void set(int k, int val);
    void insereInicio(int val);
    void removeInicio();
    void insereFinal(int val); /// exercicio
    void removeFinal();        /// exercicio
    void imprime();
    void imprimeFinal();
private:
    NoDuplo *primeiro;
    NoDuplo *ultimo;
    int n;
};