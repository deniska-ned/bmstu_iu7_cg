#include <QPoint>

#include "gtest/gtest.h"

#include "mainwindow.hpp"

TEST(is_new_incenter_better, rect_center_and_new_incenter_the_same_tns)
{
    QPoint rect_point(10, 10);
    QPoint old_incenter(20, 20);
    QPoint new_incenter(10, 10);
    bool is_triangle_selected = false;
    ASSERT_FALSE(MainWindow::incenter_cmp(old_incenter, new_incenter,
                                          rect_point, is_triangle_selected));
}

TEST(is_new_incenter_better, rect_center_and_new_incenter_the_same_ts)
{
    QPoint rect_point(10, 10);
    QPoint old_incenter(20, 20);
    QPoint new_incenter(10, 10);
    bool is_triangle_selected = true;
    ASSERT_FALSE(MainWindow::incenter_cmp(old_incenter, new_incenter,
                                          rect_point, is_triangle_selected));
}

TEST(is_new_incenter_better, rect_center_and_new_incenter_in_the_line)
{
    QPoint rect_point(10, 10);
    QPoint old_incenter(20, 20);
    QPoint new_incenter(10, 20);
    bool is_triangle_selected = false;
    ASSERT_TRUE(MainWindow::incenter_cmp(old_incenter, new_incenter,
                                         rect_point, is_triangle_selected));
}

TEST(is_new_incenter_better, rect_center_and_new_incenter_in_the_line_old)
{
    QPoint rect_point(10, 10);
    QPoint old_incenter(10, 20);
    QPoint new_incenter(20, 20);
    bool is_triangle_selected = true;
    ASSERT_TRUE(MainWindow::incenter_cmp(old_incenter, new_incenter,
                                         rect_point, is_triangle_selected));
}

TEST(is_new_incenter_better, true_tns)
{
    QPoint rect_point(10, 10);
    QPoint old_incenter(20, 20);
    QPoint new_incenter(30, 15);
    bool is_triangle_selected = false;
    ASSERT_TRUE(MainWindow::incenter_cmp(old_incenter, new_incenter,
                                         rect_point, is_triangle_selected));
}

TEST(is_new_incenter_better, true_ts)
{
    QPoint rect_point(10, 10);
    QPoint old_incenter(20, 20);
    QPoint new_incenter(30, 15);
    bool is_triangle_selected = true;
    ASSERT_TRUE(MainWindow::incenter_cmp(old_incenter, new_incenter,
                                         rect_point, is_triangle_selected));
}
