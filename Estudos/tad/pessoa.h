#include <iostream>
#include <string.h>

using namespace std;

class Pessoa
{
public:
    Pessoa(string n, int i);
    ~Pessoa();
    void imprimeP();

private:
    string Nome;
    int Idade;
};