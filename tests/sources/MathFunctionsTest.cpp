#include <gtest/gtest.h>
#include "MathFunctions/MathFunctions.h"
using namespace math;

TEST(FloatAlmostSameTest, BasicAssertions)
{
    ASSERT_TRUE(MathFunctions::IsFloatAlmostSame(1.0f, 1.0f));
    ASSERT_TRUE(MathFunctions::IsFloatAlmostSame(1.0f / 3.0f, 2.0f / 6.0f));
    ASSERT_TRUE(MathFunctions::IsFloatAlmostSame(0.0f, 10000.0f * 0.0f));

    ASSERT_FALSE(MathFunctions::IsFloatAlmostSame(1.0f, 2.0f));
    ASSERT_FALSE(MathFunctions::IsFloatAlmostSame(1.0f / 3.0f, 1.0f / 2.9f)) << 1.0f / 3.0f << ":" << 1.0f / 2.9f;
}

TEST(DoubleAlmostSameTest, BasicAssertions)
{
    ASSERT_TRUE(MathFunctions::IsDoubleAlmostSame(1.0, 1.0));
    ASSERT_TRUE(MathFunctions::IsDoubleAlmostSame(1.0 / 3.0, 2.0 / 6.0));
    ASSERT_TRUE(MathFunctions::IsDoubleAlmostSame(0.0, 10000.0 * 0.0));

    ASSERT_FALSE(MathFunctions::IsDoubleAlmostSame(1.0, 2.0));
    ASSERT_FALSE(MathFunctions::IsDoubleAlmostSame(1.0 / 3.0, 1.0 / 2.9)) << 1.0 / 3.0 << ":" << 1.0 / 2.9;
}

template <class T>
void CompareTypes(T v1, T v2, bool isTrue = true)
{
    if (isTrue)
    {
        ASSERT_TRUE(MathFunctions::Compare(v1, v2));
    }
    else
    {
        ASSERT_FALSE(MathFunctions::Compare(v1, v2));
    }
}

TEST(ComparTest, BasicAssertions)
{
    // int型
    CompareTypes(1, 1);
    CompareTypes(100 * 2, 40 * 5);
    CompareTypes(1, 0, false);

    // long long型
    CompareTypes(1ll, 1ll);
    CompareTypes(100ll * 2ll, 40ll * 5ll);
    CompareTypes(1ll, 0ll, false);

    // float型
    CompareTypes(1.0f, 1.0f);
    CompareTypes(100.0f * 2.0f, 40.0f * 5.0f);
    CompareTypes(1.0f, 0.0f, false);

    // double型
    CompareTypes(1.0, 1.0);
    CompareTypes(100.0 * 2.0, 40.0 * 5.0);
    CompareTypes(1.0, 0.0, false);
}