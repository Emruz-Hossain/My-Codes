#include<GL/freeglut.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
double p1x, p2x, p1y, p2y;
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
void displayLine(void)
{
    glClearColor(1, 1, 1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(-500, 500, -500, 500, -500, 500);
      glColor3f(1.0,0.30,0.30);
    showAxis(-500,500,-500,500);
    glColor3f(0,0,0);
    glPointSize(1);
    glBegin(GL_POINTS);
    // ---------------------Everything--------------
    double dx = p2x - p1x;
    double dy = p2y - p1y;
    double m = dy / dx;
    if (m < 1.0)
    {
    double y = p1y;
        for (double x = p1x; x<=p2x;x++)
        {
            // printf("printing\n");
            glVertex2f(x, floor(y + 0.5));
            y += m;
        }
    }
    else
    {
        double x = p1x;
        for (double y = p1y; y <= p2y; y++)
        {
            // printf("printing2\n");
            glVertex2f(floor(x + 0.5), y);
            x += 1/m;
        }
    }

    glEnd();
    glFlush();
}
int main(int argc,char **argv)
{
    printf("Enter first Point: ");
    scanf("%lf %lf",&p1x, &p1y);
    printf("Enter second point: ");
    scanf("%lf %lf", &p2x, &p2y);
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("DDA_Line_Drawing_Algorithm");
    glutDisplayFunc(displayLine);
    glutMainLoop();
}