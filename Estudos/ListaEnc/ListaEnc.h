#include "No.h"
class ListaEnc
{
private:
    No *primeiro; // Toda lista tem seu Nó
    No *ultimo;   // Ultimo nó da lista
    int n;        // Numero de nós da lista
public:
    ListaEnc();  // Construtor
    ~ListaEnc(); // Destrutor

    bool busca(int val);          // Busca o valor
    int get(int k);               // Retorna o valor inserido no indice K
    void set(int k, int val);     // Insere um valor no indice K
    void imprime();               // Imprime a lista
    void insereInicio(int val);   // Insere o valor no inicio
    void inserefinal(int Val);    // Insere o valor no final da lista
    void insereK(int k, int val); // cria um novo nó e insere o valor na posição
    void removeinicio();          // Remove o primeiro nó da lista
    void removefinal();           // Remove o ultimo nó da lista
    void removeK(int k);          // Remove o nó "k" da lista
};