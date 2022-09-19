#include <iostream>

using namespace std;

void Atv01();
void Atv02();
void Atv03();
void troca(int *a, int *b);
void divisao(int num, int Div, int *q, int *r);

int main()
{

    Atv01();
    Atv02();
    Atv03();

    return 0;
}

void Atv01()
{
    int pt;
    int *p_pt;

    cout << &pt << endl;

    int x;
    cin >> x;
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
    int q;
    int r;
    int *pt_q = &q;
    int *pt_r = &r;

    cout << "valor de A: " << x << endl
         << "valor de B: " << y << endl
         << endl;

    divisao(x, y, pt_q, pt_r);

    cout << "valor do Quociente: " << q << endl
         << "valor de Resto: " << r << endl
         << endl;
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