#pragma once

class Vector3 {
public:
    Vector3(double, double, double);

    double getX();

    double getY();

    double getZ();

    void setX(double x);

    void setY(double y);

    void setZ(double z);

    void add(Vector3 vec);

    void multiply(Vector3 vec);

private:
    double x;
    double y;
    double z;
};