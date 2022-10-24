#include <iostream>
#include "MatrizEsp.h"

using namespace std;

MatrizEsp::MatrizEsp(int n)
{
    nn = n;
    vet = new float[nn * nn];
}

MatrizEsp::~MatrizEsp()
{
    delete[] vet;
}

int MatrizEsp::detInd(int i, int j)
{
    if (i >= 0 && i < nn && j >= 0 && j < nn)
        return i * nn + j;
    else
        return -1;
}

void MatrizEsp::set(int i, int j, int val)
{
    int k = detInd(i, j);
    if (k != -1)
        vet[k] = val;

    else
    {
        cout << "ERRO: SET" << endl;
        exit(1);
    }
}
int MatrizEsp::get(int i, int j)
{
    int k = detInd(i, j);
    if (k != -1)
        return vet[k];
    else
    {
        cout << "ERRO: GET" << endl;
        exit(1);
    }
}

void MatrizEsp::imprime()
{
    for (int i = 0; i < nn; i++)
    {
        for (int j = 0; j < nn; j++)
        {
            cout << vet[i * nn + j] << " ";
        }
        cout << endl;
    }
}