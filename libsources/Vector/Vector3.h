#pragma once
#include "Vector.h"

namespace math
{
    template <class T>
    class Vector3Imp : public Vector<3, T>
    {
    public:
        Vector3Imp<T>(const T &_x, const T &_y, const T &_z);
        T x, y, z;
        T &operator[](size_t i) override;
        T const &operator[](size_t i) const override;
        Vector3Imp<T> operator+(const Vector3Imp<T> &v) const;
        Vector3Imp<T> operator-(const Vector3Imp<T> &v) const;
    };

    using Vector3 = Vector3Imp<float>;
}