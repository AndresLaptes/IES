#include <QLabel>
using namespace std;

class MyQLabel:public QLabel {
    Q_OBJECT
    
    public:
        MyQLabel(QWidget *parent);
        QString texto_original;
    public slots:
        void GuardaTexto(const QString a);
        void TruncaTexto(int d);
    signals:
        
};