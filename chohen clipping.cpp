#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
#include<iostream>
using namespace std;
float xmin=30;
float ymin=30;
float xmax=70;
float ymax=70;
float x1=20,y1=50,x2=80,y2=60,x11=xmin,x22=xmax,y11,y22,m,t1,t2,b1,b2,r1,r2,l1,l2;

void draw2()
{
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(x11,y11);
	glVertex2f(x22,y22);
	glEnd();
	glFlush();
}
void calc()
{
	if(x1-xmin<0)
	{
		l1=1;
	}
	else
	{
	l1=0;
	}
	if(xmax-x1<0)
	{
		r1=1;
	}
	else
	{
	r1=0;
	}
if(y1-ymin<0)
	{
		b1=1;
	}
	else
	{
	b1=0;
	}
if(ymax-y1<0)
	{
		t1=1;
	}
	else
	{
	t1=0;
	}
	cout<<" Region code 1 ="<<t1<<b1<<r1<<l1;
	m=(y2-y1)/(x2-x1);
	
	if(x2-xmin<0)
	{
		l2=1;
	}
	else
	{
	l2=0;
	}
	if(xmax-x2<0)
	{
		r2=1;
	}
	else
	{
	r2=0;
	}
if(y2-ymin<0)
	{
		b2=1;
	}
	else
	{
	b2=0;
	}
if(ymax-y2<0)
	{
		t2=1;
	}
	else
	{
	t2=0;
	}
	
	cout<<" Region code 1 ="<<t2<<b2<<r2<<l2;
	m=(y2-y1)/(x2-x1);
	y11=(m*(x11-x1)+y1);
	y22=(m*(x22-x2)+y2);
	draw2();
	

}


void draw()
{
	glBegin(GL_LINE_LOOP);
	glColor3f(1,1,1);
	glVertex2f(30,30);
	glVertex2f(70,30);
	glVertex2f(70,70);
	glVertex2f(30,70);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(20,50);
	glVertex2f(80,60);
	glEnd();
	
	glFlush();
}


void init(){
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
draw();
calc();
	glutSwapBuffers();
}





int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(50,50);
	glutCreateWindow("cohen cliping");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
