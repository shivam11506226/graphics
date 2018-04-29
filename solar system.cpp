#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>

float ang=0,tx,ty,tz;

	void draw()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutSolidSphere(0.15,50,50);
	
	glPushMatrix();
	glRotatef(ang,0.0,0.0,1.0);
	glTranslatef(0.3,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glutSolidSphere(0.05,50,50);
	glPopMatrix();

	glPushMatrix();
	glRotatef(ang,0.0,0.0,1.0);
	glTranslatef(0.0,0.6,0.0);
	glColor3f(0.0,1.0,0.0);
	glutSolidSphere(0.05,50,50);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(ang,0.0,0.0,1.0);
	glTranslatef(0.7,0.0,0.0);
	glColor3f(0.0,0.0,1.0);
	glutSolidSphere(0.05,50,50);
	glPopMatrix();
	
	glFlush();

}
void display(int v)
{
	ang=ang+1;
	tx=tx+0.5;
	ty=ty+0.5;
	tz=tz+0.5;
	glutPostRedisplay();
	glutTimerFunc(10,display,0);
	glutSwapBuffers();
}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("CA3");
	glutDisplayFunc(draw);
	glutTimerFunc(100,display,0);
	glutMainLoop();
	return 0;
}
