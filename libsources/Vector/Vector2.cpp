#pragma once
#include "Vector2.h"

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

    template class Vector2Imp<float>;
}