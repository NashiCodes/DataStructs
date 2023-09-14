class No
{
private:
    int info; // Informação do nó
    No *prox; // Ponteiro que aponta para o Proximo Nó

public:
    No(){};  // Construtor
    ~No(){}; // Destrutor

    int getinfo() { return info; };        // Pegar a informação do nó
    No *getprox() { return prox; };        // Pegar o proximo Ponteiro
    void setinfo(int val) { info = val; }; // Colocar a informação no nó
    void setprox(No *p) { prox = p; };     // Setar o proximo Nó
};