#include <iostream>
using namespace std;

class Matriz
{
private:
        int Linhas;
        int Colunas;
        float **matriz;
        bool verifica(int i, int j);

public:
        Matriz(int nl, int nc);
        ~Matriz();
        void set(int i, int j, float val);
        double get(int i, int j);
};