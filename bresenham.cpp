#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
void drawline(int x0, int y0, int x1, int y1){
	glBegin(GL_POINTS);
	glColor3f(1.0,1.0,1.0);
	double m = (double)(y1 - y0)/(x1 - x0);
	int q = y1- y0;
	int w = x1 - x0;
	int y = (int) y0;
	int x = (int)x0;
	int p = 2*q-w;
	if(m<1){
		while(x<=x1){
		if(p<0){
			glVertex2d(x,y);
			x = x+1;
			y = y;
			p = p+2*q;
		
		}
		else{
			glVertex2d(x,y);
			x = x+1;
			y = y+1;
			p = p+2*q - 2*w;
		}
	}
	}
	glEnd();
}

void init(){
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	drawline(2,3,90,80);
	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(100,100);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Bresenham line Algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
