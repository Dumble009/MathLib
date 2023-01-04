#pragma once
#include "Vector.h"

namespace math
{
    template <class T>
    class Vector3 : public Vector<3, T>
    {
    public:
        Vector3<T>(const T &_x, const T &_y, const T &_z);
        T x, y, z;
        T &operator[](size_t i) override;
        T const &operator[](size_t i) const override;
    };
}