#include <iostream>
#include <cstdlib>
#include "ListaD.h"

using namespace std;

ListaD::ListaD()
{
    // Lista é iniciada
    cout << "Criando Lista..." << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaD::~ListaD()
{
    cout << endl;
    cout << "Destruindo Lista..." << endl;
    NoDuplo *p = primeiro;

    while (p != NULL)
    {
        NoDuplo *t = p->getprox();
        delete p;

        p = t;
    }
}

void ListaD::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo(); // Novo Nó é criado
    p->setinfo(val);            // Informação é inserida
    p->setprox(primeiro);       // Proximo de P recebe Primeiro
    p->setant(NULL);            // Anterior recebe nulo

    if (n == 0)              // Se for o primeiro
        ultimo = p;          // Ultimo recebe p
    else                     // Caso contrario
        primeiro->setant(p); // Anterior de primeiro recebe p

    primeiro = p;
    n++;
}