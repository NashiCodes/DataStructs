#include <iostream>
#include "matriz.h"

using namespace std;

Matriz::Matriz(int nl, int nc)
{
    Linhas = nl;
    Colunas = nc;
    matriz = new float *[Linhas];

    for (int i = 0; i < Linhas; i++)
    {
        matriz[i] = new float[Colunas];
    }
}

Matriz::~Matriz()
{
    for (int i = 0; i < Linhas; i++)
        delete[] matriz[i];
    delete[] matriz;

    cout<< "destruindo Matriz"<< endl;
}

bool Matriz::verifica(int nl, int nc)
{
    if (nl >= 0 && nl < Linhas && nc >= 0 && nc < Colunas)
        return true;
    else
        return false;
}