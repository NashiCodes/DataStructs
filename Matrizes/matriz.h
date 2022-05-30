#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
using namespace std;

class Matriz
{
private:
        int Linhas;
        int Colunas;
        float **matriz;
        bool verifica(int nl, int nc);

public:
        Matriz(int nl, int nc);
        ~Matriz();
        void set();
        double get();
};
#endif