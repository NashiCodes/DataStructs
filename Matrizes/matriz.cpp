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

    cout << "destruindo Matriz" << endl;
}

bool Matriz::verifica(int i, int j)
{
    if (i >= 0 && i < Linhas && j >= 0 && j < Colunas)
        return true;
    else
        return false;
}

void Matriz::set(int i, int j, float val)
{
    if (verifica(i, j))
        matriz[i][j] = val;
    else
    {
        cout << "Erro: indice inválido" << endl;
        exit(1);
    }
}

void Matriz::get(int i, int j)
{
    if (verifica(i, j))
        return matriz[i][j];
    else
    {
        cout << "Erro: indice inválido" << endl;
        exit(1);
    }
}