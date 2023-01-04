#include <gtest/gtest.h>
#include "Vector/Vector3.h"
#include "Vector/Vector2.h"

using namespace math;

template <class T, class VT>
void Vector3Tests(const T &x, const T &y, const T &z)
{
    // コンストラクタが正しく機能するかどうか
    VT v1 = VT(x, y, z);
    ASSERT_EQ(v1.x, x);
    ASSERT_EQ(v1.y, y);
    ASSERT_EQ(v1.z, z);

    // 比較演算子が正しく機能するかどうか
    VT v2 = VT(x, y, z);

    ASSERT_TRUE(v1 == v2);
    ASSERT_FALSE(v1 != v2);

    VT v3 = VT(x - 1, y - 1, z - 1);

    ASSERT_FALSE(v1 == v3);
    ASSERT_TRUE(v1 != v3);

    // 足し算が正しくできるかどうか
    v3 = v1 + v2;
    VT v4 = VT(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);

    ASSERT_TRUE(v3 == v4);

    // 引き算が正しくできるかどうか
    v3 = v1 - v2;
    v4 = VT(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);

    ASSERT_TRUE(v3 == v4);

    // 掛け算が正しくできるかどうか
    v3 = v1 * static_cast<T>(10);
    v4 = VT(v1.x * 10, v1.y * 10, v1.z * 10);

    ASSERT_TRUE(v3 == v4);

    // 掛け算が正しくできるかどうか
    v3 = v1 / static_cast<T>(10);
    v4 = VT(v1.x / 10, v1.y / 10, v1.z / 10);

    ASSERT_TRUE(v3 == v4);
}

template <class T, class VT>
void Vector2Tests(const T &x, const T &y)
{
    // コンストラクタが正しく機能するかどうか
    VT v1 = VT(x, y);
    ASSERT_EQ(v1.x, x);
    ASSERT_EQ(v1.y, y);

    // 比較演算子が正しく機能するかどうか
    VT v2 = VT(x, y);

    ASSERT_TRUE(v1 == v2);
    ASSERT_FALSE(v1 != v2);

    VT v3 = VT(x - 1, y - 1);

    ASSERT_FALSE(v1 == v3);
    ASSERT_TRUE(v1 != v3);

    // 足し算が正しくできるかどうか
    v3 = v1 + v2;
    VT v4 = VT(v1.x + v2.x, v1.y + v2.y);

    ASSERT_TRUE(v3 == v4);

    // 引き算が正しくできるかどうか
    v3 = v1 - v2;
    v4 = VT(v1.x - v2.x, v1.y - v2.y);

    ASSERT_TRUE(v3 == v4);

    // 掛け算が正しくできるかどうか
    v3 = v1 * static_cast<T>(10);
    v4 = VT(v1.x * 10, v1.y * 10);

    ASSERT_TRUE(v3 == v4);

    // 掛け算が正しくできるかどうか
    v3 = v1 / static_cast<T>(10);
    v4 = VT(v1.x / 10, v1.y / 10);

    ASSERT_TRUE(v3 == v4);
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

    Vector2Tests<float, Vector2>(1.0f, 2.0f);
}