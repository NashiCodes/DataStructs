#include <iostream>
#include "ListaEnc.h"

using namespace std;

ListaEnc::ListaEnc()
{
    primeiro = NULL;
}

ListaEnc::~ListaEnc()
{
    No *p = primeiro;

    while (p != NULL)
    {
        No *t = p->getprox(); // Salvando o endereço do proximo nó
        delete p;             // Deletando o nó atual

        p = t; // Andando na Lista
    }
}

void ListaEnc::insereInicio(int val)
{
    No *p = new No(); // Cria um novo Nó para a lista

    p->setinfo(val);      // Inserindo a informação no Nó
    p->setprox(primeiro); // Preenche proximo

    primeiro = p; // Nó apontado por p passa a ser o primeiro da lista
}