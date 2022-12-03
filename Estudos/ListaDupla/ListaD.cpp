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

int ListaD::get(int k)
{
    NoDuplo *p = primeiro; // cria um No Aux

    for (int i = 0; i < k && p != NULL; i++) // Percorrendo a lista
    {                                        // até o indice k
        p = p->getprox();                    //
    }                                        //

    if (p == NULL)                                 // Verifica se o indice K é valido
    {                                              //
        cout << "ERRO: Indice invalido!!" << endl; //
        exit(1);                                   // Acaba o programa se o indice for invalido
    }                                              //
    else
        return p->getinfo(); // Retorna o Valor dentro do indice K
}

void ListaD::set(int k, int val)
{
    NoDuplo *p = primeiro; // No Aux

    for (int i = 0; i < k && p != NULL; i++) // Percorre a lista
    {                                        // até o indice K
        p = p->getprox();                    //
    }                                        //

    if (p == NULL)                                 // Verifica se o indice K é valido
    {                                              //
        cout << "ERRO: Indice invalido!!" << endl; //
        exit(2);                                   // Acaba o programa se o indice for invalido
    }                                              //
    else
        p->setinfo(val);
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

void ListaD::insereK(int k, int val)
{
    NoDuplo *p;
    NoDuplo *nn = new NoDuplo();
    int i = 0;
    nn->setinfo(val);

    if (n == 0)
    {
        cout << "ERRO: Lista Vazia!, inserindo no inicio..." << endl;
        insereInicio(val);
        return;
    }

    for (p = primeiro; p != NULL && i <= k; p = p->getprox())
    {
        if (i == k)
        {
            nn->setprox(p);
            nn->setant(p->getant());
            p->setant(nn);
            nn->getant()->setprox(nn);
        }

        i++;
    }
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

void ListaD::removeK(int k)
{
    NoDuplo *p;
    int i = 0;
    if (k > n)
    {
        cout << "ERRO: Indice Inválido..." << endl;
        return;
    }
    for (p = primeiro; p != NULL && i <= k; p = p->getprox())
    {
        if (i == k)
        {
            p->getant()->setprox(p->getprox());
            p->getprox()->setant(p->getant());

            delete p;
        }

        i++;
    }
    n--;
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
        cout << endl;
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
        cout << endl;
        cout << "A lista Reversa contém os valores: " << endl;
        for (p = ultimo; p != NULL; p = p->getant())
        {
            cout << p->getinfo() << " ";
        }
    }
    cout << endl;
}

void ListaD::limpar()
{
    if (primeiro == NULL)
        cout << "ERRO: Lista Vazia!!" << endl;
    else
    {
        cout << "Limpando Lista...";

        NoDuplo *p = primeiro;
        while (p != NULL)
        {
            NoDuplo *prox = p->getprox();
            delete p;

            p = prox;
        }
        n = 0;
        primeiro = NULL;
        ultimo = NULL;
    }
}

ListaD *ListaD::concatena(ListaD *l2)
{
    ListaD *lnova = new ListaD();
    NoDuplo *p;
    int numNos = l2->n;

    for (p = primeiro; p != NULL; p = p->getprox())
    {
        lnova->insereFinal(p->getinfo());
    }
    for (int i = 0; i < numNos; i++)
    {
        lnova->insereFinal(l2->get(i));
    }
    return lnova;
}

ListaD *ListaD::partirInd(int x)
{
    NoDuplo *p;
    ListaD *ListaDividida = new ListaD();
    int i = 0;

    if (n == 0)
    {
        cout << "ERRO: Lista Vazia!!!" << endl;
        return this;
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

ListaD *ListaD::partirInf(int x)
{
    NoDuplo *p;
    ListaD *ListaDividida = new ListaD();
    int i = 0;

    if (n == 0)
    {
        cout << "ERRO: Lista Vazia!!!" << endl;
        return this;
    }

    for (p = primeiro; p != NULL; p = p->getprox())
    {
        if (i == p->getinfo())
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