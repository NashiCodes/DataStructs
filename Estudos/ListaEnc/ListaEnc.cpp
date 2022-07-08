#include <iostream>
#include <cstdlib>
#include "ListaEnc.h"

using namespace std;

ListaEnc::ListaEnc()
{
    // Lista é iniciada
    cout << "Criando lista..." << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaEnc::~ListaEnc()
{
    cout << endl;
    cout << "Destruindo a Lista..." << endl;
    No *p = primeiro;

    while (p != NULL)
    {
        No *t = p->getprox(); // Salvando o endereço do proximo nó
        delete p;             // Deletando o nó atual

        p = t; // Andando na Lista
    }
}

bool ListaEnc::busca(int val)
{
    No *p; // Cria um Nó Aux

    for (p = primeiro; p != NULL; p = p->getprox()) // Percorre a Lista
    {
        if (p->getinfo() == val) // Verifica se há o valor
        {
            return true; // Verdadeiro se houver
        }
    }
    return false; // Falso caso contrário
}

int ListaEnc::get(int k)
{
    No *p; // cria um No Aux

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

void ListaEnc::set(int k, int val)
{
    No *p; // No Aux

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

void ListaEnc::insereInicio(int val)
{
    No *p = new No();     // Cria um novo Nó para a lista
    p->setinfo(val);      // Inserindo a informação no Nó
    p->setprox(primeiro); // Preenche proximo

    primeiro = p; // Nó apontado por p passa a ser o primeiro da lista

    n++;            // Aumenta o numero de nós
    if (n == 1)     // Verifica se é o primeiro nó
        ultimo = p; // Ultimo recebe p
}

void ListaEnc::inserefinal(int val)
{
    No *p = new No(); // Cria um novo Nó para a lista
    p->setinfo(val);  // Insere a informação
    p->setprox(NULL); // Preenche o proximo como NULO

    if (ultimo != NULL)     // Verifica se o Ultimo não é Nulo
        ultimo->setprox(p); // Se não for o ultimo aponta para p

    ultimo = p; // Ultimo recebe p

    n++;              // Aumenta o numero de nós
    if (n == 1)       // Verifica se é o primeiro nó
        primeiro = p; // Primeiro recebe p
}

void ListaEnc::insereK(int k, int val)
{
    No *p;             // Nó Aux
    No *nn = new No(); // Cria um novo Nó pra lista
    nn->setinfo(val);  // Insere a informação
    int i = 0;         // Variavel Aux

    if (n == 0)
    {
        cout << "ERRO:Lista Vazia!!" << endl;
        insereInicio(val);
    }
    else
    {
        for (p = primeiro; p != NULL && i < k; p = p->getprox())
        {
            if (i == k - 1)
            {
                nn->setprox(p->getprox());
                p->setprox(nn);
            }

            i++;
        }
    }
    n++;
}

void ListaEnc::removeinicio()
{
    No *p;

    if (primeiro != NULL)
    {
        p = primeiro;            // p aponta para o nó a ser excluido
        primeiro = p->getprox(); // Primeiro passa a aponta para o atual Segundo
        delete p;

        n--;
        if (n == 0)
            ultimo = NULL;
    }
    else
        cout << "ERRO: Lista Vazia!!";
}

void ListaEnc::removefinal()
{
    No *p;

    if (ultimo != NULL) // Verifica se o ultimo não é nulo
    {
        if (primeiro == ultimo) // Verifica se o primeiro é igual ao ultimo
        {
            primeiro = NULL; // Primeiro e o p recebe NULLO
            p = NULL;        //
        }
        else // Caso contrário
        {
            p = primeiro;
            while (p->getprox() != ultimo) // Percorre a lista até o penultimo
                p = p->getprox();          //

            p->setprox(NULL); // Penultimo recebe Nulo
        }
        delete ultimo; // Deleta o ultimo
        ultimo = p;    // Penultimo se torna o Ultimo
        n--;
    }
}

void ListaEnc::removeK(int k)
{
    No *p;
    No *aux;
    int i = 0;
    aux = primeiro;

    for (p = primeiro; p != NULL && i <= k; p = p->getprox())
    {
        if (k == 0)
        {
            removeinicio();
            i++;
        }

        if (k == n)
        {
            removefinal();
            i++;
        }

        if (i == (k - 1))
        {
            aux = aux->getprox();
            p->setprox(aux->getprox());

            delete aux;

            n--;
            i++;
        }

        i++;
        aux = aux->getprox();
    }
}

int ListaEnc::numNos()
{
    return n;
}

int ListaEnc::buscaMaior(int val)
{
    No *p;
    int i = 0;

    for (p = primeiro; p != NULL; p = p->getprox())
    {
        if (p->getinfo() > val)
            return i;

        i++;
    }

    return -1;
}

void ListaEnc::limpar()
{
    No *p = primeiro;

    cout << "Limpando a Lista..." << endl;
    while (p != NULL)
    {
        No *t = p->getprox(); // Salvando o endereço do proximo nó
        delete p;             // Deletando o nó atual

        p = t; // Andando na Lista

        n--;
    }
    primeiro = NULL;
    ultimo = NULL;
}

float ListaEnc::calculaMedia()
{
    No *p;
    float soma = 0;
    float media = 0;

    for (p = primeiro; p != NULL; p = p->getprox())
    {
        soma = soma + p->getinfo();
    }

    media = soma / numNos();

    return media;
}

void ListaEnc::concatena(ListaEnc *l2)
{
    ultimo->setprox(l2->primeiro);

    n = n + l2->n;
}

void ListaEnc::imprime()
{
    No *p; // Cria um Nó Aux
    if (n == 0)
    {
        cout << endl;
        cout << "ERRO: Lista Vazia!!";
    }
    else
    {
        cout << endl;
        cout << "A lista contem os valores:" << endl;
        for (p = primeiro; p != NULL; p = p->getprox()) // Percorre a Lista
        {
            cout << p->getinfo() << " "; // Imprime os valores da lista
        }

        cout << endl;
        cout << "Numeros de nos: " << numNos() << endl;
        cout << "Media da Lista eh:" << calculaMedia() << endl;
    }

    cout << endl;
}