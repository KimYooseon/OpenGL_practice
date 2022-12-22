#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    xAngle = yAngle = zAngle = 0;
    setWindowTitle("OpenGL VertexArrayIndex");
    resize(600, 600);
}

Widget::~Widget()
{
}

void Widget::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Widget::resizeGL(int w, int h){
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}


void Widget::paintGL(){
    static GLfloat vert[] = {
        0,0,-0.8,
        0.5,0.5,0,
        -0.5,0.5,0,
        -0.5, -0.5, 0,
        0.5, -0.5, 0,
    };

    static GLubyte index[] = {
        0,1,2,
        0,2,3,
        0,3,4,
        0,4,1,
    };

    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 0.1f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 0.1f);

    glRectf(-0.5, 0.5, 0.5, -0.5);


    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vert);

    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, index);
    glPopMatrix();
    glFlush();

}

void Widget::keyPressEvent(QKeyEvent* event)
{
    switch(event->key()){
        case Qt::Key_1:
            yAngle +=2;
            break;
        case Qt::Key_2:
            yAngle -=2;
            break;
        case Qt::Key_3:
            xAngle +=2;
            break;
        case Qt::Key_4:
            xAngle -=2;
            break;
        case Qt::Key_5:
            zAngle +=2;
            break;
        case Qt::Key_6:
            zAngle -=2;
            break;
        case Qt::Key_0:
            xAngle = yAngle = zAngle = 0.0;
            break;
    };

    QString str = QString("x: %1, y: %2, z: %3").arg(xAngle).arg(yAngle).arg(zAngle);
    setWindowTitle(str);
    update();
}












