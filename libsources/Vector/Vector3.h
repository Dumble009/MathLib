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

        Vector3Imp<T> Cross(const Vector3Imp<T> &v) const;

        Vector3Imp<T> operator+(const Vector3Imp<T> &v) const;
        Vector3Imp<T> operator-(const Vector3Imp<T> &v) const;

        Vector3Imp<T> operator*(const T &s) const;
        Vector3Imp<T> operator/(const T &s) const;

        template <class U>
        friend Vector3Imp<U> operator*(const U &s, const Vector3Imp<U> &v);
    };

    template <class T>
    Vector3Imp<T> operator*(const T &s, const Vector3Imp<T> &v)
    {
        return v * s;
    }

    using Vector3 = Vector3Imp<float>;
    using Vector3d = Vector3Imp<double>;
    using Vector3i = Vector3Imp<int>;
    using Vector3ll = Vector3Imp<long long>;
}