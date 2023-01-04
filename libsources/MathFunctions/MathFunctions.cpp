#include "MathFunctions.h"

#include <cmath>

namespace math
{
    bool MathFunctions::IsFloatAlmostSame(const float &f1, const float &f2, const float &epsilon)
    {
        return abs(f1 - f2) < epsilon; // 2つの浮動小数点の差分の絶対値が一定以下であれば一致しているとみなす。
    }
}