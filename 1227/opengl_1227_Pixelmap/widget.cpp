#include "widget.h"

#ifdef __APPLE__    // macOS인 경우
#include <GLUT/glut.h>
#else                      // Linux 등의 OS인 경우
#include <GL/glut.h>
#endif

Widget::Widget(QWidget *parent) : QOpenGLWidget(parent)
{
    setWindowTitle("OpenGL Pixelmap");
    resize(600, 600);
}

Widget::~Widget( )
{
}

void Widget::initializeGL( ) {
    initializeOpenGLFunctions( );
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity( );
    glOrtho(-1, 1, -1, 1, -1, 1);
}
void Widget::paintGL( )
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLubyte *data;

    glClear(GL_COLOR_BUFFER_BIT);

    QImage*image = new QImage("bmp_24.bmp");
    data = image->bits();
    if(data != NULL){
        glRasterPos2f(-0.5, -0.5);
        glDrawPixels(image->width(), image->height(), GL_BGRA_EXT, GL_UNSIGNED_BYTE, data);
    }

    glRasterPos2f(-1.0, -1.0);
    glCopyPixels(100,100,80,50,GL_COLOR);

    glFlush( );
}
