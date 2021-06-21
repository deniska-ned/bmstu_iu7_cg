#include "mainwindow.hpp"
#include "ui_mainwindow.hpp"

#include <cassert>
#include <cmath>
#include <vector>

#include <QMessageBox>

#include "custom_exceptions.hpp"
#include "QCRectangle.hpp"

#define DBL_EQ_EPS                      1e-5

#define CRITICAL_MB(MESSAGE) \
do {\
QMessageBox msgBox; \
msgBox.setText(MESSAGE); \
msgBox.setIcon(QMessageBox::Critical); \
msgBox.exec(); \
} while (false);
#define MSG_TABLE_RECT                  "Таблица точек прямоугольника\n"
#define MSG_TABLE_TRI                   "Таблица точек треугольников\n"
#define MSG_ROW_COL                     "Строка:  %1\nСтолбец: %2\n"
#define MSG_EMPTY                       "Пустая ячейка\n"
#define MSG_NAN                         "Не целое число в ячейке"

QCRectangle MainWindow::get_rectangle()
{
    int x1 = ui->sb_p1_x->value();
    int y1 = ui->sb_p1_y->value();
    int x2 = ui->sb_p2_x->value();
    int y2 = ui->sb_p2_y->value();

    double angle = ui->dsb_angle->value() / 180 * M_PI;

    return QCRectangle(QPoint(x1, y1), QPoint(x2, y2), angle);
}

std::vector<QPoint> MainWindow::get_point_set()
{
    return qtw_to_vector(ui->twPointsSet);
}

QCTriangle MainWindow::get_triangle(const QCRectangle &rectangle,
                                    const std::vector<QPoint> &point_set)
{
    QPointF rect_center = rectangle.get_center_point();

    QCTriangle triangle, triangle_tmp;
    QPointF incenter, incenter_tmp;
    bool is_selected = false;

    for (size_t i_p1 = 0; i_p1 < point_set.size(); ++i_p1)
    {
        for (size_t i_p2 = i_p1 + 1; i_p2 < point_set.size(); ++i_p2)
        {
            for (size_t i_p3 = i_p2 + 1; i_p3 < point_set.size(); ++i_p3)
            {
                try
                {
                    triangle_tmp = QCTriangle(point_set[i_p1],
                                              point_set[i_p2],
                                              point_set[i_p3]);
                }
                catch (std::invalid_argument &e)
                {
                    qDebug("Triangle(%zu,%zu,%zu): (%d;%d);(%d;%d);(%d;%d) does not exist;",
                           i_p1, i_p2, i_p3,
                           point_set[i_p1].x(),
                           point_set[i_p1].y(),
                           point_set[i_p2].x(),
                           point_set[i_p2].y(),
                           point_set[i_p3].x(),
                           point_set[i_p3].y());
                    continue;
                }

                qDebug("Triangle(%zu,%zu,%zu): (%d;%d);(%d;%d);(%d;%d);",
                       i_p1, i_p2, i_p3,
                       triangle_tmp.nodes.at(0).x(),
                       triangle_tmp.nodes.at(0).y(),
                       triangle_tmp.nodes.at(1).x(),
                       triangle_tmp.nodes.at(1).y(),
                       triangle_tmp.nodes.at(2).x(),
                       triangle_tmp.nodes.at(2).y()
                );

                incenter_tmp = triangle_tmp.get_incenter();

                if (incenter_cmp(incenter, incenter_tmp, rect_center,
                                 is_selected))
                {
                    if (is_selected)
                    {
                        qDebug("New triangle better; incenter_new = (%.2f, %.2f); incenter_old = (%.2f, %.2f)",
                               incenter_tmp.x(), incenter_tmp.y(),
                               incenter.x(), incenter.y());
                    }
                    else
                    {
                        qDebug("New triangle better; incenter_new = (%.2f, %.2f); incenter_old is not inited",
                               incenter_tmp.x(), incenter_tmp.y());
                    }
                    is_selected = true;

                    triangle = triangle_tmp;
                    incenter = incenter_tmp;
                }
                else
                {
                    qDebug("Old triangle better; incenter_new = (%.2f, %.2f); incenter_old = (%.2f, %.2f)",
                           incenter_tmp.x(), incenter_tmp.y(),
                           incenter.x(), incenter.y());
                }
            }
        }
    }

    if (!is_selected)
    {
        throw no_suitable_triangle_error();
    }
    return triangle;
}

