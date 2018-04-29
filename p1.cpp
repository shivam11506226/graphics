#include<windows.h>
#include<gl/glut.h>
#include<math.h>
#include <stdio.h>
void drawcircle(int radius,int h,int k)
{
	glBegin(GL_POINTS);
	glColor3f(1.0,0.0,0.0);
	double x0=0;
	double y0=radius;
	double p0;
	p0=1-radius;
	while(x0<=y0)
	{
		if(p0<0)
		{
			glVertex2d(h+x0,k+y0);
            		glVertex2d(h+x0,k-y0);
						glVertex2d(h-y0,k-x0);
							glVertex2d(h-x0,k+y0);
								glVertex2d(h+y0,k+x0);
									glVertex2d(h+y0,k-x0);
										glVertex2d(h-x0,k-y0);
										glVertex2d(h-y0,k+x0);
										p0=p0+(2*x0)+3;
														
		}
		else
		{
				glVertex2d(h+x0,k+y0);
            		glVertex2d(h+x0,k-y0);
						glVertex2d(h-y0,k-x0);
							glVertex2d(h-x0,k+y0);
								glVertex2d(h+y0,k+x0);
									glVertex2d(h+y0,k-x0);
										glVertex2d(h-x0,k-y0);
										glVertex2d(h-y0,k+x0);
										y0--;
										p0=p0+(2*x0)-(2*y0)+5;
		}
		x0++;
	}
	glEnd();
	glFlush();
}
void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);


		drawcircle(6,50,50);
	
		glutSwapBuffers();
}
int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(50,50);
	glutCreateWindow("CIRCLE");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
