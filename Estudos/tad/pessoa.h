#include <iostream>
#include <string.h>

using namespace std;

class Pessoa
{
public:
    Pessoa(string Nome, int idade);
    ~pessoa();
    
private:
    string nome;
    int idade;
};