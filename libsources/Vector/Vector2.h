#pragma once
#include "Vector.h"

namespace math
{
    template <class T>
    class Vector2Imp : public Vector<2, T>
    {
    public:
        Vector2Imp<T>(const T &_x, const T &_y);
        T x, y;
        T &operator[](size_t i) override;
        T const &operator[](size_t i) const override;
    };

    using Vector2 = Vector2Imp<float>;
}