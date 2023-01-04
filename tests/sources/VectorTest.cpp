﻿#include <gtest/gtest.h>
#include "Vector/Vector3.h"
#include "Vector/Vector2.h"

using namespace math;

template <class T, class VT>
void Vector3Tests(const T &x, const T &y, const T &z)
{
    VT v1 = VT(x, y, z);
    VT v2 = VT(x, y, z);

    ASSERT_TRUE(v1 == v2);
    ASSERT_FALSE(v1 != v2);

    VT v3 = VT(x - 1, y - 1, z - 1);

    ASSERT_FALSE(v1 == v3);
    ASSERT_TRUE(v1 != v3);
}

template <class T>
void Vector2Tests(const T &x, const T &y)
{
}

TEST(CreateVector3, BasicAssertions)
{
    Vector3 v = Vector3(1.0f, 2.0f, 3.0f);
    ASSERT_EQ(v.x, 1.0f);
    ASSERT_EQ(v.y, 2.0f);
    ASSERT_EQ(v.z, 3.0f);

    Vector3Tests<float, Vector3>(1.0f, 2.0f, 3.0f);
}

TEST(CreateVector2, BasicAssertions)
{
    Vector2 v = Vector2(1.0f, 2.0f);
    ASSERT_EQ(v.x, 1.0f);
    ASSERT_EQ(v.y, 2.0f);
}