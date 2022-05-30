#include <iostream>
#include "matriz.h"

using namespace std;

int main()
{
    int l;
    int c;
    float valor;

    cout << "Digite o numero de linhas e colunas" << endl;
    cin >> l;
    cin >> c;

    Matriz mat(l, c);

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> valor;
            mat.set(i, j, valor);
        }
    }

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mat.get(i, j);
        }
        cout << endl;
    }

    return 0;
}
