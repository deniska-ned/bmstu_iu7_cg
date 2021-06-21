#include <cmath>

#include <QCTriangle.hpp>
#include <QCRectangle.hpp>

#include "gtest/gtest.h"

#include "point_actions.hpp"

#define FLOAT_TOL 1e-5

TEST(triangle_incenter_suite, default)
{
    QPoint p_incenter = QCTriangle(
            QPoint(0, 0),
            QPoint(100, 100),
            QPoint(200, 0)
    ).get_incenter().toPoint();
    ASSERT_EQ(p_incenter.x(), 100);
    ASSERT_EQ(p_incenter.y(), 41);
}

TEST(triangle_incenter_suite, undefault)
{
    QPoint p_incenter = QCTriangle(
            QPoint(-100, -14),
            QPoint(-143, 102),
            QPoint(1, 111)
    ).get_incenter().toPoint();
    ASSERT_EQ(p_incenter.x(), -87);
    ASSERT_EQ(p_incenter.y(), 66);
}

TEST(triangle_incenter_suite, right_triangle)
{
    QPoint p_incenter = QCTriangle(
            QPoint(0, 0),
            QPoint(0, 100),
            QPoint(50, 0)
    ).get_incenter().toPoint();
    ASSERT_EQ(p_incenter.x(), 19);
    ASSERT_EQ(p_incenter.y(), 19);
}

TEST(triangle_incenter_suite, obtuse_triangle)
{
    QPoint p_incenter = QCTriangle(
            QPoint(-100, -10),
            QPoint(0, 10),
            QPoint(100, -10)
    ).get_incenter().toPoint();
    ASSERT_EQ(p_incenter.x(), 0);
    ASSERT_EQ(p_incenter.y(), 0);
}

TEST(triangle_incenter_suite, acute_triangle)
{
    QPoint p_incenter = QCTriangle(
            QPoint(-10, -10),
            QPoint(0, 10),
            QPoint(10, -10)
    ).get_incenter().toPoint();
    ASSERT_EQ(p_incenter.x(), 0);
    ASSERT_EQ(p_incenter.y(), -4);
}

TEST(line_intersection_suite, x)
{
    QPoint p_incenter = line_intersection(
            QLine(QPoint(0, 0), QPoint(9, 9)),
            QLine(QPoint(0, 8), QPoint(8, 0))
    ).toPoint();

    ASSERT_EQ(p_incenter.x(), 4);
    ASSERT_EQ(p_incenter.y(), 4);
}

TEST(line_intersection_suite, x_between)
{
    QPoint p_incenter = line_intersection(
            QLine(QPoint(0, 0), QPoint(1, 1)),
            QLine(QPoint(0, 5), QPoint(1, 2))
    ).toPoint();

    ASSERT_EQ(p_incenter.x(), 1);
    ASSERT_EQ(p_incenter.y(), 1);
}

TEST(line_intersection_suite, right_angle)
{
    QPoint p_incenter = line_intersection(
            QLine(QPoint(1, 1), QPoint(2, 1)),
            QLine(QPoint(1, 2), QPoint(1, 0))
    ).toPoint();

    ASSERT_EQ(p_incenter.x(), 1);
    ASSERT_EQ(p_incenter.y(), 1);
}

TEST(line_intersection_suite, parallel)
{
    try
    {
        QPointF p_incenter = line_intersection(
                QLine(QPoint(1, 1), QPoint(2, 2)),
                QLine(QPoint(1, 2), QPoint(2, 3))
        );

        ASSERT_TRUE(false);
    }
    catch (parallel_lines_intersection_error &e) {

    }
}

TEST(point_search_test_suite, triangle_line_intersection_parallel_ox)
{
    QPoint p_incenter = line_intersection(
            QLine(QPoint(0, 0), QPoint(9, 0)),
            QLine(QPoint(1, 9), QPoint(1, -9))
    ).toPoint();

    ASSERT_EQ(p_incenter.x(), 1);
    ASSERT_EQ(p_incenter.y(), 0);
}

TEST(line_len_suite, all)
{
    double len;

    len = line_len(QPoint(0, 0), QPoint(1, 0));
    ASSERT_NEAR(1, len, FLOAT_TOL);
    len = line_len(QPoint(1, 0), QPoint(0, 0));
    ASSERT_NEAR(1, len, FLOAT_TOL);
    len = line_len(QPoint(0, 0), QPoint(0, 1));
    ASSERT_NEAR(1, len, FLOAT_TOL);
    len = line_len(QPoint(0, 1), QPoint(0, 0));
    ASSERT_NEAR(1, len, FLOAT_TOL);
    len = line_len(QPoint(0, 0), QPoint(1, 1));
    ASSERT_NEAR(sqrt(2), len, FLOAT_TOL);

    len = line_len(QPoint(0, 0), QPoint(-1, 0));
    ASSERT_NEAR(1, len, FLOAT_TOL);
    len = line_len(QPoint(-1, 0), QPoint(0, 0));
    ASSERT_NEAR(1, len, FLOAT_TOL);
    len = line_len(QPoint(0, 0), QPoint(0, 1));
    ASSERT_NEAR(1, len, FLOAT_TOL);
    len = line_len(QPoint(0, -1), QPoint(0, 0));
    ASSERT_NEAR(1, len, FLOAT_TOL);
    len = line_len(QPoint(0, 0), QPoint(-1, -1));
    ASSERT_NEAR(sqrt(2), len, FLOAT_TOL);

    len = line_len(QPoint(-2, -1), QPoint(2, 1));
    ASSERT_NEAR(2 * sqrt(5), len, FLOAT_TOL);
}

TEST(is_triangle, 3_points_the_same)
{
    QPoint a(1, 1);
    QPoint b = a;
    QPoint c = a;

    bool res = QCTriangle::is_triangle(a, b, c);
    ASSERT_TRUE(!res);
}

TEST(is_triangle, 2_points_the_same)
{
    QPoint a(1, 1);
    QPoint b = a;
    QPoint c(2, 2);

    bool res = QCTriangle::is_triangle(a, b, c);
    ASSERT_TRUE(!res);
}

TEST(is_triangle, 3_points_in_line)
{
    QPoint a(1, 1);
    QPoint b(2, 2);
    QPoint c(3, 3);

    bool res = QCTriangle::is_triangle(a, b, c);
    ASSERT_TRUE(!res);
}

TEST(is_triangle, true)
{
    QPoint a(1, 1);
    QPoint b(2, 2);
    QPoint c(-3, 3);

    bool res = QCTriangle::is_triangle(a, b, c);
    ASSERT_TRUE(res);
}

TEST(is_rectangle, incorrect_order)
{
    QPoint a(0, 1);
    QPoint b(-3, 0);
    QPoint c(0, 0);

    bool res = QCRectangle::is_rectangle(a, b, c);
    ASSERT_TRUE(!res);
}

TEST(is_rectangle, parallel)
{
    QPoint a(0, 1);
    QPoint b(0, 0);
    QPoint c(-3, 0);

    bool res = QCRectangle::is_rectangle(a, b, c);
    ASSERT_TRUE(res);
}

TEST(is_rectangle, 45_degrees)
{
    QPoint a(0, 0);
    QPoint b(2, 2);
    QPoint c(4, 0);

    bool res = QCRectangle::is_rectangle(a, b, c);
    ASSERT_TRUE(res);
}

#undef FLOAT_TOL