#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <array>
#include <vector>

#include <QPoint>
#include <QWidget>

#include "QCRectangle.hpp"
#include "QCTriangle.hpp"

class Canvas : public QWidget
{
Q_OBJECT

public:
    bool is_actual_data = false;

    QCRectangle rectangle;
    QCTriangle triangle;
    std::vector<QPoint> pointsTriangle;
    QPointF incenter;

public:
    explicit Canvas(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *paintEvent) override;

private:
    void draw_points(QPainter &painter, std::vector<QPoint> points);
    void draw_coords(QPainter &painter, std::vector<QPoint> fpoints,
                     std::vector<QPoint> points);
    void draw_coord(QPainter &painter, QPoint fpoint, QPoint point,
                    int point_index);
};

#endif // CANVAS_HPP
