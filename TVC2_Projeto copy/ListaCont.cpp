#include <iostream>
#include <cstdlib>
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaCont::~ListaCont()
{
    delete[] vet;
}

void ListaCont::insereFinal(int val)
{
    if (n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit(1);
    }
    vet[n] = val;
    n = n + 1;
}

void ListaCont::imprime()
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << vet[i];
        if (i + 1 < n)
        {
            cout << ", ";
        }
    }
    cout << "]";
}

void ListaCont::limpar()
{
    n = 0;
}

//----------------------------------------------------------------------------
//Q1
bool ListaCont::insereValores(int k, int tam, int v[])
{
    if (tam <= max - n)
    {
        for (int i = n - 1; i >= k; i--)
        {
            vet[i + tam] = vet[i];
        }
        for (int i = k; i < tam; i++)
        {
            vet[i] = v[i];
        }
        n += tam;
        return true;
    }
    return false;
}
//-Q1
//----------------------------------------------------------------------------
