#include <iostream>

using namespace std;
class ConjuntoEnteros
{
public:
    ConjuntoEnteros()
    {
        ultimoElemento = 0;
        conjunto = NULL;
    }
    ConjuntoEnteros(int n)
    {
        cantidadElementos = n;
        ultimoElemento = 0;
        conjunto = new int[cantidadElementos];
    }
    ~ConjuntoEnteros() { delete[] conjunto; }
    void setConjunto(int* conjunto) { this->conjunto = conjunto; }
    void setUltimoElemento(int ultimoElemento) { this->ultimoElemento = ultimoElemento; }
    int getCantidadElementos() const { return cantidadElementos; }
    int getUltimoElemento() const { return ultimoElemento; }
    int *getConjunto() const { return conjunto; }
    int &operator[](int index)
    {
        int *nuevoConjunto;
        if (index >= cantidadElementos)
        {
            nuevoConjunto = new int[index + 10];
            for (int i = 0; i < ultimoElemento; i++)
                nuevoConjunto[i] = conjunto[i];
            cantidadElementos = index + 10;
            delete[] conjunto;
            conjunto = nuevoConjunto;
        }
        if (index > ultimoElemento)
            ultimoElemento = index + 1;
        return *(conjunto + index);
    }
    void agregar(int elemento)
    {
        int *nuevoConjunto;
        if (ultimoElemento >= cantidadElementos)
        {
            cout << "\nNo hay suficiente espacio en el array\n";
            return;
        }
        nuevoConjunto = new int[cantidadElementos];
        for (int i = 0; i < ultimoElemento; i++)
        {
            nuevoConjunto[i] = conjunto[i];
            if (nuevoConjunto[i] == elemento) 
            {
                cout << "\nEl elemento " << elemento << " ya esta en el array\n";
                delete[] nuevoConjunto;
                return;
            }
        }
        delete[] conjunto;
        conjunto = nuevoConjunto;
        conjunto[ultimoElemento++] = elemento;
    }
    void remover(int elemento)
    {
        int *nuevoConjunto = new int[cantidadElementos];
        for (int i = 0; i < ultimoElemento; i++)
        {
            nuevoConjunto[i] = conjunto[i];
        }
        for (int i = 0; i < ultimoElemento; ++i)
        {
            if (nuevoConjunto[i] == elemento)
            {
                nuevoConjunto[i] = nuevoConjunto[--ultimoElemento];
            }
        }
        delete[] conjunto;
        conjunto = nuevoConjunto;
    }
    ConjuntoEnteros operator +(ConjuntoEnteros& conjunto) //arreglar
    {
        int cantEls = cantidadElementos + conjunto.getCantidadElementos();
        int ultEl = ultimoElemento;
        int *nuevoConjunto = new int[cantEls];
        for (int i = 0; i < ultimoElemento; ++i)
            nuevoConjunto[i] = conjunto[i];
        for(int i=0; i<conjunto.getUltimoElemento();++i)
        {
            nuevoConjunto[ultEl++] = conjunto.getConjunto()[i];
        }
        ConjuntoEnteros conj(cantEls);
        conj.setConjunto(nuevoConjunto);
        conj.setUltimoElemento(ultEl);
        return conj;
    }
    ConjuntoEnteros operator -(ConjuntoEnteros& conjunto) //arreglar
    {
        int cantEls = cantidadElementos;
        int ultEl = 0;
        int *nuevoConjunto = new int[cantEls];
        for (int i = 0; i < ultimoElemento; ++i)
        {
            for(int j=0; j<conjunto.getUltimoElemento();++j)
            {
                if(this->conjunto[i] != conjunto.getConjunto()[j])
                {
                    nuevoConjunto[ultEl++] = this->conjunto[i];
                }
            }
        }
        ConjuntoEnteros conj(cantEls);
        conj.setConjunto(nuevoConjunto);
        conj.setUltimoElemento(ultEl);
        return conj;
    }
    bool operator==(ConjuntoEnteros &conjunto)
    {
        if (this->cantidadElementos != conjunto.getCantidadElementos() || this->ultimoElemento != conjunto.getUltimoElemento())
        {
            return false;
        }
        for (int i = 0; i < ultimoElemento; ++i)
        {
            if (this->conjunto[i] != conjunto.getConjunto()[i])
            {
                return false;
            }
        }
        return true;
    }

private:
    int cantidadElementos, ultimoElemento;
    int *conjunto;
};

int main()
{
    ConjuntoEnteros conj1(5);
    conj1.agregar(1);
    conj1.agregar(2);
    conj1.agregar(3);
    conj1.agregar(4);
    conj1.agregar(5);
    
    ConjuntoEnteros conj2(5);
    conj2.agregar(6);
    conj2.agregar(7);
    conj2.agregar(3);
    conj2.agregar(8);
    conj2.agregar(9);

    ConjuntoEnteros conj3  = conj1 + conj2;
    // conj3 = (conj1 + conj2);
    for(int i=0; i<conj3.getUltimoElemento();++i)
    {
        cout << conj3.getConjunto()[i] << " - ";
    }
}