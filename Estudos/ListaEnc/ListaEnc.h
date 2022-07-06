#include "No.h"
class ListaEnc
{
private:
    No *primeiro; // Toda lista tem seu Nó
public:
    ListaEnc();  // Construtor
    ~ListaEnc(); // Destrutor

    void insereInicio(int val); // Insere o valor no inicio
    bool busca(int val);        // Busca o valor
    void imprime();             // Imprime a lista
};