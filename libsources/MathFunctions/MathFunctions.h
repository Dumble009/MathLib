#pragma once

#include <float.h>

namespace math
{
    class MathFunctions
    {
    public:
        // f1とf2が大体一緒か比較する。epsilonは誤差の許容値
        static bool IsFloatAlmostSame(const float &f1, const float &f2, const float &epsilon = DBL_EPSILON);
    };
}