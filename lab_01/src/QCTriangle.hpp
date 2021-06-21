#ifndef LAB_01_QCTRIANGLE_HPP
#define LAB_01_QCTRIANGLE_HPP

#include <array>

#include <QPoint>
#include <QPainter>

class QCTriangle
{
public:
    std::array<QPoint, 3> nodes;

public:
    QCTriangle() = default;
    QCTriangle(QPoint a, QPoint b, QPoint c);
    QCTriangle(const QCTriangle& other);
    QCTriangle& operator=(const QCTriangle& other);
    void swap(QCTriangle& other);

    void draw(QPainter &painter);
    static bool is_triangle(QPoint a, QPoint b, QPoint c);
    QPointF get_incenter();
    void draw_bisection(QPainter &painter, int node_index);
    void draw_bisections(QPainter &painter);
};


#endif //LAB_01_QCTRIANGLE_HPP
