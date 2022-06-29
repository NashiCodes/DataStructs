#include <iostream>
#include <string.h>
#include "pessoa.h"

using namespace std;

Pessoa::Pessoa(string n, int i)
{
    Nome = n;
    Idade = i;
}

Pessoa::~Pessoa()
{
    cout << "desalocando memoria" << endl;
}

void Pessoa::imprimeP()
{
    cout << "Nome da Pessoa é:" << Nome << endl;
    cout << "Sua idade eh:" << Idade << endl;
}