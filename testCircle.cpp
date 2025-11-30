#include <iostream>
#include "Circle.h"
#include "Point2D.h"
#include <iomanip>

int main(){
    std::cout << std::boolalpha; // Config. para mostrar true/false

    // Prueba de constructores y operador <<
    Circle c1; // Default: red, center(0,0), radius 1
    Circle c2("green", Point2D(1,1), 2.0); // green, center(1,1), radius 2

    std::cout << "--- Prueba de Constructores y << ---\n";
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << std::endl;

    // Prueba de getters, setters y modificación de atributos
    c1.set_center(c2.get_center()); // c1 center becomes (1,1)
    c1.set_radius(c2.get_radius()); // c1 radius becomes 2
    c2.set_color("blue"); // c2 color changes

    std::cout << "--- Prueba de Modificadores (Setters) ---\n";
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << std::endl;

    // Prueba de Métodos Abstractos implementados
    std::cout << "--- Prueba de Métodos Abstractos ---\n";
    std::cout << "c1 area: " << std::fixed << std::setprecision(4) << c1.area() << std::endl; // Debería ser ~12.5664
    std::cout << "c2 perimeter: " << std::fixed << std::setprecision(4) << c2.perimeter() << std::endl; // Debería ser ~12.5664

    // Prueba de Traslación
    c1.translate(3, -1);
    std::cout << "c1 traslada (+3, -1): " << c1 << std::endl; // center = (4,0)

    // Prueba de Polimorfismo (usando el método print() de Shape)
    std::cout << "\n--- Prueba de Metodo Virtual (print) ---\n";
    Shape* s_ptr = &c1;
    s_ptr->print();
    std::cout << std::endl;
    
    return 0;
}
