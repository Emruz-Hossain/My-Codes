#include<GL/freeglut.h>
#include<GL/glut.h>

void showAxis(int x1,int x2,int y1,int y2)
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

void displayCircle(void)
{
    glClearColor(1, 1, 1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1, 0.5, 1.0);
    glOrtho(-500, 500, -500, 500, -500, 500);
    showAxis(-500,500,-500,500);
    glBegin(GL_LINES);
   // ---------------------Everything--------------
    glVertex2f(0, 0);
    glVertex2f(400, 400);

    glEnd();
    glFlush();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 400);
    glutCreateWindow("");
    glutDisplayFunc(displayCircle);
    glutMainLoop();
}
