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