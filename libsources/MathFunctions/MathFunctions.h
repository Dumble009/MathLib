#pragma once

#include <float.h>
#include "Vector/Vector.h"

namespace math
{
    class MathFunctions
    {
    public:
        // f1とf2が大体一緒か比較する。epsilonは誤差の許容値
        static bool IsFloatAlmostSame(const float &f1, const float &f2, const float &epsilon = DBL_EPSILON);
        static bool IsDoubleAlmostSame(const double &d1, const double &d2, const double &epsilon = DBL_EPSILON);

        // T型の二つの値を比較する。
        template <class T>
        static bool Compare(const T &v1, const T &v2);
    };
}