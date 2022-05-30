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
public:

    Aluno(string n, int i, string mat);
    ~Aluno();

    void lenotas();
    double calculaMedia();
};

#endif
