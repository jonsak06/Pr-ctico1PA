# Practico1PA
Ejercicios del práctico 1 de Programación Avanzada - Tecnólogo en Informática

Ejercicio 1 (básico, imprescindible)

Implementar en C++ una clase que represente un punto en un plano utilizando coordenadas cartesianas. Proveer operaciones para obtener y modificar la posición del punto en el 
plano. A su vez, implementar en C++ una clase que represente un segmento en un plano. Proveer una operación que calcule el largo del segmento.


Ejercicio 2 (básico, imprescindible)

a) Implementar en C++ una clase llamada Racional que permita definir y manipular números racionales, representados como un par de enteros. 

  La clase deberá proveer las siguientes operaciones.
  
    suma : Racional x Racional -> Racional
    
    diferencia : Racional x Racional -> Racional
    
    producto : Racional x Racional -> Racional
    
    cociente : Racional x Racional -> Racional
    
    igualdad : Racional x Racional -> bool

b) Agregar a la implementación de la clase Racional las operaciones habituales entre racionales y enteros. Sobrecargar los operadores que se consideren necesarios. 
  Como ejemplo, la clase Racional debería soportar la siguiente aplicación:
  
    void main() {

       Racional r1(2,3), r2;
       Racional r3(4), r4 = r1;
       
       if (r1 == r2) 
        r1 = r1 + r2;
       else
        r1 = r1 - r2;
        
       if (r3 != r4)
        r3 = r3 * r4;
       else
        r3 = r3 / r4;
        
       if (r1 == 2)
        r1 = r1 + 1;
       else
        r1 = r1 - 1;
        
       if (r3 != 3)
        r3 = r3 * 2;
       else
        r3 = r3 / 2;
    }

c) ¿Qué modificaciones habría que realizarle a la implementación para que soporte además la siguiente aplicación?

    r3 = 3 * r2; 
    if (2 == (2 + r2))
        r3 = 2 + r2;


Ejercicio 3 (medio, imprescindible)

a) Implementar en C++ una clase que represente a los conjuntos de enteros, utilizando como estructura de datos arreglos dinámicos. La clase deberá proveer al menos las 
siguientes operaciones:

    agregar : SetInt x int -> SetInt
    remover : SetInt x int -> SetInt
    union : SetInt x SetInt -> SetInt
    diferencia : SetInt x SetInt -> SetInt
    interseccion : SetInt x SetInt -> SetInt
    pretence : SetInt x int -> bool
    esVacio : SetInt -> bool
    cantidadElem : SetInt -> int
    esIgual : SetInt x SetInt -> bool

b) Sobrecargar los operadores +, -, == y != para que realicen la unión, diferencia, igualdad y desigualdad de conjuntos.

c) Ejecutar manualmente y en una computadora el siguiente programa comparando los resultados.

    SetInt a,b,c,d,e;
    a.agregar(0);
    a.agregar(1);
    b.agregar(1);
    b.agregar(2);
    c.agregar(0);
    c.agregar(1);
    c.agregar(2);
    d = a + b;
    e = c - b;
    if (a == d)
    cout << "a == d\n";
    else
    cout << "a != d\n";
    if (e == a) 
    cout << "e == a\n";
    else
    cout << "e != a\n";