#pragma once

#include "Vector3.h"

Vector3::Vector3(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vector3::getX() {
    return this->x;
}

double Vector3::getY() {
    return this->y;
}

double Vector3::getZ() {
    return this->z;
}

void Vector3::setX(double x) {
    this->x = x;
}

void Vector3::setY(double y) {
    this->y = y;
}

void Vector3::setZ(double z) {
    this->z = z;
}