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

    if (n == 0)              // Se a lista estiver vazia
        ultimo = p;          // Ultimo será p
    else                     // Caso contrario
        primeiro->setant(p); // Anterior do primeiro atual será p

    primeiro = p; // O novo Nó se torna o primeiro
    n++;
}

void ListaD::insereFinal(int val)
{
    NoDuplo *p = new NoDuplo(); // Novo Nó é criado
    p->setinfo(val);            // Informação é inserida
    p->setprox(NULL);           // Proximo dele será nulo
    p->setant(ultimo);          // Anterior dele será o ultimo atual da lista

    if (n == 0)             // Se a lista estiver vazia
        primeiro = p;       // O primeiro será p
    else                    // Caso contrario
        ultimo->setprox(p); // O proximo do ultimo atual será p

    ultimo = p; // O novo Nó se torna o ultimo
    n++;
}

void ListaD::removeInicio()
{
    NoDuplo *p;

    if (primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getprox();
        delete p;
        n--;

        if (n == 0)
            ultimo = NULL;
        else
            primeiro->setant(NULL);
    }
    else
    {
        cout << "ERRO: Lista Vazia..." << endl;
    }
}

void ListaD::removeFinal()
{
    NoDuplo *p;

    if (primeiro != NULL)
    {
        p = ultimo;
        ultimo = p->getant();
        delete p;
        n--;

        if (n == 0)
            primeiro = NULL;
        else
            ultimo->setprox(NULL);
    }
    else
    {
        cout << "ERRO: Lista Vazia..." << endl;
    }
}