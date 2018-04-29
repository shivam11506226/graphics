#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

float ang = 0, tx,ty,tz;
void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(-0.2,-0.9);
	glVertex2f(0.2,-0.9);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glRotatef(ang,0.0,0.0,2.0);
	glColor3f(0.0,0.5,0.7);
	glBegin(GL_LINES);
	glVertex2f(-0.5,0);
	glVertex2f(0.5,0);
	glVertex2f(0,0.5);
	glVertex2f(0,-0.5);
	glEnd();
	glPopMatrix();
	glFlush();
	
}

void display(int v){
	ang = ang + 2;
	tx = tx+0.5;
	ty = ty+0.5;
	tz = tz+0.5;
	glutPostRedisplay();
	glutTimerFunc(10,display,0);
	glutSwapBuffers();
}
int main(int argc, char **argv ){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Widmill");
	glutDisplayFunc(draw);
	glutTimerFunc(100,display,0);
	glutMainLoop();
	return 0;
	
}
