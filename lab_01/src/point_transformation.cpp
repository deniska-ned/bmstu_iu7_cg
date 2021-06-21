#include <stdexcept>
#include <array>
#include <cmath>

#include "point_transformation.hpp"

point_transformation::point_transformation(int left, int right, int bottom,
                                           int top, int width, int height,
                                           int border)
        : left(left), right(right), bottom(bottom), top(top), width(width),
          height(height), border(border)
{
    check_invalid_argument(this->left, this->right, this->bottom, this->top,
                           this->width, this->height, this->border);
}

point_transformation::point_transformation(
        const std::array<QPointF, 4> &rect_points,
        const std::vector<QPoint> &point_set,
        int width,
        int height, int border)
{
    double x_min, y_min, x_max, y_max;

    x_min = x_max = rect_points[0].x();
    y_min = y_max = rect_points[0].y();

    for (auto point: rect_points)
    {
        x_min = std::min(x_min, point.x());
        x_max = std::max(x_max, point.x());

        y_min = std::min(y_min, point.y());
        y_max = std::max(y_max, point.y());
    }

    for (auto point: point_set)
    {
        x_min = std::min(x_min, (double) point.x());
        x_max = std::max(x_max, (double) point.x());

        y_min = std::min(y_min, (double) point.y());
        y_max = std::max(y_max, (double) point.y());
    }

    this->left = (int) x_min;
    this->right = (int) x_max;

    this->bottom = (int) y_min;
    this->top = (int) y_max;

    this->width = width;
    this->height = height;

    qInfo("Screen: top = %d, bottom = %d, left = %d, right = %d",
          this->top, this->bottom, this->left, this->right);

    this->border = border;

    check_invalid_argument(this->left, this->right, this->bottom, this->top,
                           this->width, this->height, this->border);
}

QPoint point_transformation::point(QPoint src) const {
    double x = src.x() - left;
    double y = src.y() - bottom;

    double x_scale = ((double) width - 2 * border) / (right - left);
    double y_scale = ((double) height - 2 * border) / (top - bottom);

    double gen_scale = std::min(x_scale, y_scale);

    x *= gen_scale;
    y *= gen_scale;

    y = height - y;

    x += border;
    y -= border;

    return {(int) std::lround(x), (int) std::lround(y)};
}

QPointF point_transformation::point(QPointF src) const
{
    double x = src.x() - left;
    double y = src.y() - bottom;

    double x_scale = ((double) width - 2 * border) / (right - left);
    double y_scale = ((double) height - 2 * border) / (top - bottom);

    double gen_scale = std::min(x_scale, y_scale);

    x *= gen_scale;
    y *= gen_scale;

    y = height - y;

    x += border;
    y -= border;

    return {x, y};
}

void
point_transformation::check_invalid_argument(int left, int right, int bottom,
                                             int top, int width, int height,
                                             int border)
{
    if (left >= right)
    {
        throw std::invalid_argument("Left more than right");
    }

    if (bottom >= top)
    {
        throw std::invalid_argument("Bottom more than top");
    }

    if (0 == width)
    {
        throw std::invalid_argument("Zero width");
    }

    if (0 == height)
    {
        throw std::invalid_argument("Zero height");
    }

    if (width <= 2 * border)
    {
        throw std::invalid_argument("No space for picture. OX");
    }

    if (height <= 2 * border)
    {
        throw std::invalid_argument("No space for picture. OY");
    }
}
