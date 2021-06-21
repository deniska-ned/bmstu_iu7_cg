#ifndef LAB_02_POINT_TRANSFORMATIONS_HPP
#define LAB_02_POINT_TRANSFORMATIONS_HPP

#include "house.hpp"

void point_move(struct point &point, double dx, double dy);
void point_scale(struct point &point, const struct point &center,
                 double kx, double ky);
void point_rotate(struct point &point, const struct point &center,
                  double angle);

#endif //LAB_02_POINT_TRANSFORMATIONS_HPP
