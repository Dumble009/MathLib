// ----------STLのinclude----------
#include <iostream> // 入出力
#include "MathLib.h"

int main(void)
{
    math::Vector3 v1 = math::Vector3(1, 2, 3);
    math::Vector3 v2 = math::Vector3(4, 5, 6);

    auto v3 = v1 + v2;

    std::cout << "(1, 2, 3) + (4, 5, 6) = "
              << "(" << v3.x << ", " << v3.y << ", " << v3.z << ")" << std::endl;
}