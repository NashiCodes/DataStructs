#include <iostream>
using namespace std;

class MatrizLin
{
private:
    int nl, nc;
    float *vet;

    int detInd(int i, int j);

public:
    MatrizLin(int mm, int nn);
    ~MatrizLin();
    void set(int i, int j, float val);
    float get(int i, int j);
    void imprime(int i, int j);
};