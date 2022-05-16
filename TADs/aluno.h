#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include <iostream>

using namespace std;

class aluno
{
private:
    int idade;
    string name, matricula;
    double notas[7];
public:

    aluno(string n, string mat);
    ~aluno();

    void lenotas();
    double calculaMedia();
};

#endif
