#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
using namespace std;

class Matriz
{
private:
    {
        int Lin;
        int Col;
        bool verifica();
    }

public:
    {
        Matriz(int Lin; int Col);
        ~Matriz();
        void set();
        double get();
    }
}
#endif