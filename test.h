/* This header file is exclusively prepared for the graphics project titled "SOKOBAN" and is not meant for any other purpose.
    Credits : 1.Utkarsh Deep(1MV14CS115) 2. Shubham Sinha(1MV14CS101)
*/
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include<GL/glut.h>
//#include <vector>

//std::vector <unsigned char> logo1;

void makeFace(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4);
void makePath(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4) {
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
    glFlush();
}
void makeWall(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4) {
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
    glFlush();
}


void makeFloor(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4) {
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
    glFlush();
}
/*void makeBox(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4) {
    glColor3f(0.545,0.271,0.0745);
    glBegin(GL_POLYGON);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
    glFlush();
}*/
void makeDestination(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4) {
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
    glFlush();
}
double distance(double x1,double y1,double x2,double y2) {
    double a=pow(x1-x2,2);
    double b=pow(y1-y2,2);
    double dist=sqrt(a+b);
    return dist;
}
