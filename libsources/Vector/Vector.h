#pragma once

namespace math
{
    // D : 次元数、T : 要素の型(float, double, int, long long)
    template <int D, class T>
    class Vector
    {
    public:
        T Dot(const Vector<D, T> &v);

        void operator+=(const Vector<D, T> &v);
        void operator-=(const Vector<D, T> &v);
        bool operator==(const Vector<D, T> &v) const;
        bool operator!=(const Vector<D, T> &v) const;
        T &operator[](size_t i);
        T const &operator[](size_t i) const;
    };
}