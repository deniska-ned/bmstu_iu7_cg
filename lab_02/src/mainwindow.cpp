#include "mainwindow.hpp"
#include "./ui_mainwindow.hpp"
#include "qt_picture_provider.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qt_pic_init();
    ui->chart_view->setChart(qt_get_chart());
}

MainWindow::~MainWindow()
{
    qt_pic_destroy();
    delete ui;
}

void MainWindow::on_pb_move_clicked()
{
    qInfo("pb_move clicked");

    double dx = ui->dsb_mov_dx->value();
    double dy = ui->dsb_mov_dy->value();

    qt_pic_move(dx, dy);

    ui->chart_view->setChart(qt_get_chart());
}

void MainWindow::on_pb_scale_clicked()
{
    qInfo("pb_scale clicked");

    double central_x = ui->dsb_sca_central_x->value();
    double central_y = ui->dsb_sca_central_y->value();

    double kx = ui->dsb_sca_kx->value();
    double ky = ui->dsb_sca_ky->value();

    qt_pic_scale({central_x, central_y}, kx, ky);

    ui->chart_view->setChart(qt_get_chart());
}

void MainWindow::on_pb_rotate_clicked()
{
    qInfo("pb_rotate clicked");

    double central_x = ui->dsb_rot_central_x->value();
    double central_y = ui->dsb_rot_central_y->value();

    double angle =  ui->dsb_rot_angle->value() / 180.0 * M_PI;

    qt_pic_rotate({central_x, central_y}, angle);

    ui->chart_view->setChart(qt_get_chart());
}

void MainWindow::on_pb_forward_clicked() {
    qInfo("pb_forward clicked");

    bool is_shift_done = qt_pic_goto_next();
    qInfo("Pic forward done: %s", is_shift_done ? "true" : "false");

    if (is_shift_done)
    {
        ui->chart_view->setChart(qt_get_chart());
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Невозможно перейти вперед");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
}

void MainWindow::on_pb_back_clicked()
{
    qInfo("pb_back clicked");

    bool is_shift_done = qt_pic_goto_prev();
    qInfo("Pic forward done: %s", is_shift_done ? "true" : "false");

    if (is_shift_done)
    {
        ui->chart_view->setChart(qt_get_chart());
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Невозможно перейти назад");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
}

void MainWindow::on_action_about_triggered()
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

void MainWindow::on_action_task_triggered()
{
    QString msg("Нарисовать исходный рисунок (домик),"
                " осуществить его перенос, масштабирование, поворот.");

    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}
