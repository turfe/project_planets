//
// Created by admin on 11.04.2020.
//
#include <iostream>
#include "vector.h"
#include <math.h>

Vector::Vector() : Vector(0, 0) {
}

Vector::Vector(double _x, double _y) : x(_x), y(_y){

}

Vector::~Vector() {
}

double Vector::getX() const {
    return x;
}

double Vector::getY() const {
    return y;
}

void Vector::setX(double x) {
    this->x = x;
}

void Vector::setY(double y) {
    this->y = y;
}

bool Vector::operator==(const Vector &v) const {
    double E = 0.000001;
    return (abs(v.x - x) < E) && (abs(v.y - y) < E);
}

bool Vector::operator!=(const Vector &v) const {
    return !(*this == v);
}

Vector Vector::operator+(const Vector &v) const {
    return Vector(x + v.x, y + v.y);
}

Vector Vector::operator-(const Vector &v) const {
    return Vector(x - v.x, y - v.y);
}

Vector Vector::operator*(const double a) const {
    return Vector(x * a, y * a);
}

Vector Vector::operator/(const double a) const {
    return Vector(x / a, y / a);
}

Vector Vector::operator*(const int a) const {
    return Vector(x * a, y * a);
}

double Vector::operator*(const Vector &v) const {
    return x * v.x + y * v.y;
}


Vector operator*(double a, const Vector &v) {
    return Vector(v.getX() * a, v.getY() * a);
}

Vector operator*(int a, const Vector &v) {
    return Vector(v.getX() * a, v.getY() * a);
}

std::ostream &operator<<(std::ostream &os, const Vector &v) {
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Vector &v) {
    double x, y;
    is >> x >> y;
    v.setX(x);
    v.setY(y);
    return is;
}
