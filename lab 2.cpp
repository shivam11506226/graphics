#include<stdio.h>
#include<GL/gl.h>
#include<Gl/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<windows.h>

void drawEllipse(int r1,int r2,int h,int k)
{
	glBegin(GL_POINTS);
	glColor3f(1,0.5,1.7);
	int y=(int)r2;
	int x=0;
	int p=(r2*r2)-(r1*r1)*r2+(r1*r1)/4;
	while(2*r2*r2*x<2*r1*r1*y)
	{
	if(p<0)
	{
		glVertex2d(x+h,y+k);
		glVertex2d(h-x,y+k);
		glVertex2d(h-x,k-y);
		glVertex2d(x+h,k-y);
		
		p=p+(2*r2*r2)*(x+1)+r2*r2;
		x=x+1;
		y=y;
	
	}
	else
	{
		glVertex2d(x+h,y+k);
		glVertex2d(h-x,y+k);
		glVertex2d(h-x,k-y);
		glVertex2d(x+h,k-y);
		p=p+2*r2*r2*(x+1)-2*r1*r1*(y+1)+r2*r2;
		x=x+1;
		y=y-1;
	}}
	int p2=(r2*r2)*(x+0.5)*(x+0.5)+r1*r1*(y-1)*(y-1)-r1*r1*r2*r2;
		while(y!=0)
	{
	if(p2<0)
	{
		glVertex2d(x+h,y+k);
		glVertex2d(h-x,y+k);
		glVertex2d(h-x,k-y);
		glVertex2d(x+h,k-y);
		
		p2=p2+(2*r2*r2)*(x-1)-2*r1*r1*(y-1)+r1*r1;
		x=x+1;
		y=y-1;
	
	}
	else
	{
		glVertex2d(x+h,y+k);
		glVertex2d(h-x,y+k);
		glVertex2d(h-x,k-y);
		glVertex2d(x+h,k-y);
		p2=p2-2*r1*r1*(y-1)+r1*r1;
		x=x;
		y=y-1;
	}}
	
	glEnd();
		
}

void drawline(int x0,int y0,int x1,int y1)
{
	glBegin(GL_POINTS);
	glColor3f(1,0,1);
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
	drawline(20,20,20,68);
	drawline(0,0,20,20);
	drawline(0,60,40,60);
	drawline(20,20,40,0);
	drawEllipse(20,10,20,80);
	glutSwapBuffers();
	
}

void init(void)
{
	glClearColor(0.2,0.1,0,0);
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
	glutCreateWindow("2d man");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
