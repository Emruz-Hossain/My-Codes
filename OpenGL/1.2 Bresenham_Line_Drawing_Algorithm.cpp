#include<GL/freeglut.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
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

int p1x, p1y, p2x, p2y;
void displayLine(void)
{
    glClearColor(1, 1, 1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1, 0.5, 1.0);
    glOrtho(-500, 500, -500, 500, -500, 500);
    showAxis(-500,500,-500,500);
     glColor3f(0, 0, 0);
     glPointSize(1);
     glBegin(GL_POINTS);
     // ---------------------Everything--------------
     int dx = p2x - p1x;
     int dy = p2y - p1y;
     int dT = 2 * (dy - dx);
     int dS = 2 * dy;
     int d = 2 * dy - dx;
     int x = p1x;
     int y = p1y;
    while (x <= p2x)
            {
                glVertex2f(x, y);
                if (d < 0)
                {
                    d = d + dS;
                }
                else
                {
                    d = d + dT;
                    y++;
                }
                x++;
            }
    
    glEnd();
    glFlush();
}
int main(int argc,char **argv)
{
    printf("Enter first point: ");
    scanf("%d %d", &p1x, &p1y);
    printf("Enter second pont: ");
    scanf("%d %d", &p2x, &p2y);
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Bresenham_Line_Drawing_Algorithm");
    glutDisplayFunc(displayLine);
    glutMainLoop();
}
