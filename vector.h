//
// Created by admin on 11.04.2020.
//

#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    double x, y;
public:
    Vector();

    Vector(double _x, double _y);

    ~Vector();

    double getX() const;

    double getY() const;

    void setX(double x);

    void setY(double y);

    bool operator==(const Vector &v) const;

    bool operator!=(const Vector &v) const;

    Vector operator+(const Vector &v) const;

    Vector operator-(const Vector &v) const;

    Vector operator*(const double a) const;

    Vector operator/(const double a) const;

    Vector operator*(const int a) const;

    double operator*(const Vector &v) const;

};

Vector operator*(double a, const Vector &v);

Vector operator*(int a, const Vector &v);

std::ostream& operator<<(std::ostream& os, const Vector &v);

std::istream& operator>>(std::istream& is, Vector &v);

#endif //GRAPHIC_MASTER_VECTOR_H
