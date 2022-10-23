#include <iostream>
#include "MatrizLin.h"
using namespace std;

MatrizLin::MatrizLin(int mm, int nn)
{
    nl = mm;
    nc = nn;
    vet = new float[nl * nc];
}

MatrizLin::~MatrizLin()
{
    delete[] vet;
}

int MatrizLin::detInd(int i, int j)
{
    if (i >= 0 && i < nl && j >= 0 && j < nc)
        return i * nc + j;
    else
        return -1;
}

void MatrizLin::set(int i, int j, float val)
{
    int k = detInd(i, j);
    if (k != -1)
        vet[k] = val;

    else
    {
        cout << "Indices Invalidos!!" << endl;
        exit(1);
    }
}

float MatrizLin::get(int i, int j)
{
    int k = detInd(i, j);
    if (k != -1)
        return vet[k];
    else
    {
        cout << "ERRO: get" << endl;
        exit(1);
    }
}

void MatrizLin::imprime(int i, int j)
{
    int k = detInd(i, j);
    if (k != -1)
    {
        for (int i = 0; i < k; i++)
        {
            
        }
    }
}