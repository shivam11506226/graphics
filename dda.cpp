#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>


void drawable(int x0,int y0,int x1,int y1)
{
	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	double x=(double)x0;
	double y=(double)y0;
	double m=(double)(y1-y0)/(x1-x0);
	
	if(m<1)
	{
		while(x<=x1)
		{
			glVertex2d(x,round(y));
			x++;
			y=y+m;
		}
	}
	else
	{
		double m1=(double)1/m;
		while(y<=y1)
		{
			glVertex2d(round(x),y);
			y++;
			x=x+m1;
		}
	}
	glEnd();
	glFlush();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawable(10,10,60,60);
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
	glutCreateWindow("Simple");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
