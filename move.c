#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

float angle=0,tx=1,ty=1,tz=1;
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(0,0.5,0.5);
	//glutWireCone(0.6,0.8,10,20);
	glBegin(GL_TRIANGLES);
		glVertex2d(0,0);
		glVertex2d(-0.10,-0.8);
		glVertex2d(0.10,-0.8);
	glEnd();
	
	glRotatef(angle,0,0,1);
	//glutWireTeapot(0.5);
	//glutSolidTeapot(0.5);
	//glutWireSphere(0.7,50,50);
	//glutSolidSphere(0.7,50,50);
//	glutWireTorus(0.2,0.8,100,20);
	//glutSolidTorus(0.2,0.8,100,20);
	glColor3f(0,0.4,0);
	glBegin(GL_TRIANGLES);
		glVertex2d(0,0);
		glVertex2d(0.25,0.25);
		glVertex2d(0.35,0.15);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex2d(0,0);
		glVertex2d(0.35,-0.15);
		glVertex2d(0.25,-0.25);
	glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2d(0,0);
		glVertex2d(-0.25,-.25);
		glVertex2d(-0.35,-0.15);
	glEnd();
	//glutWireCone(0.6,0.8,10,20);
	glBegin(GL_TRIANGLES);
		glVertex2d(0,0);
		glVertex2d(-0.25,.25);
		glVertex2d(-0.35,0.15);
	glEnd();
	glFlush();
	
}
void rotate(){
	angle+=40;
	//ty+=0.1;
	//tx+=0.1;
	//tz+=0.1;
	glutPostRedisplay();
	glutTimerFunc(100,rotate,0);
}
int main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(150,150);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	glutTimerFunc(100,rotate,0);
	
	glutMainLoop();
}
