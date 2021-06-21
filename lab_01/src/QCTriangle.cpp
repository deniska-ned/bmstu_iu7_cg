#include <cmath>

#include <QPainter>

#include "QCTriangle.hpp"
#include "point_actions.hpp"

QCTriangle::QCTriangle(QPoint a, QPoint b, QPoint c)
{
    if (!is_triangle(a, b, c))
    {
        throw std::invalid_argument("Invalid points for triangle");
    }
    nodes = {a, b, c};
}

QCTriangle::QCTriangle(const QCTriangle &other)
{
    this->nodes = other.nodes;
}

QCTriangle &QCTriangle::operator=(const QCTriangle &other)
{
    if (this != &other)
    {
        QCTriangle(other).swap(*this);
    }

    return *this;
}

void QCTriangle::swap(QCTriangle &other)
{
    std::swap(this->nodes, other.nodes);
}

void QCTriangle::draw(QPainter &painter)
{
    painter.drawLine(nodes[0], nodes[1]);
    painter.drawLine(nodes[1], nodes[2]);
    painter.drawLine(nodes[2], nodes[0]);
}

bool QCTriangle::is_triangle(QPoint a, QPoint b, QPoint c)
{
    int area = a.x() * (b.y() - c.y())
               + b.x() * (c.y() - a.y())
               + c.x() * (a.y() - b.y());

    return 0 != area;
}

QPointF QCTriangle::get_incenter()
{
    QPoint a = nodes[0];
    QPoint b = nodes[1];
    QPoint c = nodes[2];

    double ab = line_len(a, b);
    double bc = line_len(b, c);
    double ac = line_len(a, c);

    double x = (ab * c.x() + bc * a.x() + ac * b.x()) / (ab + bc + ac);
    double y = (ab * c.y() + bc * a.y() + ac * b.y()) / (ab + bc + ac);

    return {x, y};
}

void QCTriangle::draw_bisection(QPainter &painter, int node_index)
{
    QPointF incenter = get_incenter();
    QPointF bs_intersection = line_intersection(
            QLine(nodes[node_index], incenter.toPoint()),
            QLine(nodes[(node_index + 1) % 3], nodes[(node_index + 2) % 3]));
    painter.drawLine(nodes[node_index], bs_intersection.toPoint());
}

void QCTriangle::draw_bisections(QPainter &painter)
{
    for (int i = 0; i < 3; ++i)
        draw_bisection(painter, i);
}
