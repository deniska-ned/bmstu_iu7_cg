#ifndef LAB_01_POINT_TRANSFORMATION_HPP
#define LAB_01_POINT_TRANSFORMATION_HPP

#include <vector>
#include <array>

#include <QPoint>

class point_transformation
{
public:
    int left;
    int right;
    int top;
    int bottom;
    int width;
    int height;
    int border;

    point_transformation(int left, int right, int bottom,
                         int top, int width, int height,
                         int border);

    point_transformation(const std::array<QPointF, 4> &rect_points,
                         const std::vector<QPoint> &point_set, int width,
                         int height, int border);


    QPoint point(QPoint src) const;
    QPointF point(QPointF src) const;

private:
    static void check_invalid_argument(int left, int right, int bottom,
                                int top, int width, int height,
                                int border);
};

#endif //LAB_01_POINT_TRANSFORMATION_HPP
