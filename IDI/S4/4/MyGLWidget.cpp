// MyGLWidget.cpp
#include "MyGLWidget.h"
#include "model.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

int MyGLWidget::printOglError(const char file[], int line, const char func[]) 
{
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    const char * error = 0;
    switch (glErr)
    {
        case 0x0500:
            error = "GL_INVALID_ENUM";
            break;
        case 0x501:
            error = "GL_INVALID_VALUE";
            break;
        case 0x502: 
            error = "GL_INVALID_OPERATION";
            break;
        case 0x503:
            error = "GL_STACK_OVERFLOW";
            break;
        case 0x504:
            error = "GL_STACK_UNDERFLOW";
            break;
        case 0x505:
            error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = "unknown error!";
    }
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s function: %s\n",
                             file, line, error, func);
        retCode = 1;
    }
    return retCode;
}

MyGLWidget::~MyGLWidget() {
}

void MyGLWidget::initializeGL()
{
    BL2GLWidget::initializeGL();
    glEnable(GL_DEPTH_TEST);
    ini_camera();
}

void MyGLWidget::carregaShaders()
{
  BL2GLWidget::carregaShaders();
  projLoc = glGetUniformLocation(program->programId(),"proj");
  viewLoc = glGetUniformLocation(program->programId(),"view");
}

void MyGLWidget::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    modelTransform();
    projectTransform();
    viewTransform();

    glBindVertexArray(VAO_pat);
    glDrawArrays (GL_TRIANGLES, 0, size_model);
    glBindVertexArray(0);
}

void MyGLWidget::ini_camera()
{
    //atributs perspectiva
    FOV= float(M_PI)/2.0f;
    ratio= 1.0f;
    znear= 0.4f;
    zfar= 3.0f;
    //atributs vista
    OBS = glm::vec3(0,0,1);
    VRP = glm::vec3(0,0,0);
    UP = glm::vec3(0,1,0);
}

void MyGLWidget::projectTransform()
{
    glm::mat4 Proj = glm::perspective(FOV,ratio,znear,zfar);
    glUniformMatrix4fv(projLoc,1,GL_FALSE,&Proj[0][0]);
}

void MyGLWidget::viewTransform()
{
    glm::mat4 View = glm::lookAt ( OBS, VRP, UP );
    glUniformMatrix4fv( viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::creaBuffers()
{
    Model m;
    m.load("./Model/HomerProves.obj");
    size_model = m.faces().size()*3;
    glGenVertexArrays(1, &VAO_pat);
    glBindVertexArray(VAO_pat);
    
    
    GLuint VBO_pat[2];
    glGenBuffers(2, VBO_pat);

    //VBO vertices
    glBindBuffer(GL_ARRAY_BUFFER, VBO_pat[0]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*m.faces().size()*3*3,m.VBO_vertices(),GL_STATIC_DRAW);
    //atribut vertex
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);
    
    //VBO colores
    glBindBuffer(GL_ARRAY_BUFFER, VBO_pat[1]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*m.faces().size()*3*3,m.VBO_matdiff(),GL_STATIC_DRAW);
    //atribut colors
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);

   
    glBindVertexArray(0);
}
