#include "MathFunctions.h"

#include <cmath>

namespace math
{
    bool MathFunctions::IsFloatAlmostSame(const float &f1, const float &f2, const float &epsilon)
    {
        return abs(f1 - f2) < epsilon; // 2つの浮動小数点の差分の絶対値が一定以下であれば一致しているとみなす。
    }

    bool MathFunctions::IsDoubleAlmostSame(const double &d1, const double &d2, const double &epsilon)
    {
        return abs(d1 - d2) < epsilon;
    }

    // Compareを型毎に特殊化する。整数は完全一致で比較するが実数は誤差を許容する比較手法を使用するため
    template <>
    bool MathFunctions::Compare(const int &v1, const int &v2)
    {
        return v1 == v2;
    }

    template <>
    bool MathFunctions::Compare(const long long &v1, const long long &v2)
    {
        return v1 == v2;
    }

    template <>
    bool MathFunctions::Compare(const float &v1, const float &v2)
    {
        return IsFloatAlmostSame(v1, v2);
    }

    template <>
    bool MathFunctions::Compare(const double &v1, const double &v2)
    {
        return IsDoubleAlmostSame(v1, v2);
    }
}