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

long long a,b;

void displayEllipse(void)
{
    glClearColor(1, 1, 1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1, 0.5, 1.0);
    glOrtho(-500, 500, -500, 500, -500, 500);
    showAxis(-500,500,-500,500);
    glColor3f(0, 0, 0);
    glBegin(GL_POINTS);
    // ---------------------Everything--------------
    long long x = 0, y = b;
    long long asq = a * a, bsq = b * b, asq2 = 2 * asq, bsq2 = 2 * bsq;
    long long fx = 0, fy = asq2 * b;
    long long p = bsq - asq * b + asq / 4.0;
    while(fx<fy)
    {
        glVertex2f(x, y);
        glVertex2f(x, -y);
        glVertex2f(-x, -y);
        glVertex2f(-x, y);
        x++;
        fx = fx + bsq2;
        if(p<0)
        {
            p = p + fx + bsq;
        }
        else
        {
            y--;
            fy = fy - asq2;
            p = p + fx + bsq - fy;
        }
    }
        glVertex2f(x, y);
        glVertex2f(x, -y);
        glVertex2f(-x, -y);
        glVertex2f(-x, y);
    p = bsq * (x + 0.5) * (x + 0.5) + asq * (y - 1) * (y - 1) - asq * bsq;
    while(y>0)
    {
        y--;
        fy = fy - asq2;
        if (p >= 0)
        {
            p = p - fy + asq;
        }
        else
        {
            x++;
            fx = fx + bsq2;
            p = p + fx - fy + asq;
        }
        glVertex2f(x, y);
        glVertex2f(x, -y);
        glVertex2f(-x, -y);
        glVertex2f(-x, y);
    }
    glEnd();
    glFlush();
}
int main(int argc,char **argv)
{
    printf("Enter length of Major Axis: ");
    scanf("%lld", &a);
    printf("Enter length of Minor Axis: ");
    scanf("%lld", &b);
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("");
    glutDisplayFunc(displayEllipse);
    glutMainLoop();
}
