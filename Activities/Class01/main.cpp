#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()

using namespace std;

void Atv01();
void Atv02();
void Atv03();
void Atv04();
void Atv05();
void troca(int *a, int *b);
void divisao(int num, int Div, int *q, int *r);
bool func(int tam, int vet[], int *par, int *impar, int *negativos);
int numAleatorio(int a, int b);

int main()
{

    Atv01();
    Atv02();
    Atv03();
    Atv04();
    Atv05();

    return 0;
}

void Atv01()
{
    int pt;
    int *p_pt;

    cout << &pt << endl;

    int x;
    x = numAleatorio(0, 100);
    p_pt = &x;

    cout << *p_pt << endl;
    cout << p_pt << endl;

    *p_pt = *p_pt * 10;

    cout << *p_pt << endl;

    p_pt += 10;

    cout << p_pt << endl
         << endl;
}

void Atv02()
{
    int x = 20;
    int y = 30;

    int *pt_x = &x;
    int *pt_y = &y;

    cout << "Antes da Troca:" << endl
         << "X = " << x << endl
         << "Y = " << y << endl;

    troca(pt_x, pt_y);

    cout << "Depois da Troca:" << endl
         << "X = " << x << endl
         << "Y = " << y << endl
         << endl;
}

void Atv03()
{
    int x = 65;
    int y = 30;
    int *pt_q = new int;
    int *pt_r = new int;

    cout << "valor de A: " << x << endl
         << "valor de B: " << y << endl
         << endl;

    divisao(x, y, pt_q, pt_r);

    cout << "valor do Quociente: " << *pt_q << endl
         << "valor de Resto: " << *pt_r << endl
         << endl;

    delete pt_q;
    delete pt_r;
}

void Atv04()
{
    int tam = 20;
    int *vet = new int[tam];
    int par = 0;
    int impar = 0;
    int negativos = 0;
    int *pt_par = &par;
    int *pt_impar = &impar;
    int *pt_negativos = &negativos;

    srand(time(NULL));

    for (int i = 0; i < tam; i++)
    {
        vet[i] = numAleatorio(-1000, 1000);
    }

    for (int i = 0; i < tam; i++)
        cout << vet[i] << " ";

    cout << endl;
    cout << endl;

    if (func(tam, vet, pt_par, pt_impar, pt_negativos))
    {
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;

    cout << "Quantidade de pares: " << *pt_par << endl;
    cout << "Quantidade de impares: " << *pt_impar << endl;
    cout << "Quantidade de negativos: " << *pt_negativos << endl;

    delete vet;
}

void Atv05()
{

}

void troca(int *a, int *b)
{
    int aux;

    aux = *b;
    *b = *a;
    *a = aux;
}

void divisao(int num, int div, int *q, int *r)
{
    *q = num / div;
    *r = num % div;
}

bool func(int tam, int vet[], int *par, int *impar, int *negativos)
{
    for (int i = 0; i < tam; i++)
    {
        if (vet[i] < 0)
        {
            cout << vet[i] << " ";
            *negativos += 1;
        }
        if ((vet[i] % 2) == 0)
            *par += 1;
        else
            *impar += 1;
    }
    cout << endl;
    cout << endl;

    if (*negativos > 0)
        return true;
    else
        return false;
}

int numAleatorio(int a, int b)
{
    return a + rand() % (b - a + 1); /// retorna um numero inteiro aleatório entre a e b
}