void MainWindow::on_pbGo_clicked()
{
    QCRectangle rectangle;
    std::vector<QPoint> point_set;
    QCTriangle triangle;

    try
    {
        rectangle = get_rectangle();
    }
    catch (incorrect_rect_error &e)
    {
        qDebug("Incorrect rectangle data");

        ui->canvas->is_actual_data = false;
        ui->canvas->repaint();

        QString msg = QString("Прямоугольник вырождается в прямую");

        CRITICAL_MB(msg);

        return;
    }

    const std::array<QPointF, 4> &rect_nodes = rectangle.get_nodes();
    qDebug("Rect_points: (%.2f;%.2f),(%.2f;%.2f),(%.2f;%.2f),(%.2f;%.2f)",
           rect_nodes[0].x(), rect_nodes[0].y(),
           rect_nodes[1].x(), rect_nodes[1].y(),
           rect_nodes[2].x(), rect_nodes[2].y(),
           rect_nodes[3].x(), rect_nodes[3].y()
    );

    try
    {
        point_set = get_point_set();
        triangle = get_triangle(rectangle, point_set);
    }
    catch (qtablewidget_item_empty_error &e)
    {
        qCritical("Rectangle points table; %s; [%d][%d]",
                  e.what(), e.col_i, e.row_i);

        QString msg = QString(MSG_TABLE_TRI MSG_ROW_COL MSG_EMPTY).arg(
                QString::number(e.row_i + 1), QString::number(e.col_i + 1));

        CRITICAL_MB(msg);

        ui->canvas->is_actual_data = false;
        ui->canvas->repaint();

        return;
    }
    catch (qtablewidget_invalid_argument_error &e)
    {
        qCritical("Rectangle points table; %s; [%d][%d]",
                  e.what(), e.col_i, e.row_i);

        QString msg = QString(MSG_TABLE_TRI MSG_ROW_COL MSG_NAN).arg(
                QString::number(e.row_i + 1), QString::number(e.col_i + 1));

        CRITICAL_MB(msg);

        ui->canvas->is_actual_data = false;
        ui->canvas->repaint();

        return;
    }
    catch (no_suitable_triangle_error &e)
    {
        qCritical("%s", e.what());

        QString msg("На данных точках невозможно построить "
                    "необходимый треугольник");

        CRITICAL_MB(msg);

        ui->canvas->is_actual_data = false;
        ui->canvas->repaint();

        return;
    }

    qDebug("Triangle: (%d;%d),(%d;%d),(%d;%d)",
           triangle.nodes[0].x(), triangle.nodes[0].y(),
           triangle.nodes[1].x(), triangle.nodes[1].y(),
           triangle.nodes[2].x(), triangle.nodes[2].y()
           );

    ui->canvas->is_actual_data = true;

    ui->canvas->rectangle = rectangle;
    ui->canvas->triangle = triangle;
    ui->canvas->pointsTriangle = point_set;
    ui->canvas->incenter = triangle.get_incenter();

    ui->canvas->repaint();

    QString msg = QString("Треугольник построен на точках с координатами:\n"
                          "(%1;%2), (%3;%4), (%5;%6)")
            .arg(triangle.nodes[0].x())
            .arg(triangle.nodes[0].y())
            .arg(triangle.nodes[1].x())
            .arg(triangle.nodes[1].y())
            .arg(triangle.nodes[2].x())
            .arg(triangle.nodes[2].y());

    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

void MainWindow::on_sbPointCount_valueChanged(int new_value)
{
    ui->twPointsSet->setRowCount(new_value);
}

void MainWindow::on_actionAbout_triggered()
{
    QString msg("МГТУ им. Н.Э.Баумана\n"
                "ИУ7-43Б 2019-2023\n"
                "Компьютерная графика\n"
                "Лабораторная работа №1\n"
                "Автор: Недолужоко Денис");

    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

void MainWindow::on_actionTask_triggered()
{
    QString msg("На плоскости задан прямоугольник"
                " (точками диагонали и углом) и множество точек."
                " Найти такой треугольник с вершинами в точках множества,"
                " для которого прямая, соединящая центр прямоугольника и точку"
                " пересечения биссектрис треугольника образует минимальный"
                " угол с осью абсцесс.\nСделать в графическом режиме вывод"
                " изображния.");

    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::incenter_cmp(QPointF p_old, QPointF p_new,
                              QPointF rect_center, bool is_selected)
{
    if (p_new == rect_center)
    {
        qDebug("false; p_new == rect_center");
        return false;
    }

    if (!is_selected)
    {
        qDebug("true; old point is not selected");
        return true;
    }

    if (fabs(p_new.x() - rect_center.x()) < DBL_EQ_EPS)
    {
        qDebug("false; new_point_x is the same to rect center");
        return false;
    }

    if (fabs(p_old.x() - rect_center.x()) < DBL_EQ_EPS)
    {
        qDebug("true; old_point_x is the same to rect center");
        return true;
    }

    double dx_old = fabs(p_old.x() - rect_center.x());
    double dy_old = fabs(p_old.y() - rect_center.y());

    double dx_new = fabs(p_new.x() - rect_center.x());
    double dy_new = fabs(p_new.y() - rect_center.y());

    double k_old = (double) dy_old / dx_old;
    double k_new = (double) dy_new / dx_new;

    if (k_new < k_old)
    {
        qDebug("true; k_old == %lf; k_new == %lf;", k_old, k_new);
        return true;
    }

    qDebug("false; k_old == %lf; k_new == %lf;", k_old, k_new);
    return false;
}

#define COL_COUNT 2
std::vector<QPoint> MainWindow::qtw_to_vector(QTableWidget *table)
{
    assert(2 == table->columnCount());

    int row_count = table->rowCount();

    std::vector<QPoint> v;

    v.resize((size_t) row_count);

    for (int point_i = 0; point_i < row_count; ++point_i)
    {
        int point_coord[COL_COUNT];
        for (int col_i = 0; col_i < COL_COUNT; ++col_i)
        {
            QTableWidgetItem *table_item = table->item(point_i, col_i);

            if (nullptr == table_item)
            {
                throw qtablewidget_item_empty_error(point_i, col_i);
            }

            bool is_number = false;
            int number = table_item->text().toInt(&is_number, 10);
            if (!is_number)
            {
                throw qtablewidget_invalid_argument_error(point_i, col_i);
            }

            point_coord[col_i] = number;
        }
        v[point_i] = QPoint(point_coord[0], point_coord[1]);
    }

    return v;
}
#undef COL_COUNT

#undef CRITICAL_MB
#undef MSG_TABLE_RECT
#undef MSG_TABLE_TRI
#undef MSG_ROW_COL
#undef MSG_EMPTY
#undef MSG_NAN
