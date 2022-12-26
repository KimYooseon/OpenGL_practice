//#include <math.h>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    //setWindowTitle("Hello OpenGL");
    //resize(600, 600);
//    radius = 0.05;
//    delta_theta = 2*M_PI/20;
//    theta = 0.0;
//    cord_length = 0.5;

//    bEdge = GL_FALSE;

    //setWindowTitle("OpenGL Animation");
    //setWindowTitle("OpenGL EdgeFlag3D");

    alpha = 0.5f;
    src = GL_SRC_ALPHA;
    dest = GL_ONE_MINUS_SRC_ALPHA;

    setWindowTitle("OpenGL Blending");
    resize(600, 600);

//    QTimer *timer = new QTimer();
//    connect(timer, SIGNAL(timeout()), SLOT(timerFunction()));
//    timer->start(1000/60);
}

Widget::~Widget()
{
}

void Widget::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void Widget::resizeGL(int w, int h){
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}


void Widget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //glEdgeFlag(TRUE);

    glEnable(GL_BLEND);
    glBlendFunc(src, dest);

    glColor3f(0, 0, 1);
    glRectf(-0.5, 0.8, 0.5, 0.0);

    glColor4f(1, 0, 0, alpha);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);

//    glBegin(GL_TRIANGLES);
//    if(bEdge)
//        glEdgeFlag(TRUE);
//    glVertex2f(0.0, 0.0);
//    glVertex2f(-0.5, 0.5);
//    if(bEdge)
//        glEdgeFlag(FALSE);
//    glVertex2f(-0.5, -0.5);

//    glVertex2f(0.0, 0.0);
//    if(bEdge)
//        glEdgeFlag(TRUE);
//    glVertex2f(0.5, -0.5);
//    glVertex2f(0.5, 0.5);

//    if(bEdge)
//        glEdgeFlag(FALSE);
//    glVertex2f(0.0, 0.0);
//    if(bEdge)
//        glEdgeFlag(TRUE);
//    glVertex2f(-0.5, -0.5);
//    if(bEdge)
//        glEdgeFlag(FALSE);
//    glVertex2f(0.5, -0.5);

//    glBegin(GL_TRIANGLES);
//    glColor3f(0.0, 1.0, 1.0);
//    glVertex2f(0.0, 0.5);
//    glVertex2f(-0.5, 0.0);
//    glVertex2f(0.0, 0.0);

//    glVertex2f(0.0, 0.0);
//    glVertex2f(0.5, 0.0);
//    glVertex2f(0.0, -0.5);


//    glRectf(-0.8, 0.8, 0.8, -0.8);

//    glShadeModel(GL_FLAT);
//    glBegin(GL_TRIANGLE_FAN);
//    glColor3f(1.0, 0.0, 1.0);
//    glVertex2f(0.0, 0.0);
//    glVertex2f(0.0, 0.5);
//    glVertex2f(-0.35, 0.35);

//    glColor3f(0.0, 1.0, 1.0);
//    glVertex2f(-0.5, 0.0);

//    glColor3f(1.0, 0.0, 1.0);
//    glVertex2f(-0.35, -0.35);

//    glColor3f(0.0, 1.0, 1.0);
//    glVertex2f(0.0, -0.5);

//    glBegin(GL_TRIANGLE_STRIP);
//    GLfloat x = -0.8;
//    GLfloat y = 0.4;
//    for(int i = 0 ; i < 6 ; i++){
//        if(i%2 == 0){
//            glColor3f(0.0, 0.0, 1.0);
//        } else {
//            glColor3f(0.0, 1.0, 1.0);
//        }

//        glVertex2f(x, y);
//        x += 0.3;
//        y *= -1;
//    };

    glEnd();
    glFlush();

//    current_angle = cos(0.1*atime);

//    glColor3f(1.0, 1.0, 1.0);
//    glBegin(GL_LINES);
//    glVertex2f(0.0, 0.0);
//    xcenter = -cord_length*sin(current_angle);
//    ycenter = -cord_length*cos(current_angle);
//    glVertex2f(xcenter, ycenter);
//    glEnd();

//    glColor3f(1.0, 0.0, 0.0);
//    glBegin(GL_POLYGON);
//    theta = 0;
//    while(theta <= 2*M_PI){
//        x = xcenter + radius * sin(theta);
//        y = ycenter + radius * cos(theta);
//        glVertex2f(x, y);
//        theta += delta_theta;
//    };


//    glBegin(GL_POLYGON);
//    glVertex3f(0.25, 0.25, 0.0);
//    glVertex3f(0.75, 0.25, 0.0);
//    glVertex3f(0.75, 0.75, 0.0);
//    glVertex3f(0.25, 0.75, 0.0);

//    glFlush();
}

//void Widget::timerFunction()
//{
//    atime++;
//    update();
//}

void Widget::keyPressEvent(QKeyEvent* event)
{
//    switch(event->key()){
//        case Qt::Key_Up:
//        bEdge = GL_TRUE;
//        break;

//        case Qt::Key_Down:
//        bEdge = GL_FALSE;
//        break;

//    };

    switch(event->key()){
        case Qt::Key_Up:
        alpha += 0.1;
        break;

        case Qt::Key_Down:
        alpha -= 0.1;
        break;

        case Qt::Key_Left:
        src = GL_ONE;
        dest = GL_ZERO;
        break;

        case Qt::Key_Right:
        src = GL_SRC_ALPHA;
        dest = GL_ONE_MINUS_SRC_ALPHA;
        break;
    };

    update();
}
