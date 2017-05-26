#include<GL/freeglut.h>
#include<GL/glut.h>
void drawPoint()
{
	glClearColor(0.4, 0.4, 0.4,0.4);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3,0.2,0.8);
	glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
	glPointSize(1);
	glBegin(GL_POINTS);
	for (double x = 0; x <= 100;x+=1)
	{
		for (double y = 1; y <= 100;y+=1)
		{
			glVertex2f(x, y);
		}
	}
	glEnd();		

	glFlush();
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(800, 400);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Test Window");
	glutDisplayFunc(drawPoint);
	
	glutMainLoop();
}