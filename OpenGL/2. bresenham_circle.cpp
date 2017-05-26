#include<GL/freeglut.h>
#include<GL/glut.h>
#include<stdio.h>
int r;

void displayCircle(void)
{
   	glClearColor(1, 1, 1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glOrtho(-500, 500, -500, 500, -500, 500);
    glPointSize(2);
    glBegin(GL_POINTS);

    int x, y,d;
    x = 0;
    y = r;
    d = 3 - 2 * r;
    while (x <= y)
    {
        
        glVertex2f(x,y);
        glVertex2f(y,x);
        glVertex2f(-y,x);
        glVertex2f(-x,y);
        glVertex2f(-x,-y);
        glVertex2f(-y,-x);
        glVertex2f(y,-x);
        glVertex2f(x,-y);
        if(d<0)
        {
            d = d + 4 * x + 6;
        }
        else 
        {
            d = d + 4 *( x-y) + 10;
            y--;
        }
        x++;
    }

    glEnd();
    glFlush();
}
int main(int argc,char **argv)
{
    printf("Enter Radius of the circle: ");
    scanf("%d", &r);
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Breselham's Circle Algorithm'");
    glutDisplayFunc(displayCircle);
    glutMainLoop();
}