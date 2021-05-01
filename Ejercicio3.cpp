#include <iostream>

class ConjuntoEnteros {
    public:
        ConjuntoEnteros() { ultimoElemento = 0; conjunto = NULL; }
        ConjuntoEnteros(int n) { cantidadElementos = n; ultimoElemento = 0; conjunto = new int(cantidadElementos); }
        ~ConjuntoEnteros() { delete conjunto; }
        void setCantidadElementos(int cantidad) { cantidadElementos = cantidad; }
        void setConjunto(int n) { cantidadElementos = n; conjunto = new int(cantidadElementos); }
        int getCantidadElementos() const { return cantidadElementos; }
        int getUltimoElemento() const { return ultimoElemento; }
        int* getConjunto() const { return conjunto; }
        int* agregar(int elemento) { conjunto[ultimoElemento] = elemento; ultimoElemento++; }
        bool operator ==(ConjuntoEnteros conjunto) {
            if (this->cantidadElementos != conjunto.getCantidadElementos() || this->ultimoElemento != conjunto.getUltimoElemento()) {
                return false;
            }
            for(int i=0; i<ultimoElemento; ++i){
                if(this->conjunto[i] != conjunto.getConjunto()[i]){
                    return false;
                }
            }
            return true;
        }

    private:
        int cantidadElementos, ultimoElemento;
        int* conjunto;
};

int main() 
{
    ConjuntoEnteros conj1(5);
    conj1.agregar(1);
    conj1.agregar(2);
    conj1.agregar(5);
    conj1.agregar(4);
    conj1.agregar(5);
    
    ConjuntoEnteros conj2(5);
    conj2.agregar(1);
    conj2.agregar(2);
    conj2.agregar(5);
    conj2.agregar(4);
    conj2.agregar(5);

    std::cout << (conj1 == conj2);

}