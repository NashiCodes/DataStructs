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