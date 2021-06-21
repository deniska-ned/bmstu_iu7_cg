#include "gtest/gtest.h"

#include <cmath>

#include "point_transformations.hpp"

#define DBL_CMP_EPS                     1e-5

TEST(point_scale_pos, from_center_k_1_1)
{
    struct point center = {0.0, 0.0};
    struct point point = {1.0, 1.0};
    double kx = 1.0;
    double ky = 1.0;
    struct point point_expecected = point;

    point_scale(point, center, kx, ky);

    ASSERT_NEAR(point_expecected.x, point.x, DBL_CMP_EPS);
    ASSERT_NEAR(point_expecected.y, point.y, DBL_CMP_EPS);
}

TEST(point_scale_pos, from_center_k_2_3)
{
    struct point center = {0.0, 0.0};
    struct point point = {1.0, 1.0};
    double kx = 2.0;
    double ky = 3.0;
    struct point point_expecected = {2.0, 3.0};

    point_scale(point, center, kx, ky);

    ASSERT_NEAR(point_expecected.x, point.x, DBL_CMP_EPS);
    ASSERT_NEAR(point_expecected.y, point.y, DBL_CMP_EPS);
}

TEST(point_scale_pos, from_1_1_k_1_1)
{
    struct point center = {1.0, 1.0};
    struct point point = {2.0, 3.0};
    double kx = 1.0;
    double ky = 1.0;
    struct point point_expecected = {2.0, 3.0};

    point_scale(point, center, kx, ky);

    ASSERT_NEAR(point_expecected.x, point.x, DBL_CMP_EPS);
    ASSERT_NEAR(point_expecected.y, point.y, DBL_CMP_EPS);
}

TEST(point_scale_pos, from_1_1_k_5_1)
{
    struct point center = {1.0, 1.0};
    struct point point = {2.0, 3.0};
    double kx = 5.0;
    double ky = 7.0;
    struct point point_expecected = {6.0, 15.0};

    point_scale(point, center, kx, ky);

    ASSERT_NEAR(point_expecected.x, point.x, DBL_CMP_EPS);
    ASSERT_NEAR(point_expecected.y, point.y, DBL_CMP_EPS);
}

TEST(point_rotation_pos, from_center)
{
    struct point center = {0.0, 0.0};
    struct point point = {2.0, 3.0};
    double angle = 90 / 180.0 * M_PI;
    struct point point_expecected = {-3.0, 2.0};

    point_rotate(point, center, angle);

    ASSERT_NEAR(point_expecected.x, point.x, DBL_CMP_EPS);
    ASSERT_NEAR(point_expecected.y, point.y, DBL_CMP_EPS);
}

TEST(point_rotation_pos, not_from_center)
{
    struct point center = {1.0, 2.0};
    struct point point = {3.0, 5.0};
    double angle = 90 / 180.0 * M_PI;
    struct point point_expecected = {-2.0, 4.0};

    point_rotate(point, center, angle);

    ASSERT_NEAR(point_expecected.x, point.x, DBL_CMP_EPS);
    ASSERT_NEAR(point_expecected.y, point.y, DBL_CMP_EPS);
}
