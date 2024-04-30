#include <QApplication>
#include "MyForm.h"
using namespace std;

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    MyForm form;
    form.show();
    return app.exec();
}