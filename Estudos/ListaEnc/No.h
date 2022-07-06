class No
{
private:
    int info; // Informação do nó
    No *prox; // Ponteiro que aponta para o Proximo Nó

public:
    No();                  // Construtor
    ~No();                 // Destrutor
    int getinfo();         // Pegar a informação do nó
    No *getprox();         // Pegar o proximo Ponteiro
    void setinfo(int val); // Colocar a informação no nó
    void setprox(No *p);   // Setar o proximo Nó
};