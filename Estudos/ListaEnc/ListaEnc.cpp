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
    No *p = new No(); // Cria um novo Nó para a lista

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
    else                    // Caso contrario
        ultimo = p;         // Ultimo recebe p

    n++;              // Aumenta o numero de nós
    if (n == 1)       // Verifica se é o primeiro nó
        primeiro = p; // Primeiro recebe p
}

void ListaEnc::removeinicio()
{
    No *p;

    if (primeiro != NULL)
    {
        p = primeiro; // p aponta para o nó a ser excluido

        primeiro = p->getprox(); // Primeiro passa a aponta para o atual Segundo

        delete p;
    }
}

void ListaEnc::imprime()
{
    No *p; // Cria um Nó Aux

    cout << "A lista contem os valores:" << endl;
    cout << endl;

    for (p = primeiro; p != NULL; p = p->getprox()) // Percorre a Lista
    {
        cout << p->getinfo() << " "; // Imprime os valores da lista
    }

    cout << endl;
}