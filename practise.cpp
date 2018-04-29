#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
int angle=45;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutSolidSphere(0.1,50,50);
	glRotatef(angle,0.0,0.0,0.1);
	glTranslatef(0.3,0.0,0.0);
	glColor3f(1,0,0);
}
void abc()
{
	angle+=1;
	glutPostRedisplay();
	glutTimerFunc(100,abc,0);
	glutSwapBuffers();
}
int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Midpoint Circle Algorithm");
	glutDisplayFunc(display);
	glutTimerFunc(100, abc, 0);
	glutMainLoop();
	return 0;
}
