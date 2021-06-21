#ifndef LAB_01_QCRECTANGLE_HPP
#define LAB_01_QCRECTANGLE_HPP

#include <array>
#include <stdexcept>

#include <QPainter>
#include <QPoint>

#include "point_transformation.hpp"

#define RECT_POINT_COUNT                4

class not_rectangle_error: public std::runtime_error
{
public:
    not_rectangle_error()
            : std::runtime_error("Not a rectangle given") {}
};

class QCRectangle
{
private:
    std::array<QPointF, RECT_POINT_COUNT> nodes;

    double angle;
    QPointF get_2nd_rectangle_point() const;
    QPointF get_4th_parallelogram_point() const;

public:
    QCRectangle() = default;
    QCRectangle(const QPoint &a, const QPoint &c, const double angle);
    QCRectangle(const QCRectangle &other);
    QCRectangle& operator=(const QCRectangle &other);
    void swap(QCRectangle &other);

    const std::array<QPointF, 4> & get_nodes() const;
    double get_angle() const;

    QPointF get_center_point() const;
    static bool is_rectangle(QPoint a, QPoint b, QPoint c);
    void draw(QPainter &painter) const;
};


#endif //LAB_01_QCRECTANGLE_HPP
