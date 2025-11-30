#include "Point2D.h"
#include <cmath> // Necesario para std::sqrt y std::pow (aunque también incluido en el .h)

// Constructor
Point2D::Point2D(double x_coord, double y_coord) : x(x_coord), y(y_coord) {}

// Método estático distance
double Point2D::distance(const Point2D &a, const Point2D &b) {
    // Fórmula de distancia euclidiana: d(a,b) = sqrt((a1-b1)^2 + (a2-b2)^2)
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
}

// Sobrecarga global del operador ==
bool operator==(const Point2D &a, const Point2D &b) {
    return (a.x == b.x) && (a.y == b.y);
}

// Sobrecarga global del operador !=
bool operator!=(const Point2D &a, const Point2D &b) {
    // Reutilizamos el operador ==
    return !(a == b);
}

// Sobrecarga global del operador <<
std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
