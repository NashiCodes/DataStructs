#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include <iostream>

using namespace std;

class Aluno
{
private:
    int idade;
    string nome, matricula;
    double notas[7];
public:

    Aluno(string n, string mat);
    ~Aluno();

    void lenotas();
    double calculaMedia();
};

#endif
