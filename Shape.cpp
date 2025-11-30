#include "Shape.h"
#include <iostream>
#include <stdexcept>

// Función auxiliar privada para validar el color
// Los únicos colores válidos son "red", "green", "blue"
bool is_valid_color(const std::string& c) {
    return c == "red" || c == "green" || c == "blue";
}

// Constructor por defecto
// Crea una figura de color "red" (rojo).
Shape::Shape() : color("red") {}

// Constructor con color específico
// Lanza excepción si el color no es válido.
Shape::Shape(std::string new_color) {
    if (!is_valid_color(new_color)) {
        throw std::invalid_argument("Error: El color debe ser 'red', 'green' o 'blue'.");
    }
    this->color = new_color;
}

// Devuelve el color de relleno de la figura.
std::string Shape::get_color() const {
    return color;
}

// Modifica el color de relleno de la figura.
void Shape::set_color(std::string c) {
    if (!is_valid_color(c)) {
        throw std::invalid_argument("Error: El color debe ser 'red', 'green' o 'blue'.");
    }
    this->color = c;
}

// Las funciones virtuales puras (area, perimeter, translate, print)
// no necesitan implementación aquí, ya que son abstractas (= 0).
