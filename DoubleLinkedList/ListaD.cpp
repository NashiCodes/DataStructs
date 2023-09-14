/**
 * @file ListaD.h
 * @brief Definição da classe ListaD e seus métodos.
 */

#include <iostream>
#include <cstdlib>
#include "ListaD.h"

using namespace std;

/**
 * @brief Construtor da classe ListaD.
 *
 * Inicializa uma nova lista duplamente encadeada.
 */
ListaD::ListaD() : primeiro(nullptr), ultimo(nullptr), n(0) {}

/**
 * @brief Destrutor da classe ListaD.
 *
 * Libera a memória alocada para todos os nós da lista.
 */
ListaD::~ListaD()
{
    cout << endl;
    cout << "Destruindo Lista..." << endl;
    NoDuplo *p = primeiro;

    while (p != nullptr)
    {
        NoDuplo *t = p->getprox();
        delete p;
        p = t;
    }
}

/**
 * @brief Obtém o valor do elemento na posição k da lista.
 *
 * @param k A posição do elemento na lista.
 * @return O valor do elemento na posição k.
 */
int ListaD::get(int k)
{
    NoDuplo *p = primeiro;

    for (int i = 0; i < k && p != nullptr; i++)
    {
        p = p->getprox();
    }

    if (p == nullptr)
    {
        cout << "ERRO: Índice inválido!!" << endl;
        exit(1);
    }
    else
    {
        return p->getinfo();
    }
}

/**
 * @brief Define o valor do elemento na posição k da lista.
 *
 * @param k A posição do elemento na lista.
 * @param val O novo valor a ser definido.
 */
void ListaD::set(int k, int val)
{
    NoDuplo *p = primeiro;

    for (int i = 0; i < k && p != nullptr; i++)
    {
        p = p->getprox();
    }

    if (p == nullptr)
    {
        cout << "ERRO: Índice inválido!!" << endl;
        exit(2);
    }
    else
    {
        p->setinfo(val);
    }
}

/**
 * @brief Insere um novo elemento no início da lista.
 *
 * @param val O valor a ser inserido.
 */
void ListaD::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setinfo(val);
    p->setprox(primeiro);
    p->setant(nullptr);

    if (n == 0)
        ultimo = p;
    else
        primeiro->setant(p);

    primeiro = p;
    n++;
}

/**
 * @brief Insere um novo elemento no final da lista.
 *
 * @param val O valor a ser inserido.
 */
void ListaD::insereFinal(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setinfo(val);
    p->setprox(nullptr);
    p->setant(nullptr);

    if (n == 0)
        primeiro = p;
    else
    {
        ultimo->setprox(p);
        p->setant(ultimo);
    }

    ultimo = p;
    n++;
}

/**
 * @brief Insere um novo elemento na posição k da lista.
 *
 * @param k A posição onde o elemento será inserido.
 * @param val O valor a ser inserido.
 */
void ListaD::insereK(int k, int val)
{
    NoDuplo *p;
    NoDuplo *nn = new NoDuplo();
    int i = 0;
    nn->setinfo(val);

    if (n == 0)
    {
        cout << "ERRO: Lista Vazia!, inserindo no início..." << endl;
        insereInicio(val);
        return;
    }

    for (p = primeiro; p != nullptr && i <= k; p = p->getprox())
    {
        if (i == k)
        {
            nn->setprox(p);
            nn->setant(p->getant());
            p->setant(nn);
            nn->getant()->setprox(nn);

            n++;
        }

        i++;
    }
}

/**
 * @brief Remove o primeiro elemento da lista.
 */
void ListaD::removeInicio()
{
    NoDuplo *p;

    if (primeiro != nullptr)
    {
        p = primeiro;
        primeiro = p->getprox();
        delete p;
        n--;

        if (n == 0)
            ultimo = nullptr;
        else
            primeiro->setant(nullptr);
    }
    else
    {
        cout << "ERRO: Lista Vazia..." << endl;
    }
}

/**
 * @brief Remove o último elemento da lista.
 */
void ListaD::removeFinal()
{
    NoDuplo *p;

    if (primeiro != nullptr)
    {
        p = ultimo;
        ultimo = p->getant();
        delete p;
        n--;

        if (n == 0)
            primeiro = nullptr;
        else
            ultimo->setprox(nullptr);
    }
    else
    {
        cout << "ERRO: Lista Vazia..." << endl;
    }
}

