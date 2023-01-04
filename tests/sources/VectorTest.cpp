#include <gtest/gtest.h>
#include "Vector/Vector3.h"
#include "Vector/Vector2.h"

using namespace math;

TEST(CreateVector3, BasicAssertions)
{
    Vector3 v = Vector3(1.0f, 2.0f, 3.0f);
    ASSERT_EQ(v.x, 1.0f);
    ASSERT_EQ(v.y, 2.0f);
    ASSERT_EQ(v.z, 3.0f);
}

TEST(CreateVector2, BasicAssertions)
{
    Vector2 v = Vector2(1.0f, 2.0f);
    ASSERT_EQ(v.x, 1.0f);
    ASSERT_EQ(v.y, 2.0f);
}