#include <iostream>

//Parte a y b
class Racional
{
public:
    Racional()
    {
        numerador = 0;
        denominador = 1;
    }
    Racional(int num, int den)
    {
        numerador = num;
        denominador = den;
    }
    Racional(int num)
    {
        numerador = num;
        denominador = 1;
    }
    ~Racional() {}
    void setNumerador(int num) { numerador = num; }
    void setDenominador(int den) { denominador = den; }
    int getNumerador() { return numerador; }
    int getDenominador() { return denominador; }
    Racional operator+(Racional r) { return Racional(numerador * r.denominador + denominador * r.numerador, denominador * r.denominador); }
    Racional operator-(Racional r) { return Racional(numerador * r.denominador - denominador * r.numerador, denominador * r.denominador); }
    Racional operator*(Racional r) { return Racional(numerador * r.numerador, denominador * r.denominador); }
    Racional operator/(Racional r) { return Racional(numerador * r.denominador, denominador * r.numerador); }
    bool operator==(Racional r) { return (numerador * r.denominador) == (denominador * r.numerador); }
    bool operator!=(Racional r) { return (numerador * r.denominador) != (denominador * r.numerador); }

private:
    int numerador, denominador;
};

std::ostream &operator<<(std::ostream &salida, Racional r)
{
    salida << r.getNumerador() << "/" << r.getDenominador() << std::endl;
    return salida;
}

//Parte c
Racional operator+(int e, Racional r) { return Racional(e * r.getDenominador() + r.getNumerador(), r.getDenominador()); }
Racional operator-(int e, Racional r) { return Racional(e * r.getDenominador() - r.getNumerador(), r.getDenominador()); }
Racional operator*(int e, Racional r) { return Racional(r.getNumerador() * e, r.getDenominador()); }
Racional operator/(int e, Racional r) { return Racional(r.getNumerador(), r.getDenominador() * e); }
bool operator==(int e, Racional r) { return r.getNumerador() == r.getDenominador() * e; }
bool operator!=(int e, Racional r) { return r.getNumerador() != r.getDenominador() * e; }

int main()
{
    //Parte b
    Racional r1(2, 3), r2;
    Racional r3(4), r4 = r1;
    if (r1 == r2)
        r1 = r1 + r2;
    else
        r1 = r1 - r2;
    std::cout << r1; // 2/3

    if (r3 != r4)
        r3 = r3 * r4;
    else
        r3 = r3 / r4;
    std::cout << r3; // 8/3

    if (r1 == 2)
        r1 = r1 + 1;
    else
        r1 = r1 - 1;
    std::cout << r1; // -1/3

    if (r3 != 3)
        r3 = r3 * 2;
    else
        r3 = r3 / 2;
    std::cout << r3; // 16/3

    //Parte c
    r3 = 3 * r2;
    std::cout << r3; // 0

    if (2 == (2 + r2))
        r3 = 2 + r2;
    std::cout << r3; // 2
}