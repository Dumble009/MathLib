#include "Vector.h"
#include "MathFunctions/MathFunctions.h"

namespace math
{
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

    template class Vector<3, float>;
    template class Vector<3, double>;
    template class Vector<3, int>;
    template class Vector<3, long long>;

    template class Vector<2, float>;
    template class Vector<2, double>;
    template class Vector<2, int>;
    template class Vector<2, long long>;
}