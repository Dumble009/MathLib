#include <gtest/gtest.h>
#include "Vector/Vector3.h"
#include "Vector/Vector2.h"
#include "MathFunctions/MathFunctions.h"

using namespace math;

// 加算代入、減算代入が正しく機能するかどうかのテスト
template <class VT>
void AssignmentTest(const VT &v1, const VT &v2)
{
    VT v3 = v1;
    v3 += v2;
    VT v4 = v1 + v2;
    ASSERT_TRUE(v3 == v4);

    v3 = v1;
    v3 -= v2;
    v4 = v1 - v2;
    ASSERT_TRUE(v3 == v4);
}

template <class T, class VT>
void Vector3Tests(const T &x, const T &y, const T &z)
{
    // コンストラクタが正しく機能するかどうか
    VT v1 = VT(x, y, z);
    ASSERT_EQ(v1.x, x);
    ASSERT_EQ(v1.y, y);
    ASSERT_EQ(v1.z, z);

    // 添え字アクセスが正しく出来るかどうか
    ASSERT_EQ(v1.x, v1[0]);
    ASSERT_EQ(v1.y, v1[1]);
    ASSERT_EQ(v1.z, v1[2]);

    // 構造体の大きさが正常かどうかの確認
    ASSERT_EQ(sizeof(VT), sizeof(T) * 3);

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

    // スカラーが先頭に来る掛け算が正しくできるかどうか
    v3 = static_cast<T>(10) * v1;

    ASSERT_TRUE(v3 == v4);

    // 割り算が正しくできるかどうか
    v3 = v1 / static_cast<T>(10);
    v4 = VT(v1.x / 10, v1.y / 10, v1.z / 10);

    ASSERT_TRUE(v3 == v4);

    AssignmentTest(v1, v3);

    T dot = v1.Dot(v3);

    ASSERT_TRUE(MathFunctions::Compare(dot, v1.x * v3.x + v1.y * v3.y + v1.z * v3.z));
}

template <class T, class VT>
void Vector2Tests(const T &x, const T &y)
{
    // コンストラクタが正しく機能するかどうか
    VT v1 = VT(x, y);
    ASSERT_EQ(v1.x, x);
    ASSERT_EQ(v1.y, y);

    // 添え字アクセスが正しく出来るかどうか
    ASSERT_EQ(v1.x, v1[0]);
    ASSERT_EQ(v1.y, v1[1]);

    // 構造体の大きさが正常かどうかの確認
    ASSERT_EQ(sizeof(VT), sizeof(T) * 2);

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

    // スカラーが先頭に来る掛け算が正しくできるかどうか
    v3 = static_cast<T>(10) * v1;

    ASSERT_TRUE(v3 == v4);

    // 割り算が正しくできるかどうか
    v3 = v1 / static_cast<T>(10);
    v4 = VT(v1.x / 10, v1.y / 10);

    ASSERT_TRUE(v3 == v4);

    AssignmentTest(v1, v3);

    T dot = v1.Dot(v3);

    ASSERT_TRUE(MathFunctions::Compare(dot, v1.x * v3.x + v1.y * v3.y));
}

TEST(Vector3Test, BasicAssertions)
{
    Vector3Tests<float, Vector3>(1.0f, 2.0f, 3.0f);
    Vector3Tests<double, Vector3d>(1.0, 2.0, 3.0);
    Vector3Tests<int, Vector3i>(1, 2, 3);
    Vector3Tests<long long, Vector3ll>(1ll, 2ll, 3ll);
}

TEST(Vector2Test, BasicAssertions)
{
    Vector2Tests<float, Vector2>(1.0f, 2.0f);
    Vector2Tests<double, Vector2d>(1.0, 2.0);
    Vector2Tests<int, Vector2i>(1, 2);
    Vector2Tests<long long, Vector2ll>(1ll, 2ll);
}