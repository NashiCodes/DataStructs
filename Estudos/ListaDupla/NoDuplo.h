class NoDuplo
{
private:
    int info;      // Informação do Nó
    NoDuplo *prox; // Pronteiro para o proximo
    NoDuplo *ant;  // Ponteiro para o anterior
public:
    NoDuplo();
    ~NoDuplo();

    void setinfo(int val) { info = val; };        // Insere um valor no Nó
    void setprox(NoDuplo *Prox) { prox = Prox; }; // Seta o proximo Nó
    void setant(NoDuplo *Ant) { ant = Ant; };     // Seta o Nó anterior
    int getinfo() { return info; };               // Retorna a Informação
    NoDuplo *getprox() { return prox; };          // Retorna o proximo nó
    NoDuplo *getant() { return ant; };            // Retorna o Nó anterior
};