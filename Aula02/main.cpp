#include <iostream>
#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()

using namespace std;

int numAleatorio(int a, int b);
void Atv01();
void Atv02();
void Atv03();
int fatorial(int n);
void imprimeIntervalo(int a, int b, int inc);
void imprimeDecrescente(int n);

int main()
{
    Atv01();
    Atv02();
    Atv03();
}

void Atv01()
{
    int n;
    int fat;

    srand(time(NULL));

    n = numAleatorio(0, 10);

    fat = fatorial(n);

    cout << "Fatorial de : " << n << " eh: " << fat << endl
         << endl;
}

void Atv02()
{
    int a;
    int b;
    int inc;

    srand(time(NULL));

    a = numAleatorio(0, 499);
    b = numAleatorio(500, 1000);
    inc = numAleatorio(1, 10);

    cout << "intervalo fechado entre: " << a << " e " << b << " com incremento de " << inc << endl
         << endl;

    imprimeIntervalo(a, b, inc);

    cout << endl
         << endl;
}

void Atv03()
{
    int n;

    srand(time(NULL));

    n = numAleatorio(1, 100);

    cout << "Numero que sera decrescido: " << n << endl;

    imprimeDecrescente(n);
}

void imprimeDecrescente(int n)
{
    if (n >= 0)
    {
        cout << n << " ";
        imprimeDecrescente(n - 1);
    }
}

void imprimeIntervalo(int a, int b, int inc)
{
    if (a < b)
    {
        cout << a << " ";
        imprimeIntervalo(a + inc, b, inc);
    }
}

int fatorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fatorial(n - 1);
}

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); /// retorna um numero inteiro aleatório entre a e b
}