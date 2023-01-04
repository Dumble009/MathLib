﻿#pragma once
#include "Vector3.h"

#include <stdexcept>

namespace math
{
    template <class T>
    Vector3<T>::Vector3(const T &_x, const T &_y, const T &_z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    template <class T>
    T &Vector3<T>::operator[](size_t i)
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
    T const &Vector3<T>::operator[](size_t i) const
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

    template class Vector3<float>;
}