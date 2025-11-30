#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept> // Para std::invalid_argument
#include "Point2D.h" // Se incluye porque las clases derivadas lo usarán

class Shape {
protected:
    // Atributo protegido que almacena el color de la figura
    std::string color;

public:
    // Constructores
    // ----------------------------------------------------
    // Constructor por defecto, crea una figura de color rojo.
    Shape();
    
    // Crea una figura del color especificado.
    // Lanza std::invalid_argument si el color no es válido.
    Shape(std::string color);

    // Métodos (Interfaz pública)
    // ----------------------------------------------------
    
    // Devuelve el color de relleno de la figura.
    std::string get_color() const;

    // Modifica el color de relleno de la figura. 
    // Lanza std::invalid_argument si el color no es válido.
    void set_color(std::string c);

    // Métodos virtuales puros (hacen a Shape abstracta)
    // ----------------------------------------------------
    
    // Calcula el área de una figura.
    virtual double area() const = 0;

    // Calcula el perímetro de una figura.
    virtual double perimeter() const = 0;

    // Traslada la figura aplicando los incrementos de X e Y.
    virtual void translate(double incX, double incY) = 0;

    // Imprimirá por pantalla información básica sobre la figura.
    virtual void print() const = 0;

    // Destructor virtual (esencial para clases base)
    virtual ~Shape() = default;
};

#endif
