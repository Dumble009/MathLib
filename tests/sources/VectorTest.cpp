﻿#include <gtest/gtest.h>
#include "Vector/Vector3.h"

using namespace math;

TEST(CreateVector3, BasicAssertions)
{
    Vector3<float> v = Vector3<float>(1.0f, 2.0f, 3.0f);
    ASSERT_EQ(v.x, 1.0f);
    ASSERT_EQ(v.y, 2.0f);
    ASSERT_EQ(v.z, 3.0f);
}