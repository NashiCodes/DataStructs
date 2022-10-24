#include <iostream>

using namespace std;

class MatrizEsp
{
private:
    int nn;
    float *vet;

    int detInd(int i, int j);

public:
    MatrizEsp(int n);
    ~MatrizEsp();
    void set(int i, int j, int val);
    int get(int i, int j);
    void imprime();
};