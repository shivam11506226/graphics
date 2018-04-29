#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<stdio.h>
float ang=0,x,y,z;
void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity ();
	glColor3f(0,0,1);
     glRotatef(ang,x,y,z);
     glutWireTeapot(0.5);
    
	glFlush();
	}
	void xyz(int v)
{
	x=x+0.3;
	y=y+0.3;
	z=z+0.3;
	ang=ang+5;

	glutPostRedisplay();
	glutTimerFunc(100,xyz,0);
	
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
