#include "No.h"
class ListaEnc
{
private:
    No* primeiro;
public:
    ListaEnc();
    ~ListaEnc();

    void insereInicio(int val);
    bool busca(int val);
};