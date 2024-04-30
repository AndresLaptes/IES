TEMPLATE    = app
QT         += opengl 

INCLUDEPATH +=  /usr/include/glm \
                /home2/users/alumnes/1289953/Documentos/IDI/S4/4/Model/

FORMS += MyForm.ui

HEADERS += MyForm.h BL2GLWidget.h MyGLWidget.h

SOURCES += main.cpp MyForm.cpp \
        BL2GLWidget.cpp MyGLWidget.cpp \
        /home2/users/alumnes/1289953/Documentos/IDI/S4/4/Model/model.cpp