/**
 * @brief Remove o elemento na posição k da lista.
 *
 * @param k A posição do elemento a ser removido.
 */
void ListaD::removeK(int k)
{
    NoDuplo *p;
    int i = 0;
    if (k > n)
    {
        cout << "ERRO: Índice Inválido..." << endl;
        return;
    }
    for (p = primeiro; p != nullptr && i <= k; p = p->getprox())
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

/**
 * @brief Verifica se um valor está presente na lista.
 *
 * @param val O valor a ser buscado.
 * @return true se o valor estiver na lista, false caso contrário.
 */
bool ListaD::busca(int val)
{
    NoDuplo *p;

    for (p = primeiro; p != nullptr; p = p->getprox())
    {
        if (p->getinfo() == val)
            return true;
    }

    return false;
}

/**
 * @brief Imprime os valores da lista.
 */
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
        for (p = primeiro; p != nullptr; p = p->getprox())
        {
            cout << p->getinfo() << " ";
        }
    }
    cout << endl;
}

/**
 * @brief Imprime os valores da lista em ordem reversa.
 */
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
        for (p = ultimo; p != nullptr; p = p->getant())
        {
            cout << p->getinfo() << " ";
        }
    }
    cout << endl;
}

/**
 * @brief Limpa todos os elementos da lista, liberando a memória.
 */
void ListaD::limpar()
{
    if (primeiro == nullptr)
        cout << "ERRO: Lista Vazia!!" << endl;
    else
    {
        cout << "Limpando Lista...";

        NoDuplo *p = primeiro;
        while (p != nullptr)
        {
            NoDuplo *prox = p->getprox();
            delete p;

            p = prox;
        }
        n = 0;
        primeiro = nullptr;
        ultimo = nullptr;
    }
}

/**
 * @brief Concatena a lista atual com outra lista e retorna a nova lista resultante.
 *
 * @param l2 A lista a ser concatenada com a lista atual.
 * @return Um ponteiro para a nova lista resultante.
 */
ListaD *ListaD::concatena(ListaD *l2)
{
    ListaD *lnova = new ListaD();
    NoDuplo *p;
    int numNos = l2->n;

    for (p = primeiro; p != nullptr; p = p->getprox())
    {
        lnova->insereFinal(p->getinfo());
    }
    for (int i = 0; i < numNos; i++)
    {
        lnova->insereFinal(l2->get(i));
    }
    return lnova;
}

/**
 * @brief Divide a lista atual em duas a partir da posição x e retorna a segunda parte.
 *
 * @param x A posição a partir da qual a lista será dividida.
 * @return Um ponteiro para a segunda parte da lista original.
 */
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

    for (p = primeiro; p != nullptr; p = p->getprox())
    {
        if (i == x)
        {
            ListaDividida->primeiro = p;
            ListaDividida->ultimo = ultimo;
            ultimo = p->getant();
            ultimo->setprox(nullptr);
            ListaDividida->primeiro->setant(nullptr);
        }
        i++;
    }

    return ListaDividida;
}

/**
 * @brief Divide a lista atual em duas a partir do valor x e retorna a segunda parte.
 *
 * @param x O valor a partir do qual a lista será dividida.
 * @return Um ponteiro para a segunda parte da lista original.
 */
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

    for (p = primeiro; p != nullptr; p = p->getprox())
    {
        if (i == p->getinfo())
        {
            ListaDividida->primeiro = p;
            ListaDividida->ultimo = ultimo;
            ultimo = p->getant();
            ultimo->setprox(nullptr);
            ListaDividida->primeiro->setant(nullptr);
        }
        i++;
    }

    return ListaDividida;
}

/**
 * @brief Remove todas as ocorrências de um valor da lista.
 *
 * @param val O valor a ser removido da lista.
 */
void ListaD::removeOcorrencias(int val)
{
    NoDuplo *p;

    if (n == 0)
    {
        cout << "ERRO: Lista Vazia!!!" << endl;
        return;
    }

    for (p = primeiro; p != nullptr; p = p->getprox())
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
