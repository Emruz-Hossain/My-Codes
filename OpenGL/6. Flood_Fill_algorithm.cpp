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
int visit[1005][1005], vx = 500, vy = 500;
int R[] = {-1,0,1,0,-1,1,1,-1};
int C[] = {0,1,0,-1,1,1,-1,-1};
void floodFill(int x,int y)
{
    int xp = 0, yp = 0;
    while(visit[xp+vx][vy]==0)
    {
        yp = 0;
        while (visit[xp + vx][yp + vy] != -1)
        {
            glVertex2f(xp, yp);
            yp++;
        }
        yp = 0;
        while(visit[xp+vx][yp+vy]!=-1)
        {
            glVertex2f(xp,yp);
            yp--;
        }
        xp++;
    }
    xp = 0;
    while (visit[xp + vx][vy] ==0)
    {
        yp = 0;
        while (visit[xp + vx][yp + vy] ==0)
        {
            glVertex2f(xp, yp);
            yp++;
        }
        yp = 0;
        while(visit[xp+vx][yp+vy]==0)
        {
            glVertex2f(xp,yp);
            yp--;
        }
        xp--;
    }
}
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
        visit[x + vx][y + vy] = -1;
        visit[x + vx][-y + vy] = -1;
        visit[-x + vx][-y + vy] = -1;
        visit[-x + vx][y + vy] = -1;
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
        visit[x + vx][y + vy] = -1;
        visit[x + vx][-y + vy] = -1;
        visit[-x + vx][-y + vy] = -1;
        visit[-x + vx][y + vy] = -1;
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
        visit[x + vx][y + vy] = -1;
        visit[x + vx][-y + vy] = -1;
        visit[-x + vx][-y + vy] = -1;
        visit[-x + vx][y + vy] = -1;
    }
    glColor3f(0.5, 0.5, 0.8);
    floodFill(0, 0);
    glEnd();
    glFlush();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("flood_fill_algorithm");
    a = 350;
    b = 250;
    memset(visit, 0, sizeof(visit));
    glutDisplayFunc(displayEllipse);
    glutMainLoop();
}