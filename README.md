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
