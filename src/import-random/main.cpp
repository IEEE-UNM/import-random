#include <iostream>
#include <QApplication>
#include "SpinnerWindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    SpinnerWindow window(nullptr);
    window.show();

    return app.exec();
}
