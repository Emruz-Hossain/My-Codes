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
double rad(double angle)
{
    double pi = 2 * acos(0);
    return ((angle * pi) / 180.0);
}
void C_curve(double x,double y,double len,double alpha,int order)
{
    if(order>0)
    {
        len = len / sqrt(2.0);
        C_curve(x, y, len, alpha + 45, order - 1);
        x = x + len * cos(rad(alpha + 45));
        y = y + len * sin(rad(alpha + 45));
        C_curve(x, y, len, alpha - 45, order - 1);

    }
    else
    {
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x + len * cos(rad(alpha)), y + len * sin(rad(alpha)));
        glEnd();
        glFlush();

    }
}
void displayCurve(void)
{
    glClearColor(1, 1, 1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1, 0.5, 1.0);
    glOrtho(-100, 100, -100, 100,-100,100);
    showAxis(-500,500,-500,500);
    glPointSize(3);
    double x, y, len;
    int order;
    printf("Enter starting co-ordinate(x,y): ");
    scanf("%lf %lf", &x, &y);
    printf("Enter Length of the line (L): ");
    scanf("%lf", &len);
    printf("Enter order of the C-curve: ");
    scanf("%d", &order);
    C_curve(x, y, 90, len, order);
    
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    glutCreateWindow("");
    glutDisplayFunc(displayCurve);
    glutMainLoop();
}
