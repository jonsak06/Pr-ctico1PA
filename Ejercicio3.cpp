#include <iostream>

class ConjuntoEnteros {
    public:
        ConjuntoEnteros() { ultimoElemento = 0; conjunto = NULL; }
        ConjuntoEnteros(int n) {
            cantidadElementos = n;
            ultimoElemento = 0;
            conjunto = new int[cantidadElementos];
        }
        ConjuntoEnteros(ConjuntoEnteros* conjunto) { 
            this->cantidadElementos = conjunto->getCantidadElementos(); 
            this->ultimoElemento = conjunto->getUltimoElemento();
            for(int i=0; i<ultimoElemento; ++i) {
                this->conjunto[i] = conjunto->getConjunto()[i];
            }
        }
        ~ConjuntoEnteros() { delete conjunto; }
        void setCantidadElementos(int cantidad) { cantidadElementos = cantidad; }
        void setConjunto(int n) { cantidadElementos = n; conjunto = new int(cantidadElementos); }
        int getCantidadElementos() const { return cantidadElementos; }
        int getUltimoElemento() const { return ultimoElemento; }
        int* getConjunto() const { return conjunto; }

        // int& operator[](int index) {} //falta esto

        void operator =(ConjuntoEnteros& conjunto) {
            this->cantidadElementos = conjunto.getCantidadElementos();
            this->ultimoElemento = conjunto.getUltimoElemento();
            this->conjunto = conjunto.getConjunto();
        }

        void agregar(int elemento) {
            if(ultimoElemento <= cantidadElementos) {
                conjunto[ultimoElemento] = elemento; ultimoElemento++;
            }
        } 
        void remover(int elemento) {//probar si queda bien luego de sobrecargar el operador []
            int j;
            for(int i=0; i<ultimoElemento; ++i) {
                if(conjunto[i] == elemento) {
                    this->conjunto[j++] = this->conjunto[i];
                }
            }
            ultimoElemento = j;
        }

        bool operator ==(ConjuntoEnteros& conjunto) {
            if (this->cantidadElementos != conjunto.getCantidadElementos() || this->ultimoElemento != conjunto.getUltimoElemento()) {
                return false;
            }
            for(int i=0; i<ultimoElemento; ++i) {
                if(this->conjunto[i] != conjunto.getConjunto()[i]) {
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
    conj1.agregar(3);
    conj1.agregar(4);
    conj1.agregar(5);
    // ConjuntoEnteros conj3 = conj1; //funca
    // std::cout << (conj1 == conj3) << std::endl; //funca
    std::cout << conj1.getConjunto()[0] << " - " << conj1.getConjunto()[1] << " - " << conj1.getConjunto()[2] << " - " << conj1.getConjunto()[3] << " - " << conj1.getConjunto()[4] << std::endl;
    conj1.remover(4);//no funca
    conj1.agregar(8);
    std::cout << conj1.getConjunto()[0] << " - " << conj1.getConjunto()[1] << " - " << conj1.getConjunto()[2] << " - " << conj1.getConjunto()[3] << " - " << conj1.getConjunto()[4] << std::endl;
    
    // ConjuntoEnteros conj2(5);
    // conj2.agregar(1);
    // conj2.agregar(2);
    // conj2.agregar(5);
    // conj2.agregar(4);
    // conj2.agregar(5);
}