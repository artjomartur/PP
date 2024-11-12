#pragma once


#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <stdexept> 

// Definition der Klasse Vector2d mit Template für die Typanpassung
template <typename T>
class Vector2d {
public:
    // Standardkonstruktor mit Initialisierung der Komponenten auf Standardwerte
    Vector2d() : x(T()), y(T()) {}

    // Konstruktor, um beide Komponenten direkt zu setzen
    Vector2d(T x_value, T y_value) : x(x_value), y(y_value) {}

    // Methode zum Setzen beider Komponenten
    void set(T x_value, T y_value) {
        x = x_value;
        y = y_value;
    }

    // Zugriff über den Indexoperator []
    T& operator[](size_t index) {
        if (index == 0) return x;
        if (index == 1) return y;
        throw std::out_of_range("Ungültiger Index für Vector2d");
    }

    // Konstante Version des Indexoperators für schreibgeschützten Zugriff
    const T& operator[](size_t index) const {
        if (index == 0) return x;
        if (index == 1) return y;
        throw std::out_of_range("Ungültiger Index für Vector2d");
    }

    Vector2d operatorAdd(const Vector2d& other) const {
        return Vector2d(x + other.x, y + other.y)
    }

    Vector2d operatorSub(const Vector2d& other) const {
        return Vector2d(x - other.x, y - other.y)
    }

    Vector2d operatorMul(const Vector2d& other, int z) const {
        return Vector2d(z * other.x, z * other.y)
    }

    Vector2d operatorDiv(const Vector2d& other) const {
        return Vector2d(z / other.x, z / other.y)
    }

private:
    T x; // Komponente an Stelle 0
    T y; // Komponente an Stelle 1
};

#endif // VECTOR2D_H
