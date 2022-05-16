#include <iostream>
#include "aluno.h"

using namespace std;

Aluno::Aluno (string n, string mat)
{
    nome = n;
    matricula = mat;
    idade = 18;

    for(int i = 0; i < 7; i++)
    notas[i] = 0;
}
Aluno::~Aluno()
{
    cout<< "destruindo aluno"<< endl;
}

void Aluno::lenotas()
{
    int i;
    for(i = 0; i < 7; i++)
    {
        cout<<"digite as notas "<< i+1 <<":";
        cin>>notas[i];
    }
}

double Aluno::calculaMedia()
{
    
}