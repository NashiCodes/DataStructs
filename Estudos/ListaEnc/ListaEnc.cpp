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

bool ListaEnc::busca(int val)
{
    No *p; // Cria um ponteiro Aux

    for (p = primeiro; p != NULL; p = p->getprox()) // Percorre a Lista
    {
        if (p->getinfo() == val) // Verifica se há o valor
        {
            return true; // Verdadeiro se houver
        }
    }
    return false; // Falso caso contrário
}