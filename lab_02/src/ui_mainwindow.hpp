/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_task;
    QAction *action_about;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QChartView *chart_view;
    QVBoxLayout *verticalLayout;
    QGroupBox *gb_move;
    QGridLayout *gridLayout;
    QLabel *l_mov_dx;
    QPushButton *pb_move;
    QDoubleSpinBox *dsb_mov_dy;
    QLabel *l_mov_dy;
    QDoubleSpinBox *dsb_mov_dx;
    QGroupBox *gb_scale;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *dsb_sca_central_y;
    QDoubleSpinBox *dsb_sca_kx;
    QLabel *l_sca_cental;
    QDoubleSpinBox *dsb_sca_ky;
    QPushButton *pb_scale;
    QLabel *l_sca_kx;
    QLabel *l_sca_ky;
    QDoubleSpinBox *dsb_sca_central_x;
    QGroupBox *gb_rotate;
    QGridLayout *gridLayout_3;
    QLabel *l_rot_cental;
    QLabel *l_rot_angle;
    QPushButton *pb_rotate;
    QDoubleSpinBox *dsb_rot_central_x;
    QDoubleSpinBox *dsb_rot_angle;
    QDoubleSpinBox *dsb_rot_central_y;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *hl_forward_back_pb;
    QPushButton *pb_back;
    QPushButton *pb_forward;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1201, 900);
        action_task = new QAction(MainWindow);
        action_task->setObjectName(QString::fromUtf8("action_task"));
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QString::fromUtf8("action_about"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        chart_view = new QChartView(centralwidget);
        chart_view->setObjectName(QString::fromUtf8("chart_view"));

        horizontalLayout->addWidget(chart_view);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gb_move = new QGroupBox(centralwidget);
        gb_move->setObjectName(QString::fromUtf8("gb_move"));
        gridLayout = new QGridLayout(gb_move);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        l_mov_dx = new QLabel(gb_move);
        l_mov_dx->setObjectName(QString::fromUtf8("l_mov_dx"));

        gridLayout->addWidget(l_mov_dx, 0, 0, 1, 1);

        pb_move = new QPushButton(gb_move);
        pb_move->setObjectName(QString::fromUtf8("pb_move"));

        gridLayout->addWidget(pb_move, 2, 0, 1, 3);

        dsb_mov_dy = new QDoubleSpinBox(gb_move);
        dsb_mov_dy->setObjectName(QString::fromUtf8("dsb_mov_dy"));
        dsb_mov_dy->setMinimum(-1000.000000000000000);
        dsb_mov_dy->setMaximum(1000.000000000000000);
        dsb_mov_dy->setValue(15.000000000000000);

        gridLayout->addWidget(dsb_mov_dy, 1, 1, 1, 2);

        l_mov_dy = new QLabel(gb_move);
        l_mov_dy->setObjectName(QString::fromUtf8("l_mov_dy"));

        gridLayout->addWidget(l_mov_dy, 1, 0, 1, 1);

        dsb_mov_dx = new QDoubleSpinBox(gb_move);
        dsb_mov_dx->setObjectName(QString::fromUtf8("dsb_mov_dx"));
        dsb_mov_dx->setMinimum(-1000.000000000000000);
        dsb_mov_dx->setMaximum(1000.000000000000000);
        dsb_mov_dx->setValue(10.000000000000000);

        gridLayout->addWidget(dsb_mov_dx, 0, 1, 1, 2);


        verticalLayout->addWidget(gb_move);

        gb_scale = new QGroupBox(centralwidget);
        gb_scale->setObjectName(QString::fromUtf8("gb_scale"));
        gridLayout_2 = new QGridLayout(gb_scale);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        dsb_sca_central_y = new QDoubleSpinBox(gb_scale);
        dsb_sca_central_y->setObjectName(QString::fromUtf8("dsb_sca_central_y"));
        dsb_sca_central_y->setMinimum(-1000.000000000000000);
        dsb_sca_central_y->setMaximum(1000.000000000000000);

        gridLayout_2->addWidget(dsb_sca_central_y, 0, 2, 1, 1);

        dsb_sca_kx = new QDoubleSpinBox(gb_scale);
        dsb_sca_kx->setObjectName(QString::fromUtf8("dsb_sca_kx"));
        dsb_sca_kx->setMinimum(-1000.000000000000000);
        dsb_sca_kx->setMaximum(1000.000000000000000);
        dsb_sca_kx->setSingleStep(0.500000000000000);
        dsb_sca_kx->setValue(1.000000000000000);

        gridLayout_2->addWidget(dsb_sca_kx, 1, 1, 1, 2);

        l_sca_cental = new QLabel(gb_scale);
        l_sca_cental->setObjectName(QString::fromUtf8("l_sca_cental"));

        gridLayout_2->addWidget(l_sca_cental, 0, 0, 1, 1);

        dsb_sca_ky = new QDoubleSpinBox(gb_scale);
        dsb_sca_ky->setObjectName(QString::fromUtf8("dsb_sca_ky"));
        dsb_sca_ky->setMinimum(-1000.000000000000000);
        dsb_sca_ky->setMaximum(1000.000000000000000);
        dsb_sca_ky->setSingleStep(0.500000000000000);
        dsb_sca_ky->setValue(1.000000000000000);

        gridLayout_2->addWidget(dsb_sca_ky, 2, 1, 1, 2);

        pb_scale = new QPushButton(gb_scale);
        pb_scale->setObjectName(QString::fromUtf8("pb_scale"));

        gridLayout_2->addWidget(pb_scale, 3, 0, 1, 3);

        l_sca_kx = new QLabel(gb_scale);
        l_sca_kx->setObjectName(QString::fromUtf8("l_sca_kx"));

        gridLayout_2->addWidget(l_sca_kx, 1, 0, 1, 1);

        l_sca_ky = new QLabel(gb_scale);
        l_sca_ky->setObjectName(QString::fromUtf8("l_sca_ky"));

        gridLayout_2->addWidget(l_sca_ky, 2, 0, 1, 1);

        dsb_sca_central_x = new QDoubleSpinBox(gb_scale);
        dsb_sca_central_x->setObjectName(QString::fromUtf8("dsb_sca_central_x"));
        dsb_sca_central_x->setMinimum(-1000.000000000000000);
        dsb_sca_central_x->setMaximum(1000.000000000000000);
        dsb_sca_central_x->setValue(0.000000000000000);

        gridLayout_2->addWidget(dsb_sca_central_x, 0, 1, 1, 1);


        verticalLayout->addWidget(gb_scale);

        gb_rotate = new QGroupBox(centralwidget);
        gb_rotate->setObjectName(QString::fromUtf8("gb_rotate"));
        gridLayout_3 = new QGridLayout(gb_rotate);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        l_rot_cental = new QLabel(gb_rotate);
        l_rot_cental->setObjectName(QString::fromUtf8("l_rot_cental"));

        gridLayout_3->addWidget(l_rot_cental, 0, 0, 1, 1);

        l_rot_angle = new QLabel(gb_rotate);
        l_rot_angle->setObjectName(QString::fromUtf8("l_rot_angle"));

        gridLayout_3->addWidget(l_rot_angle, 1, 0, 1, 1);

        pb_rotate = new QPushButton(gb_rotate);
        pb_rotate->setObjectName(QString::fromUtf8("pb_rotate"));

        gridLayout_3->addWidget(pb_rotate, 2, 0, 1, 3);

        dsb_rot_central_x = new QDoubleSpinBox(gb_rotate);
        dsb_rot_central_x->setObjectName(QString::fromUtf8("dsb_rot_central_x"));
        dsb_rot_central_x->setMinimum(-1000.000000000000000);
        dsb_rot_central_x->setMaximum(1000.000000000000000);

        gridLayout_3->addWidget(dsb_rot_central_x, 0, 1, 1, 1);

        dsb_rot_angle = new QDoubleSpinBox(gb_rotate);
        dsb_rot_angle->setObjectName(QString::fromUtf8("dsb_rot_angle"));
        dsb_rot_angle->setMinimum(-1000.000000000000000);
        dsb_rot_angle->setMaximum(1000.000000000000000);
        dsb_rot_angle->setSingleStep(10.000000000000000);

        gridLayout_3->addWidget(dsb_rot_angle, 1, 1, 1, 2);

        dsb_rot_central_y = new QDoubleSpinBox(gb_rotate);
        dsb_rot_central_y->setObjectName(QString::fromUtf8("dsb_rot_central_y"));
        dsb_rot_central_y->setMinimum(-1000.000000000000000);
        dsb_rot_central_y->setMaximum(1000.000000000000000);

        gridLayout_3->addWidget(dsb_rot_central_y, 0, 2, 1, 1);


        verticalLayout->addWidget(gb_rotate);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        hl_forward_back_pb = new QHBoxLayout();
        hl_forward_back_pb->setObjectName(QString::fromUtf8("hl_forward_back_pb"));
        pb_back = new QPushButton(centralwidget);
        pb_back->setObjectName(QString::fromUtf8("pb_back"));

        hl_forward_back_pb->addWidget(pb_back);

        pb_forward = new QPushButton(centralwidget);
        pb_forward->setObjectName(QString::fromUtf8("pb_forward"));

        hl_forward_back_pb->addWidget(pb_forward);


        verticalLayout->addLayout(hl_forward_back_pb);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1201, 33));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action_task);
        menu->addAction(action_about);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_task->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\320\273\320\276\320\262\320\270\320\265", nullptr));
        action_about->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\270", nullptr));
        gb_move->setTitle(QString());
        l_mov_dx->setText(QCoreApplication::translate("MainWindow", "dx", nullptr));
        pb_move->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        l_mov_dy->setText(QCoreApplication::translate("MainWindow", "dy", nullptr));
        gb_scale->setTitle(QString());
        l_sca_cental->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200", nullptr));
        pb_scale->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        l_sca_kx->setText(QCoreApplication::translate("MainWindow", "x. \320\272\320\276\321\215\321\204.", nullptr));
        l_sca_ky->setText(QCoreApplication::translate("MainWindow", "y. \320\272\320\276\321\215\321\204.", nullptr));
        gb_rotate->setTitle(QString());
        l_rot_cental->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200", nullptr));
        l_rot_angle->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 (\302\260)", nullptr));
        pb_rotate->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        pb_back->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        pb_forward->setText(QCoreApplication::translate("MainWindow", "\320\222\320\277\320\265\321\200\320\265\320\264", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
