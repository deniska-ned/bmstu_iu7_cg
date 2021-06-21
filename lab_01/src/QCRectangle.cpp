#include "QCRectangle.hpp"

#include <cmath>

#include "point_transformation.hpp"
#include "point_actions.hpp"

// private

QPointF QCRectangle::get_2nd_rectangle_point() const
{
    return line_intersection(
            cos(angle), sin(angle),
            -cos(angle) * nodes[0].x() - sin(angle) * nodes[0].y(),
            -sin(angle), cos(angle),
            sin(angle) * nodes[2].x() - cos(angle) * nodes[2].y()
    );
}

QPointF QCRectangle::get_4th_parallelogram_point() const
{
    return {nodes[2].x() - (nodes[1].x() - nodes[0].x()),
            nodes[2].y() - (nodes[1].y() - nodes[0].y())};
}

// protected

// public

QCRectangle::QCRectangle(const QPoint &a, const QPoint &c, const double angle)
        : angle(angle)
{
    nodes[0] = a;
    nodes[2] = c;
    nodes[1] = get_2nd_rectangle_point();
    nodes[3] = get_4th_parallelogram_point();

    if (nodes[1] == nodes[0] || nodes[1] == nodes[2])
    {
        throw incorrect_rect_error();
    }
}

QCRectangle::QCRectangle(const QCRectangle &other)
{
    this->nodes = other.nodes;
    this->angle = other.angle;
}

QCRectangle& QCRectangle::operator=(const QCRectangle &other)
{
    if (this != &other)
    {
        QCRectangle(other).swap(*this);
    }

    return *this;
}

void QCRectangle::swap(QCRectangle &other)
{
    if (this != &other)
    {
        std::swap(this->nodes, other.nodes);
        std::swap(this->angle, other.angle);
    }
}

const std::array<QPointF, 4> & QCRectangle::get_nodes() const
{
    return nodes;
}

double QCRectangle::get_angle() const
{
    return angle;
}

QPointF QCRectangle::get_center_point() const
{
    return {(nodes[0].x() + nodes[2].x()) / 2.0,
            (nodes[0].y() + nodes[2].y()) / 2.0};
}

bool QCRectangle::is_rectangle(QPoint a, QPoint b, QPoint c)
{
    int scalar_mult = (a.x() - b.x()) * (c.x() - b.x())
                      + (a.y() - b.y()) * (c.y() - b.y());

    qDebug("scalar_mult == %d", scalar_mult);
    return 0 == scalar_mult;
}

void QCRectangle::draw(QPainter &painter) const
{
    for (unsigned i = 0; i < RECT_POINT_COUNT; ++i)
    {
        painter.drawLine(nodes[i % RECT_POINT_COUNT],
                         nodes[(i + 1) % RECT_POINT_COUNT]);
    }
}
