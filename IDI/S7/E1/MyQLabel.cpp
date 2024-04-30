#include "MyQLabel.h"
#include <QString>
using namespace std;

void MyQLabel::GuardaTexto(QString a) {
    texto_original = a;
}

void MyQLabel::TruncaTexto(int d)  {
    QString text_truncat = texto_original;
    text_truncat.truncate(d);
    setText(text_truncat);
}
