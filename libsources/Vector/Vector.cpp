#include "Vector.h"
#include "MathFunctions/MathFunctions.h"

namespace math
{
    template <int D, class T>
    T Vector<D, T>::Dot(const Vector<D, T> &v)
    {
        T ret = static_cast<T>(0);
        for (int i = 0; i < D; i++)
        {
            ret += (*this)[i] * v[i];
        }

        return ret;
    }

    template <int D, class T>
    void Vector<D, T>::operator+=(const Vector<D, T> &v)
    {
        for (int i = 0; i < D; i++)
        {
            (*this)[i] += v[i];
        }
    }

    template <int D, class T>
    void Vector<D, T>::operator-=(const Vector<D, T> &v)
    {
        for (int i = 0; i < D; i++)
        {
            (*this)[i] -= v[i];
        }
    }

    template <int D, class T>
    bool Vector<D, T>::operator==(const Vector<D, T> &v) const
    {
        for (int i = 0; i < D; i++)
        {
            if (!MathFunctions::Compare((*this)[i], v[i]))
            {
                return false;
            }
        }

        return true;
    }

    template <int D, class T>
    bool Vector<D, T>::operator!=(const Vector<D, T> &v) const
    {
        return !(*(this) == v);
    }

    template <int D, class T>
    T &Vector<D, T>::operator[](size_t i)
    {
        void *ptr = this;
        return static_cast<T *>(ptr)[i];
    }

    template <int D, class T>
    T const &Vector<D, T>::operator[](size_t i) const
    {
        const void *ptr = this;
        return static_cast<const T *>(ptr)[i];
    }

    template class Vector<3, float>;
    template class Vector<3, double>;
    template class Vector<3, int>;
    template class Vector<3, long long>;

    template class Vector<2, float>;
    template class Vector<2, double>;
    template class Vector<2, int>;
    template class Vector<2, long long>;
}