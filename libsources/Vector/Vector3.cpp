#pragma once
#include "Vector3.h"
#include "MathFunctions/MathFunctions.h"

#include <stdexcept>

namespace math
{
    template <class T>
    Vector3Imp<T>::Vector3Imp(const T &_x, const T &_y, const T &_z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    template <class T>
    Vector3Imp<T> Vector3Imp<T>::Cross(const Vector3Imp<T> &v) const
    {
        return Vector3Imp<T>(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
    }

    template <class T>
    Vector3Imp<T> Vector3Imp<T>::operator+(const Vector3Imp<T> &v) const
    {
        return Vector3Imp<T>(this->x + v.x, this->y + v.y, this->z + v.z);
    }

    template <class T>
    Vector3Imp<T> Vector3Imp<T>::operator-(const Vector3Imp<T> &v) const
    {
        return Vector3Imp<T>(this->x - v.x, this->y - v.y, this->z - v.z);
    }

    template <class T>
    Vector3Imp<T> Vector3Imp<T>::operator*(const T &s) const
    {
        return Vector3Imp<T>(this->x * s, this->y * s, this->z * s);
    }

    template <class T>
    Vector3Imp<T> Vector3Imp<T>::operator/(const T &s) const
    {
        return Vector3Imp<T>(this->x / s, this->y / s, this->z / s);
    }

    template class Vector3Imp<float>;
    template class Vector3Imp<double>;
    template class Vector3Imp<int>;
    template class Vector3Imp<long long>;
}