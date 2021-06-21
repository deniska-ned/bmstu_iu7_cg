#include "gtest/gtest.h"

#include "matrix.hpp"

#define DBL_CMP_EPS                     1e-5

#define N 1
#define K 1
#define M 1
TEST(matrix_mult_pos, 1_1x1_1)
{
    std::array<std::array<unsigned, K>, N> m1 = {{18}};
    std::array<std::array<unsigned, M>, K> m2 = {{61}};

    std::array<std::array<unsigned, M>, N> res = matrix_mult(m1, m2, 0u);

    ASSERT_EQ(1098, res.at(0).at(0));
}
#undef M
#undef K
#undef N

#define N 1
#define K 3
#define M 3
TEST(matrix_mult_pos, 1_3x3_3)
{
    std::array<std::array<unsigned, K>, N> m1 = {{2, 3, 5}};
    std::array<unsigned, M> m2_r1 = {7, 11, 13};
    std::array<unsigned, M> m2_r2 = {17, 19, 23};
    std::array<unsigned, M> m2_r3 = {29, 31, 37};
    std::array<std::array<unsigned, M>, K> m2 = {m2_r1,
                                                 m2_r2,
                                                 m2_r3};

    std::array<std::array<unsigned, M>, N> res = matrix_mult(m1, m2, 0u);

    ASSERT_EQ(210, res.at(0).at(0));
    ASSERT_EQ(234, res.at(0).at(1));
    ASSERT_EQ(280, res.at(0).at(2));
}
#undef M
#undef K
#undef N

#define N 1
#define K 3
#define M 3
TEST(matrix_mult_pos, 1_3x3_3_double)
{
    std::array<std::array<double, K>, N> m1 = {{2.0, 3.0, 5.0}};
    std::array<double, M> m2_r1 = {7.0, 11.0, 13.0};
    std::array<double, M> m2_r2 = {17.0, 19.0, 23.0};
    std::array<double, M> m2_r3 = {29.0, 31.0, 37.0};
    std::array<std::array<double, M>, K> m2 = {m2_r1,
                                                 m2_r2,
                                                 m2_r3};

    std::array<std::array<double, M>, N> res = matrix_mult(m1, m2, 0.0);

    ASSERT_NEAR(210, res.at(0).at(0), DBL_CMP_EPS);
    ASSERT_NEAR(234, res.at(0).at(1), DBL_CMP_EPS);
    ASSERT_NEAR(280, res.at(0).at(2), DBL_CMP_EPS);
}
#undef M
#undef K
#undef N
