#include <cmath>

#include "point_actions.hpp"

#define DBL_EQ_EPS                      1e-5

double line_len(QPoint a, QPoint b)
{
    return std::sqrt(
            (a.x() - b.x()) * (a.x() - b.x())
            + (a.y() - b.y()) * (a.y() - b.y()));
}

QPointF line_intersection(QLine l1, QLine l2)
{
    int a1 = l1.y2() - l1.y1();
    int b1 = -(l1.x2() - l1.x1());
    int c1 = a1 * l1.x1() + b1 * l1.y1();

    int a2 = l2.y2() - l2.y1();
    int b2 = -(l2.x2() - l2.x1());
    int c2 = a2 * l2.x1() + b2 * l2.y1();

    int determinant = a1 * b2 - a2 * b1;

    if (0 == determinant)
    {
        throw parallel_lines_intersection_error();
    }
    else
    {
        double x = (b2 * c1 - b1 * c2) / (double) determinant;
        double y = (a1 * c2 - a2 * c1) / (double) determinant;

        return {x, y};
    }
}

QPointF line_intersection(const double a1, const double b1, const double c1,
                          const double a2, const double b2, const double c2)
{
    double determinant = a1 * b2 - a2 * b1;

    if (fabs(determinant) < DBL_EQ_EPS)
    {
        throw parallel_lines_intersection_error();
    }
    else
    {
        double x = (b1 * c2 - b2 * c1) / (double) determinant;
        double y = (a2 * c1 - a1 * c2) / (double) determinant;

        return {x, y};
    }
}
