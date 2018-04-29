#include<windows.h>
#include<gl/glut.h>
#include<math.h>
#include<stdio.h>
void drawLine(int x0,int y0,int x1,int y1)
{
	glBegin(GL_POINTS);
	glColor3f(1.0,1.0,1.0);
	double m=(double)(y1-y0)/(x1-x0);
	double y=(double)y0;
	double x=(double)x0;
	double p=(double)2*(y1-y0)-(x1-x0);
	
	
		while(x<=x1)
		
		{
			if(p<0)
			{
			
			glVertex2d(x,y);
			y=y;
			x++;
		
		p=p+2*(y1-y0);
	}
	
	else
	
	
		
		
		{
			glVertex2d(x,y);
			y++;
			x++;
			p=p+2*(y1-y0)-(x1-x0);
		}
	}
	glEnd();
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
	drawLine(2,3,90,80);
	glutSwapBuffers();
}
int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(100,100);
	glutInitWindowPosition(50,50);
	glutCreateWindow("bresenham Line Drwaing");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
