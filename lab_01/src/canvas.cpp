#include <cmath>

#include <QStyleOption>
#include <QPainter>

#include "canvas.hpp"
#include "point_transformation.hpp"

#define TEXT_WIDTH                      1
#define LINE_WIDTH                      2
#define POINT_WIDTH                     5

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    qDebug("Canvas created %s", "by qDebug");
}

void Canvas::paintEvent(QPaintEvent *paintEvent)
{
    QWidget::paintEvent(paintEvent);

    qInfo("called");

    QStyleOption opt;
    opt.init(this);

    QPainter painter;
    painter.begin(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    if (!is_actual_data)
    {
        qInfo("Func called. Data is not actual. Nothing will be painted");
    }
    else
    {
        qInfo("Func called. Data is actual. Image will be drawn");

        const std::array<QPointF, 4> &rect_nodes = rectangle.get_nodes();
        qDebug("Rect_points: (%.2f;%.2f),(%.2f;%.2f),(%.2f;%.2f),(%.2f;%.2f)",
               rect_nodes[0].x(), rect_nodes[0].y(),
               rect_nodes[1].x(), rect_nodes[1].y(),
               rect_nodes[2].x(), rect_nodes[2].y(),
               rect_nodes[3].x(), rect_nodes[3].y()
        );

        qDebug("Point set [len = %zu]:", pointsTriangle.size());
        for (auto point: pointsTriangle)
        {
            qDebug("(%d; %d)", point.x(), point.y());
        }

        QCRectangle frectangle;
        QCTriangle ftriangle;
        std::vector<QPoint> fpointsTriangle;
        QPointF fincenter;

        int border = 30;
        point_transformation trans = point_transformation(
                rectangle.get_nodes(), pointsTriangle,
                width(), height(), border);

        frectangle = QCRectangle(trans.point(rect_nodes[0]).toPoint(),
                                 trans.point(rect_nodes[2]).toPoint(),
                                 -rectangle.get_angle());

        ftriangle = QCTriangle(trans.point(triangle.nodes[0]),
                               trans.point(triangle.nodes[1]),
                               trans.point(triangle.nodes[2]));

        for (auto point: pointsTriangle)
        {
            fpointsTriangle.push_back(trans.point(point));
        }

        fincenter = trans.point(incenter);

        QPen pen;
        pen.setWidth(LINE_WIDTH);

        pen.setColor(Qt::magenta);
        painter.setPen(pen);
        frectangle.draw(painter);

        pen.setColor(Qt::green);
        painter.setPen(pen);
        ftriangle.draw(painter);

        pen.setColor(Qt::cyan);
        painter.setPen(pen);
        ftriangle.draw_bisections(painter);

        pen.setColor(Qt::gray);
        painter.setPen(pen);
        painter.drawLine(ftriangle.get_incenter(),
                         frectangle.get_center_point());

        pen.setWidth(POINT_WIDTH);
        pen.setColor(Qt::red);
        painter.setPen(pen);
        draw_points(painter, fpointsTriangle);
        painter.drawPoint(fincenter.toPoint());

        pen.setWidth(TEXT_WIDTH);
        pen.setColor(Qt::black);
        painter.setPen(pen);
        draw_coords(painter, fpointsTriangle, pointsTriangle);
    }

    painter.end();
}

void Canvas::draw_points(QPainter &painter, std::vector<QPoint> points)
{
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);
    painter.setPen(pen);

    for (auto point: points)
    {
        painter.drawPoint(point);
    }
}

void Canvas::draw_coords(QPainter &painter, std::vector<QPoint> fpoints,
                         std::vector<QPoint> points)
{
    for (int i = 0; i < fpoints.size(); ++i)
    {
        draw_coord(painter, fpoints[i], points[i], i);
    }
}

void Canvas::draw_coord(QPainter &painter, QPoint fpoint, QPoint point,
                        int point_index)
{
    painter.drawText(
            fpoint.x() + (fpoint.x() < width()  / 2 ? 5: -120),
            fpoint.y() + (fpoint.y() < height() / 2 ? 15: 0),
            QString("x%1 (%2;%3)").arg(point_index + 1).arg(point.x()).arg(point.y()));
}
