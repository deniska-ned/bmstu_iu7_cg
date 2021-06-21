#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qSetMessagePattern("[%{type}] %{appname} (%{file}:%{line} %{function}) - %{message}");

    MainWindow w;
    w.show();

    return QApplication::exec();
}
