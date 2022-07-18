#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    // OMITIDO
}

void ListaDupla::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(primeiro);
    p->setAnt(NULL);

    if (n == 0)
    {
        ultimo = p;
    }
    else
    {
        primeiro->setAnt(p);
    }
    primeiro = p;
    n = n + 1;
}

void ListaDupla::imprime()
{
    cout << "[";
    for (NoDuplo *p = primeiro; p != NULL; p = p->getProx())
    {
        cout << p->getInfo();
        if (p->getProx() != NULL)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

//----------------------------------------------------------------------------
//Q2
void ListaDupla::trocaSegundoPenultimo()
{
    NoDuplo *p;
    NoDuplo *aux;

    if (n <= 4)
    {
        cout << endl
             << "ERRO: A lista tem menos de 5 nos!" << endl;
        return;
    }

    for (p = primeiro; p != NULL; p = p->getProx())
    {
        if (p == primeiro->getProx())
        {
            aux = p;
        }

        if (p == ultimo->getAnt())
        {
            p->setProx(aux->getProx());
            p->getProx()->setAnt(p);
            p->getAnt()->setProx(aux);
            aux->setProx(ultimo);
            aux->setAnt(p->getAnt());
            p->setAnt(primeiro);
            primeiro->setProx(p);
            ultimo->setAnt(aux);

            return;
        }
    }
}
//-Q2
//----------------------------------------------------------------------------
