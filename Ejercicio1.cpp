#include <iostream>
#include <cmath>

class Punto {
    public:
        Punto() {}
        Punto(float coordenadaX, float coordenadaY) { this->coordenadaX = coordenadaX; this->coordenadaY = coordenadaY; }
        ~Punto() {}
        void setCoordenadaX(float coordenadaX) { this->coordenadaX = coordenadaX; }
        void setCoordenadaY(float coordenadaY) { this->coordenadaY = coordenadaY; }
        float getCoordenadaX() const { return coordenadaX; }
        float getCoordenadaY() const { return coordenadaY; }
    private:
        float coordenadaX;
        float coordenadaY;
};

class Segmento {
    public:
        Segmento() {}
        Segmento(Punto a, Punto b) { this->a = a; this-> b = b; }
        ~Segmento() {}
        void setA(Punto a) { this->a = a; }
        void setB(Punto b) { this->b = b; }
        Punto getA() const { return a; }
        Punto getB() const { return b; }
        float calcularLargoSegmento() { return sqrt( pow(this->a.getCoordenadaX() - this->b.getCoordenadaX(), 2) + pow(this->a.getCoordenadaY() - this->b.getCoordenadaY(), 2) ); }
    private:
        Punto a;
        Punto b;
};

int main()
{
    Punto a(2,1);
    Punto b(3,3);
    Segmento segmento(a,b);
    std::cout << "El largo del segmento es: " << segmento.calcularLargoSegmento();
}