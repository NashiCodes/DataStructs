#include <iostream>
#include "aluno.h"

using namespace std;

aluno::aluno (string n, string mat)
{
    nome = n;
    matricula = mat;
    idade = 18;

    for(int i = 0; i < 7; i++)
    notas[i] = 0;
}
    aluno::~aluno()
{
    cout<< "destruindo aluno"<< endl;
}

void aluno::lenotas()
{
    int i;
    for(i = 0; i < 7; i++)
    {
        cout<<"digite as notas"<< i+1 <<";";
        cin>>notas[i];
    }
}