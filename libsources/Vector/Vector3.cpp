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
    T &Vector3Imp<T>::operator[](size_t i)
    {
        if (i == 0)
        {
            return x;
        }
        else if (i == 1)
        {
            return y;
        }
        else if (i == 2)
        {
            return z;
        }

        throw std::out_of_range("invalid range access to Vector");
    }

    template <class T>
    T const &Vector3Imp<T>::operator[](size_t i) const
    {
        if (i == 0)
        {
            return x;
        }
        else if (i == 1)
        {
            return y;
        }
        else if (i == 2)
        {
            return z;
        }

        throw std::out_of_range("invalid range access to Vector");
    }

    template <class T>
    bool Vector3Imp<T>::operator==(const Vector3Imp<T> &v) const
    {
        return MathFunctions::Compare(this->x, v.x) &&
               MathFunctions::Compare(this->y, v.y) &&
               MathFunctions::Compare(this->z, v.z);
    }

    template class Vector3Imp<float>;
    template class Vector3Imp<double>;
    template class Vector3Imp<int>;
    template class Vector3Imp<long long>;
}