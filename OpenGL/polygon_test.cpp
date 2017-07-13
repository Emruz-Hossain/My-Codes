#include<GL/freeglut.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
int R[] = {0,0,1,-1};
int C[] = {1,-1,0,0};
void showAxis(int x1, int x2, int y1, int y2)
{
    glBegin(GL_POINTS);
    for (int i = x1;i<=x2;i++)
    {
        glVertex2f(i, 0);
    }
    for (int j = y1; j <= y2;j++)
    {
        glVertex2f(0, j);
    }
    glFlush();
    glEnd();
}
void boundaryFill(int x,int y)
{
    glColor3f(1.0, 0.2, 0.8);
    gl
    glVertex2f(x, y);
    for (int i = 0; i < 4; i++)
    {
        boundaryFill(x + R[i], y + C[i]);
        glFlush();
    }
}
void displayPolygon(void)
{
    glClearColor(1, 1, 1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1, 0.5, 1.0);
    glOrtho(-500, 500, -500, 500, -500, 500);
    showAxis(-500,500,-500,500);
    glBegin(GL_POLYGON);
   // ---------------------Everything--------------
    glVertex2f(200, 20);
    glVertex2f(400, 400);
    glVertex2f(10, 300);
    glVertex2f(-200, -10);
    glVertex2f(-50, -280);
    glVertex2f(100, -250);
    glEnd();
    glFlush();
    boundaryFill(398,398);
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 400);
    glutCreateWindow("");
    glutDisplayFunc(displayPolygon);
    glutMainLoop();
}
