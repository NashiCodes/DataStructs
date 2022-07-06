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

    int n = numAleatorio(5, 50);           // Numero de Nós gerado Randomicamente
    cout << "numero de nós:" << n << endl; // Mostra a quantidade de Nós
    int val;                               // Variavel valor Criada
    cout << endl;

    for (int i = 0; i < n; i++) // Percorre a lista
    {
        val = numAleatorio(0, 100); // Gera um numero aleatorio entre 0 e 2022
        l.insereInicio(val);        // Insere o valor na Lista
    }

    l.imprime();

    return 0;
}