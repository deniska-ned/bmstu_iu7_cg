#include "point_transformations.hpp"

#include <cassert>
#include <cmath>

#include "matrix.hpp"

#define DBL_CMP_EPS                     1e-5

void point_move(struct point &point, double dx, double dy)
{
    std::array<std::array<double, 3>, 1> matrix_coord =
            {{point.x, point.y, 1.0}};

    std::array<double, 3> matrix_move_row_0 = {1.0, 0.0, 0.0};
    std::array<double, 3> matrix_move_row_1 = {0.0, 1.0, 0.0};
    std::array<double, 3> matrix_move_row_2 = {dx,  dy,  1.0};
    std::array<std::array<double, 3>, 3> matrix_move =
            {matrix_move_row_0,
             matrix_move_row_1,
             matrix_move_row_2};

    std::array<std::array<double, 3>, 1> composition =
            matrix_mult(matrix_coord, matrix_move, 0.0);

    assert(std::fabs(composition[0][2] - 1.0) < DBL_CMP_EPS);

    point.x = composition[0][0];
    point.y = composition[0][1];
}

void point_scale(struct point &point, const struct point &center,
                 double kx, double ky)
{
    point_move(point, -center.x, -center.y);

    std::array<std::array<double, 3>, 1> matrix_coord =
            {{point.x, point.y, 1.0}};

    std::array<double, 3> matrix_scale_row_0 = {kx, 0.0, 0.0};
    std::array<double, 3> matrix_scale_row_1 = {0.0, ky, 0.0};
    std::array<double, 3> matrix_scale_row_2 = {0.0, 0.0, 1.0};
    std::array<std::array<double, 3>, 3> matrix_scale =
            {matrix_scale_row_0,
             matrix_scale_row_1,
             matrix_scale_row_2};

    std::array<std::array<double, 3>, 1> composition =
            matrix_mult(matrix_coord, matrix_scale, 0.0);

    assert(std::fabs(composition[0][2] - 1.0) < DBL_CMP_EPS);

    point.x = composition[0][0];
    point.y = composition[0][1];

    point_move(point, center.x, center.y);
}

void point_rotate(struct point &point, const struct point &center,
                  double angle)
{
    angle *= -1.0;

    point_move(point, -center.x, -center.y);

    std::array<std::array<double, 3>, 1> matrix_coord =
            {{point.x, point.y, 1.0}};

    std::array<double, 3> matrix_rot_row_0 = {cos(angle), -sin(angle), 0.0};
    std::array<double, 3> matrix_rot_row_1 = {sin(angle), cos(angle), 0.0};
    std::array<double, 3> matrix_rot_row_2 = {0.0, 0.0, 1.0};
    std::array<std::array<double, 3>, 3> matrix_rotate =
            {matrix_rot_row_0,
             matrix_rot_row_1,
             matrix_rot_row_2};

    std::array<std::array<double, 3>, 1> composition =
            matrix_mult(matrix_coord, matrix_rotate, 0.0);

    assert(std::fabs(composition[0][2] - 1.0) < DBL_CMP_EPS);

    point.x = composition[0][0];
    point.y = composition[0][1];

    point_move(point, center.x, center.y);

}
