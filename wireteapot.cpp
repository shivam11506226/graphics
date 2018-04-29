#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>

float ang=0,tx,ty,tz;
void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(ang,tx,ty,tz);
	//glutWireTeapot(0.5);
	glutWireTetrahedron();
	//glutSolidTeapot(0.5);
//	glutWireSphere(0.5,50,50);
	//glutSolidSphere(0.5,50,50);
	//	glutWireTorus(0.2,0.8,100,20);
//	glutSolidTorus(0.2,0.8,100,20);
//glutWireCone(0.2,0.8,10,20);
//glutSolidCone(0.2,0.8,100,20);
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	
	glEnd();
	glFlush();
	
	
}


void display(int v){
	ang=ang+0.1;
	tx=tx+0.5;
	ty=ty+0.5;
	tz=tz+0.5;
	glutPostRedisplay();
	glutTimerFunc(10,display,0); 
	
//	draw();
	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("scaling");
	glutDisplayFunc(draw);
	glutTimerFunc(100,display,0);
	glutMainLoop();
	return 0;
}
