/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "canvas.hpp"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTask;
    QAction *actionAbout;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    Canvas *canvas;
    QVBoxLayout *vlConfig;
    QGroupBox *gbPointsRect;
    QGridLayout *gridLayout;
    QLabel *l_p1;
    QSpinBox *sb_p1_x;
    QSpinBox *sb_p1_y;
    QLabel *l_p2;
    QSpinBox *sb_p2_x;
    QSpinBox *sb_p2_y;
    QLabel *l_angle;
    QDoubleSpinBox *dsb_angle;
    QGroupBox *gbPointsSet;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *twPointsSet;
    QSpinBox *sbPointCount;
    QPushButton *pbGo;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(886, 867);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionTask = new QAction(MainWindow);
        actionTask->setObjectName(QString::fromUtf8("actionTask"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        canvas = new Canvas(centralwidget);
        canvas->setObjectName(QString::fromUtf8("canvas"));
        canvas->setMinimumSize(QSize(500, 0));
        canvas->setAutoFillBackground(false);
        canvas->setStyleSheet(QString::fromUtf8("background-color:white;"));

        horizontalLayout->addWidget(canvas);

        vlConfig = new QVBoxLayout();
        vlConfig->setObjectName(QString::fromUtf8("vlConfig"));
        gbPointsRect = new QGroupBox(centralwidget);
        gbPointsRect->setObjectName(QString::fromUtf8("gbPointsRect"));
        gbPointsRect->setMinimumSize(QSize(360, 0));
        gbPointsRect->setMaximumSize(QSize(360, 16777215));
        gridLayout = new QGridLayout(gbPointsRect);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        l_p1 = new QLabel(gbPointsRect);
        l_p1->setObjectName(QString::fromUtf8("l_p1"));

        gridLayout->addWidget(l_p1, 0, 0, 1, 2);

        sb_p1_x = new QSpinBox(gbPointsRect);
        sb_p1_x->setObjectName(QString::fromUtf8("sb_p1_x"));
        sb_p1_x->setMinimum(-2000);
        sb_p1_x->setMaximum(2000);
        sb_p1_x->setValue(0);

        gridLayout->addWidget(sb_p1_x, 1, 0, 1, 1);

        sb_p1_y = new QSpinBox(gbPointsRect);
        sb_p1_y->setObjectName(QString::fromUtf8("sb_p1_y"));

        gridLayout->addWidget(sb_p1_y, 1, 1, 1, 1);

        l_p2 = new QLabel(gbPointsRect);
        l_p2->setObjectName(QString::fromUtf8("l_p2"));

        gridLayout->addWidget(l_p2, 2, 0, 1, 2);

        sb_p2_x = new QSpinBox(gbPointsRect);
        sb_p2_x->setObjectName(QString::fromUtf8("sb_p2_x"));
        sb_p2_x->setMaximum(2000);
        sb_p2_x->setValue(100);

        gridLayout->addWidget(sb_p2_x, 3, 0, 1, 1);

        sb_p2_y = new QSpinBox(gbPointsRect);
        sb_p2_y->setObjectName(QString::fromUtf8("sb_p2_y"));
        sb_p2_y->setMaximum(2000);
        sb_p2_y->setValue(100);

        gridLayout->addWidget(sb_p2_y, 3, 1, 1, 1);

        l_angle = new QLabel(gbPointsRect);
        l_angle->setObjectName(QString::fromUtf8("l_angle"));

        gridLayout->addWidget(l_angle, 4, 0, 1, 2);

        dsb_angle = new QDoubleSpinBox(gbPointsRect);
        dsb_angle->setObjectName(QString::fromUtf8("dsb_angle"));
        dsb_angle->setMinimum(-500.000000000000000);
        dsb_angle->setMaximum(500.990000000000009);

        gridLayout->addWidget(dsb_angle, 5, 0, 1, 2);


        vlConfig->addWidget(gbPointsRect);

        gbPointsSet = new QGroupBox(centralwidget);
        gbPointsSet->setObjectName(QString::fromUtf8("gbPointsSet"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(gbPointsSet->sizePolicy().hasHeightForWidth());
        gbPointsSet->setSizePolicy(sizePolicy1);
        gbPointsSet->setMinimumSize(QSize(360, 0));
        gbPointsSet->setMaximumSize(QSize(360, 16777215));
        verticalLayout_2 = new QVBoxLayout(gbPointsSet);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        twPointsSet = new QTableWidget(gbPointsSet);
        if (twPointsSet->columnCount() < 2)
            twPointsSet->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        twPointsSet->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        twPointsSet->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (twPointsSet->rowCount() < 4)
            twPointsSet->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        twPointsSet->setItem(0, 0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        twPointsSet->setItem(0, 1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        twPointsSet->setItem(1, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        twPointsSet->setItem(1, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        twPointsSet->setItem(2, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        twPointsSet->setItem(2, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        twPointsSet->setItem(3, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        twPointsSet->setItem(3, 1, __qtablewidgetitem9);
        twPointsSet->setObjectName(QString::fromUtf8("twPointsSet"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(twPointsSet->sizePolicy().hasHeightForWidth());
        twPointsSet->setSizePolicy(sizePolicy2);
        twPointsSet->setMinimumSize(QSize(300, 0));
        twPointsSet->setMaximumSize(QSize(500, 16777215));
        twPointsSet->setShowGrid(true);
        twPointsSet->setGridStyle(Qt::SolidLine);
        twPointsSet->setSortingEnabled(false);
        twPointsSet->setRowCount(4);
        twPointsSet->setColumnCount(2);
        twPointsSet->horizontalHeader()->setVisible(true);
        twPointsSet->horizontalHeader()->setCascadingSectionResizes(false);
        twPointsSet->horizontalHeader()->setMinimumSectionSize(120);
        twPointsSet->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        twPointsSet->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(twPointsSet);

        sbPointCount = new QSpinBox(gbPointsSet);
        sbPointCount->setObjectName(QString::fromUtf8("sbPointCount"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sbPointCount->sizePolicy().hasHeightForWidth());
        sbPointCount->setSizePolicy(sizePolicy3);
        sbPointCount->setMinimumSize(QSize(300, 0));
        sbPointCount->setMaximumSize(QSize(500, 16777215));
        sbPointCount->setMinimum(3);
        sbPointCount->setMaximum(20);
        sbPointCount->setValue(4);

        verticalLayout_2->addWidget(sbPointCount);


        vlConfig->addWidget(gbPointsSet);

        pbGo = new QPushButton(centralwidget);
        pbGo->setObjectName(QString::fromUtf8("pbGo"));
        pbGo->setMinimumSize(QSize(360, 0));
        pbGo->setMaximumSize(QSize(360, 16777215));

        vlConfig->addWidget(pbGo);


        horizontalLayout->addLayout(vlConfig);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 886, 33));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionTask);
        menu->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionTask->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\320\273\320\276\320\262\320\270\320\265", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\270", nullptr));
        gbPointsRect->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\202\320\276\321\207\320\265\320\272 \320\277\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\260", nullptr));
        l_p1->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \320\277\320\265\321\200\320\262\320\276\320\271 \321\202\320\276\321\207\320\272\320\270", nullptr));
        l_p2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \320\262\321\202\320\276\321\200\320\276\320\271 \321\202\320\276\321\207\320\272\320\270", nullptr));
        l_angle->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273", nullptr));
        gbPointsSet->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\202\320\276\321\207\320\265\320\272 \321\202\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\276\320\262", nullptr));
        QTableWidgetItem *___qtablewidgetitem = twPointsSet->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = twPointsSet->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));

        const bool __sortingEnabled = twPointsSet->isSortingEnabled();
        twPointsSet->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem2 = twPointsSet->item(0, 0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = twPointsSet->item(0, 1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = twPointsSet->item(1, 0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "150", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = twPointsSet->item(1, 1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = twPointsSet->item(2, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = twPointsSet->item(2, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "150", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = twPointsSet->item(3, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = twPointsSet->item(3, 1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        twPointsSet->setSortingEnabled(__sortingEnabled);

        pbGo->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
