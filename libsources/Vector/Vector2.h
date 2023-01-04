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
        Vector2Imp<T> operator+(const Vector2Imp<T> &v) const;
        Vector2Imp<T> operator-(const Vector2Imp<T> &v) const;

        Vector2Imp<T> operator*(const T &s) const;
        Vector2Imp<T> operator/(const T &s) const;

        template <class U>
        friend Vector2Imp<U> operator*(const U &s, const Vector2Imp<U> &v);
    };

    template <class T>
    Vector2Imp<T> operator*(const T &s, const Vector2Imp<T> &v)
    {
        return v * s;
    }

    using Vector2 = Vector2Imp<float>;
}