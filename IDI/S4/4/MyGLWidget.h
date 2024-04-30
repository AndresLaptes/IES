// MyGLWidget.h
#include "BL2GLWidget.h"
#include "model.h"
#include <cmath>

#define _USE_MATH_DEFINES

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();

  protected:
    virtual void carregaShaders();
    virtual void projectTransform();
    virtual void paintGL();
    virtual void viewTransform();
    virtual void ini_camera();
    virtual void creaBuffers();
    virtual void initializeGL();
   
    int size_model;
    GLuint VAO_pat;
    GLuint projLoc;
    GLuint viewLoc;
    //paràmetres perspectiva
    float FOV;
    float ratio;
    float znear;
    float zfar;
    //paràmetres vista
    glm::vec3 OBS;
    glm::vec3 VRP;
    glm::vec3 UP;

  private:
    int printOglError(const char file[], int line, const char func[]);
};
