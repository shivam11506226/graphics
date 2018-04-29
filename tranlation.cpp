#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<stdio.h>
float tx,ty,sx,sy,ang=0,x,y;
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity ();
	glTranslatef(tx,ty,0.0);
	glScalef(sx,sy,0);
	glRotatef(ang,x,y,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.0,0.0);
	glVertex2f(0.1,0.0);
	glVertex2f(0.05,0.2);
	glEnd();
	glFlush();
	
}
/*void draw1()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity ();
	glTranslatef(tx,ty,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.1,0.1);
	glVertex2f(0.2,0.1);
	glVertex2f(0.05,0.2);
	glEnd();
	glFlush();
	
}*/
void xyz(int v)
{
	x=x+0.3;
	y=y+0.3;
	tx=tx+0.01;
	ty=ty+0.01;
	ang=ang+5;
	sx=sx+.1;
	sy=sy+.1;
	glutPostRedisplay();
	glutTimerFunc(1000,xyz,0);
	
}
int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Circle Drawing Algorithm");
	
	glutDisplayFunc(draw);
	glutTimerFunc(10,xyz,0);
	
	glutMainLoop(); 
	return 0;
  }
