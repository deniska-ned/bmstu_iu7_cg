#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QTableWidget>

#include "QCRectangle.hpp"
#include "QCTriangle.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

private:
    QCRectangle get_rectangle();
    std::vector<QPoint> get_point_set();
    static QCTriangle get_triangle(const QCRectangle &rectangle,
                                   const std::vector<QPoint> &point_set);

private slots:
    void on_pbGo_clicked();
    void on_sbPointCount_valueChanged(int new_value);
    void on_actionAbout_triggered();
    void on_actionTask_triggered();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    static bool incenter_cmp(QPointF p_old, QPointF p_new, QPointF rect_center,
                             bool is_selected);
    std::vector<QPoint> qtw_to_vector(QTableWidget *table);
};

#endif // MAINWINDOW_HPP
