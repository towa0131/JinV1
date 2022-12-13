#pragma once

class Vector3 {
public:
    Vector3(double, double, double);

    double getX();

    double getY();

    double getZ();

private:
    double x;
    double y;
    double z;
};