#ifndef LAB_01_POINT_ACTIONS_HPP
#define LAB_01_POINT_ACTIONS_HPP

#include <QPoint>
#include <QLine>

#include "custom_exceptions.hpp"

double line_len(QPoint a, QPoint b);

QPointF line_intersection(QLine l1, QLine l2);

QPointF line_intersection(double a1, double b1, double c1,
                          double a2, double b2, double c2);

#endif //LAB_01_POINT_ACTIONS_HPP
