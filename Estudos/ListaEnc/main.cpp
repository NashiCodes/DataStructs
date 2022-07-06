#include <iostream>
#include <cstdlib> //rand()
#include <ctime>   //time()
#include "ListaEnc.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); // retorna um numero inteiro aleatório entre a e b
}

int main()
{
    srand(time(NULL));
    // ATENCAO: os valores inseridos na lista sao gerados
    // aleatoriamente e mudam em cada execucao do programa!!!

    ListaEnc l; // Lista é iniciada

    int n = numAleatorio(0, 50);           // Numero de Nós gerado Randomicamente
    cout << "numero de nós:" << n << endl; // Mostra a quantidade de Nós
    int val;                               // Variavel valor Criada

    for (int i = 0; i < n; i++) // Percorre a lista
    {
        val = numAleatorio(0, 2022); // Gera um numero aleatorio entre 0 e 2022
        l.insereInicio(val);         // Insere o valor na Lista
    }

    return 0;
}