#include <iostream>

using namespace std;

int main()
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

    cout << p_pt << endl;

    return 0;
}
