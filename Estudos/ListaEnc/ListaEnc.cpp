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
    No *p;

    for (int i = 0; i < k && p != NULL; i++)
    {
        p = p->getprox();
    }

    if (p == NULL)
    {
        cout << "ERRO: Indice invalido!!" << endl;
        exit(1);
    }
    else
        return p->getinfo();
}

void ListaEnc::insereInicio(int val)
{
    No *p = new No(); // Cria um novo Nó para a lista

    /* o comando No *p = new No() aloca um novo
    nó de forma dinâmica, isto é, este novo nó só ́é criado
    quando a operação ̃insereInicio(val) e executada.*/

    /*Portanto, novos nós são adicionados à lista em tempo de execução
    de acordo com a demanda da aplicação.*/

    /*Logo, em um instante de tempo, a memoria ocupada pela
    lista e proporcional ao número de nós armazenados na mesma.*/

    p->setinfo(val);      // Inserindo a informação no Nó
    p->setprox(primeiro); // Preenche proximo

    primeiro = p; // Nó apontado por p passa a ser o primeiro da lista
}

void ListaEnc::inserefinal(int val)
{
    for (No *p = primeiro; p < NULL; p = p->getprox())
    {
        if (p->getprox() == NULL)
        {
            No *final;
        }
    }
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