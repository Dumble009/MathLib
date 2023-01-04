#include <gtest/gtest.h>
#include "MathFunctions/MathFunctions.h"
using namespace math;

TEST(FloatCompareTest, BasicAssertions)
{
    ASSERT_TRUE(MathFunctions::IsFloatAlmostSame(1.0f, 1.0f));
    ASSERT_TRUE(MathFunctions::IsFloatAlmostSame(1.0f / 3.0f, 2.0f / 6.0f));
    ASSERT_TRUE(MathFunctions::IsFloatAlmostSame(0.0f, 10000.0f * 0.0f));
}