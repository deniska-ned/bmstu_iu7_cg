#include "qt_picture_provider.hpp"

#include <iostream>
#include "picture/picture.hpp"

void qt_pic_init()
{
    pic_init();
}

void qt_pic_destroy()
{
    pic_destroy();
}

void qt_pic_move(double dx, double dy)
{
    pic_move(dx, dy);
}

void qt_pic_scale(QPointF center, double kx, double ky)
{
    pic_scale({center.x(), center.y()}, kx, ky);
}

void qt_pic_rotate(QPointF point, double angle)
{
    pic_rotate({point.x(), point.y()}, angle);
}

struct house qt_pic_get()
{
    return pic_get();
}

QChart * qt_get_chart()
{
    const struct house house = qt_pic_get();

    QLineSeries *roof_series = new QLineSeries();
    for (unsigned i = 0; i < TETRAGON_NODES_COUNT + 1; ++i)
    {
        roof_series->append(house.roof.nodes[i % TETRAGON_NODES_COUNT].x,
                           house.roof.nodes[i % TETRAGON_NODES_COUNT].y);
    }

    QLineSeries *walls_series = new QLineSeries();
    for (unsigned i = 0; i < TETRAGON_NODES_COUNT + 1; ++i)
    {
        walls_series->append(house.walls.nodes[i % TETRAGON_NODES_COUNT].x,
                            house.walls.nodes[i % TETRAGON_NODES_COUNT].y);
    }

    QLineSeries *door_series = new QLineSeries();
    door_series->append(house.door.nodes[3].x, house.door.nodes[3].y);
    door_series->append(house.door.nodes[1].x, house.door.nodes[1].y);
    door_series->append(house.door.nodes[2].x, house.door.nodes[2].y);
    door_series->append(house.door.nodes[0].x, house.door.nodes[0].y);
    for (unsigned i = 0; i < TETRAGON_NODES_COUNT + 1; ++i)
    {
        door_series->append(house.door.nodes[i % TETRAGON_NODES_COUNT].x,
                             house.door.nodes[i % TETRAGON_NODES_COUNT].y);
    }

    QLineSeries *handle_series = new QLineSeries();
    for (unsigned i = 0; i < TETRAGON_NODES_COUNT + 1; ++i)
    {
        handle_series->append(house.handle.nodes[i % TETRAGON_NODES_COUNT].x,
                            house.handle.nodes[i % TETRAGON_NODES_COUNT].y);
    }

    QLineSeries *circle_series = new QLineSeries();
    for (unsigned i = 0; i < RING_POINTS_COUNT + 1; ++i)
    {
        circle_series->append(house.window.nodes[i % RING_POINTS_COUNT].x,
                              house.window.nodes[i % RING_POINTS_COUNT].y);
    }

    QLineSeries *grating_hor_series = new QLineSeries();
    grating_hor_series->append(house.grating_hor.nodes[0].x,
                               house.grating_hor.nodes[0].y);
    grating_hor_series->append(house.grating_hor.nodes[1].x,
                               house.grating_hor.nodes[1].y);
    QLineSeries *grating_ver_series = new QLineSeries();
    grating_ver_series->append(house.grating_ver.nodes[0].x,
                               house.grating_ver.nodes[0].y);
    grating_ver_series->append(house.grating_ver.nodes[1].x,
                               house.grating_ver.nodes[1].y);

    QChart *chart = new QChart();

    chart->addSeries(grating_hor_series);
    chart->addSeries(grating_ver_series);
    chart->addSeries(circle_series);
    chart->addSeries(handle_series);
    chart->addSeries(door_series);
    chart->addSeries(walls_series);
    chart->addSeries(roof_series);

    chart->legend()->hide();
    chart->setTitle("Прекрасный дивный дом");

    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).back()->setRange(-30, 30);
    chart->axes(Qt::Vertical).back()->setRange(-30, 30);

    return chart;
}

bool qt_pic_goto_next()
{
    return pic_goto_next();
}

bool qt_pic_goto_prev()
{
    return pic_goto_prev();
}
