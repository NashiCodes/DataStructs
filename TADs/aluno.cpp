#include <iostream>
#include <string.h>
#include "aluno.h"

using namespace std;

Aluno::Aluno(string n, int i, string mat)
{
    nome = n;
    matricula = mat;
    idade = i;

    for (int i = 0; i < 7; i++)
        notas[i] = 0;
}
Aluno::~Aluno()
{
    cout << "destruindo aluno" << endl;
}
void Aluno::alunonotas()
{
    lenotas();
    calculaMedia();
    imprimenotas();
}

void Aluno::lenotas()
{
    int i;
    for (i = 0; i < 7; i++)
    {
        cout << "digite a nota " << i + 1 << ":";
        cin >> notas[i];
    }
}

void Aluno::imprimenotas()
{
    cout << "As notas do Aluno " << nome << " foram: ";
    int i;
    for (i = 0; i < 7; i++)
    {
        cout << notas[i] << ", ";
    }
    cout << endl;
}

void Aluno::calculaMedia()
{
    double Calculo = 0;
    int i = 0;
    for (i = 0; i < 7; i++)
    {
        Calculo = Calculo + notas[i];
    }

    Calculo = Calculo / i;

    cout << "A media do Aluno " << nome << " foi: " << Calculo << endl;
}