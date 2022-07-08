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

    ListaEnc l;  // Lista 1 é iniciada
    ListaEnc l2; // Lista 2 eh criada

    int n = numAleatorio(5, 50);                      // Numero de Nós gerado Randomicamente
    cout << "numero de nós da Lista 1:" << n << endl; // Mostra a quantidade de Nós
    int val;                                          // Variavel valor Criada
    cout << endl;

    for (int i = 0; i < n; i++) // Percorre a lista
    {
        val = numAleatorio(0, 100); // Gera um numero aleatorio entre 0 e 100
        l.insereInicio(val);        // Insere o valor na Lista
    }

    n = numAleatorio(5, 50);                          // Numero de Nós gerado Randomicamente
    cout << "numero de nós da Lista 2:" << n << endl; // Mostra a quantidade de Nós
    cout << endl;

    for (int i = 0; i < n; i++) // Percorre a lista
    {
        val = numAleatorio(0, 100); // Gera um numero aleatorio entre 0 e 100
        l2.insereInicio(val);       // Insere o valor na Lista
    }

    l.imprime();
    l.insereInicio(2022);
    l.imprime();
    l.inserefinal(2022);
    l.imprime();
    l.insereK(5, 2022);
    l.imprime();
    l.removeinicio();
    l.imprime();
    l.removefinal();
    l.imprime();
    l.removeK(4);
    l.imprime();

    l2.insereInicio(2022);
    l2.imprime();
    l2.inserefinal(2022);
    l2.imprime();
    l2.insereK(5, 2022);
    l2.imprime();
    l2.removeinicio();
    l2.imprime();
    l2.removefinal();
    l2.imprime();
    l2.removeK(4);
    l2.imprime();

    l.concatena(&l2);
    l.imprime();

    l.limpar();
    l.imprime();
    l2.limpar();
    l2.imprime();

    return 0;
}