#pragma once

namespace math
{
    // D : 次元数、T : 要素の型(float, double, int, long long)
    template <int D, class T>
    class Vector
    {
    public:
        virtual T &operator[](size_t i) = 0;
        virtual T const &operator[](size_t i) const = 0;
    };
}