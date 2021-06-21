#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qSetMessagePattern(
            "[%{type}] %{appname} (%{file}:%{line} %{function}) - %{message}");

    MainWindow w;
    w.show();

    return a.exec();
}
