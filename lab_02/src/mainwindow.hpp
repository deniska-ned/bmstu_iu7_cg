#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_pb_move_clicked();
    void on_pb_scale_clicked();
    void on_pb_rotate_clicked();
    void on_pb_forward_clicked();
    void on_pb_back_clicked();

    void on_action_about_triggered();
    void on_action_task_triggered();
};
#endif // MAINWINDOW_H
