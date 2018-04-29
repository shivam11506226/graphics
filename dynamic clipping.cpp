#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
#include<iostream>
using namespace std;
float x1,x2,y1,y2,xmin,xmax,ymin,ymax,x11=xmin,x22=xmax,y22,y11,m,t1,t2,b1,b2,r1,r2,l1,l2;

void draw2()
{
	glPushMatrix();
	glColor3f(0,1,0);
	glBegin(GL_LINES);
	glVertex2f(x11,y11);
	glVertex2f(x22,y22);
	glEnd();
	glPopMatrix();
	glFlush();
}

void calc()
{	glPushMatrix();
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
	
	cout<<"Region code I "<<t1<<b1<<r1<<l1;	
	
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
	
	cout<<"\nRegion code II "<<t2<<b2<<r2<<l2;

	m=(y2-y1)/(x2-x1);

	y11=(m*(x11-x1))+y1;
	y22=(m*(x22-x2))+y2;
	draw2();
		glPopMatrix();
}

void draw()
{glPushMatrix();
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(xmin,ymin);
	glVertex2f(xmax,ymin);
	glVertex2f(xmax,ymax);
	glVertex2f(xmin,ymax);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
		glPopMatrix();
	glFlush();
}

void init(){
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
}

void enter()
{glPushMatrix();
	cout<<"\n Enter the window size";
	cout<<"\nxmin:";
	cin>>xmin;
	cout<<"\nxmax:";
	cin>>xmax;
	cout<<"\nymin:";
	cin>>ymin;
	cout<<"\nymax:";
	cin>>ymax;
	
	cout<<"Enter the line coordinates";
	cout<<"\nx1:";
	cin>>x1;
	cout<<"\nx2:";
	cin>>x2;
	cout<<"\ny1:";
	cin>>y1;
	cout<<"\ny2:";
	cin>>y2;
	glPopMatrix();
}

void display(){
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT);
		
	draw();
	calc();
	glutSwapBuffers();
		glPopMatrix();
}




int main(int argc, char **argv){
enter();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Cohen Sutherland Line Clipping");
	init();
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
}

