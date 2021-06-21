#ifndef LAB_02_QT_PICTURE_PROVIDER_HPP
#define LAB_02_QT_PICTURE_PROVIDER_HPP

#include <QPoint>
#include <QtCharts>

void qt_pic_init();
void qt_pic_destroy();
void qt_pic_move(double dx, double dy);
void qt_pic_scale(QPointF center, double kx, double ky);
void qt_pic_rotate(QPointF point, double angle);
struct house qt_pic_get();
QChart * qt_get_chart();

bool qt_pic_goto_next();
bool qt_pic_goto_prev();

#endif //LAB_02_QT_PICTURE_PROVIDER_HPP
