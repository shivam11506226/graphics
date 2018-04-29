#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
void draw(int x0,int y0,int x1,int y1)
{
	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	double m=(double)(y1-y0)/(x1-x0);
	double x=(double)x0;
	double y=(double)y0;
	double p=(double)2*(y1-y0)-(x1-x0);
	while(x<=x1)
	{
		if(p<0)
		{
			glVertex2d(x,y);
			x++;
			y=y;
			p=p+2*(y1-y0);
		}
		else
		{
		glVertex2d(x,y);
		x++;
		y++;
	 p=p+2*(y1-y0)-(x1-x0);	
		}
		
	}
	glEnd();
	glFlush();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw(2,3,80,90);
	glutSwapBuffers();
}
void init(void)
{
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,100,0,100,0,100);
	
}
int main(int args,char **argc)
{
	glutInit(&args,argc);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("bedrham");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
