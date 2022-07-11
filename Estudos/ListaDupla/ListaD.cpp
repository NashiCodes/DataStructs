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

bool ListaD::busca(int val)
{
    NoDuplo *p;

    for (p = primeiro; p != NULL; p = p->getprox())
    {
        if (p->getinfo() == val)
            return true;
    }

    return false;
}

void ListaD::imprime()
{
    NoDuplo *p;

    if (n == 0)
    {
        cout << "ERRO: Lista Vazia!!!" << endl;
        return;
    }
    else
    {
        cout << "A lista contém os valores: " << endl;
        for (p = primeiro; p != NULL; p = p->getprox())
        {
            cout << p->getinfo() << " ";
        }
    }
    cout << endl;
}

void ListaD::imprimeReverso()
{
    NoDuplo *p;

    if (n == 0)
    {
        cout << "ERRO: Lista Vazia!!!" << endl;
        return;
    }
    else
    {
        cout << "A lista Reversa contém os valores: " << endl;
        for (p = ultimo; p != NULL; p = p->getant())
        {
            cout << p->getinfo() << " ";
        }
    }
    cout << endl;
}

ListaD *ListaD::concatena(ListaD *l2)
{
    if (n == 0)
    {
        cout << "ERRO: Lista Vazia!!!" << endl;
        return;
    }
    ultimo->setprox(l2->primeiro);
    l2->primeiro->setant(ultimo);
    ultimo = l2->ultimo;
    l2->primeiro = primeiro;

    n += l2->n;

    return l2;
}

ListaD *ListaD::partir(int x)
{
    NoDuplo *p;
    ListaD *ListaDividida = new ListaD();
    int i = 0;

    if (n == 0)
    {
        cout << "ERRO: Lista Vazia!!!" << endl;
        return;
    }

    for (p = primeiro; p != NULL; p = p->getprox())
    {
        if (i == x)
        {
            ListaDividida->primeiro = p;
            ListaDividida->ultimo = ultimo;
            ultimo = p->getant();
            ultimo->setprox(NULL);
            ListaDividida->primeiro->setant(NULL);
        }
        i++;
    }

    return ListaDividida;
}

void ListaD::removeOcorrencias(int val)
{
    NoDuplo *p;

    if (n == 0)
    {
        cout << "ERRO: Lista Vazia!!!" << endl;
        return;
    }

    for (p = primeiro; p != NULL; p = p->getprox())
    {
        if (p->getinfo() == val)
        {
            NoDuplo *t = p->getant();
            t->setprox(p->getprox());
            p->getprox()->setant(t);

            delete p;
            return;
        }
    }
}