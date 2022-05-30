#ifndef ALUNO_H
#define ALUNO_H
#include <iostream>
#include <string>

using namespace std;

class Aluno
{
private:
    int idade;
    string nome, matricula;
    double notas[7];
    void lenotas();
    void calculaMedia();

public:
    Aluno(string n, int i, string mat);
    ~Aluno();

    void imprimenotas();
    void alunonotas();
};

#endif
