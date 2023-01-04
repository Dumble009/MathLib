#pragma once
#include "Vector.h"

namespace math
{
    template <class T>
    class Vector2 : public Vector<3, T>
    {
    public:
        Vector2<T>(const T &_x, const T &_y);
        T x, y;
        T &operator[](size_t i) override;
        T const &operator[](size_t i) const override;
    };
}