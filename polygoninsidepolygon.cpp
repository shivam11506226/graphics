#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,1);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5,-0.5);
	glVertex2f(0.8,-0.5);
	glVertex2f(0.8,0.8);
	glVertex2f(0,0.5);
	glEnd();
		glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.3,-0.3);
	glVertex2f(0.6,-0.3);
	glVertex2f(0.6,0.6);
	glVertex2f(0,0.5);
	glEnd();
	glFlush();
}
int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Simple");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
