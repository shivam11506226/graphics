#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>

float tx,ty;
void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(tx,ty,0.0);
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0.1,0.1);
	glVertex2f(0.2,0.1);
	glVertex2f(0.05,0.8);
	
	glEnd();
	glFlush();
	
	
}


void display(int v){
	tx = tx+0.01;
	ty = ty+0.01;
	glutPostRedisplay();
	glutTimerFunc(100,display,0); 
	

	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Translate");
	glutDisplayFunc(draw);
	glutTimerFunc(100,display,0);
	glutMainLoop();
	return 0;
}
