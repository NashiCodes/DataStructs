#include <iostream>
#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()

using namespace std;

void Atv01();
int fatorial(int n);
int numAleatorio(int a, int b);

int main()
{
    Atv01();
}

void Atv01()
{
    int n;
    int fat;

    srand(time(NULL));

    n = numAleatorio(0, 10);

    fat = fatorial(n);

    cout << "Fatorial de : " << n << " eh: " << fat<< endl;
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