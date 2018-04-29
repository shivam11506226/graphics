#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(0,0);
	glVertex2f(0.5,0);
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
