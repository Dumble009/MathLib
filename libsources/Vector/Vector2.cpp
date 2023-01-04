#pragma once
#include "Vector2.h"
#include "MathFunctions/MathFunctions.h"

#include <stdexcept>

namespace math
{
    template <class T>
    Vector2Imp<T>::Vector2Imp(const T &_x, const T &_y)
    {
        x = _x;
        y = _y;
    }

    template <class T>
    T &Vector2Imp<T>::operator[](size_t i)
    {
        if (i == 0)
        {
            return x;
        }
        else if (i == 1)
        {
            return y;
        }

        throw std::out_of_range("invalid range access to Vector");
    }

    template <class T>
    T const &Vector2Imp<T>::operator[](size_t i) const
    {
        if (i == 0)
        {
            return x;
        }
        else if (i == 1)
        {
            return y;
        }

        throw std::out_of_range("invalid range access to Vector");
    }

    template <class T>
    Vector2Imp<T> Vector2Imp<T>::operator+(const Vector2Imp<T> &v) const
    {
        return Vector2Imp<T>(this->x + v.x, this->y + v.y);
    }

    template <class T>
    Vector2Imp<T> Vector2Imp<T>::operator-(const Vector2Imp<T> &v) const
    {
        return Vector2Imp<T>(this->x - v.x, this->y - v.y);
    }

    template <class T>
    Vector2Imp<T> Vector2Imp<T>::operator*(const T &s) const
    {
        return Vector2Imp<T>(this->x * s, this->y * s);
    }

    template <class T>
    Vector2Imp<T> Vector2Imp<T>::operator/(const T &s) const
    {
        return Vector2Imp<T>(this->x / s, this->y / s);
    }

    template class Vector2Imp<float>;
    template class Vector2Imp<double>;
    template class Vector2Imp<int>;
    template class Vector2Imp<long long>;
}