#include <iostream>
#include <cstdlib> //rand()
#include <ctime>   //time()
#include "MatrizEsp.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); // retorna um numero inteiro aleatório entre a e b
}

int main()
{
    srand(time(NULL));
    //-----------------------------------------//
    int n = numAleatorio(2, 10);
    MatrizEsp mat(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat.set(i, j, numAleatorio(0, 10));
        }
        
    }

    mat.imprime();
}