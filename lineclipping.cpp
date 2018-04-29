#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
float Xmin=10,Xmax=20,Ymin=10,Ymax=20,x1=5,y1=12,x2=30,y2=15;
float x11=Xmin,y11,x22=Xmax,y22,m,t1,t2,b1,b2,r1,r2,l1,l2;
void draw()
{
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(Xmin,Ymin);
	glVertex2f(Xmax,Ymin);
	glVertex2f(Xmax,Ymax);
	glVertex2f(Xmin,Ymax);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
	
	
	if((x1-Xmin)<0)
	l1=1;
	if((Xmax-x1)<0)
	r1=1;
	if((y1-Ymin)<0)
	b1=1;
	if((Ymax-y1)<0)
	t1=1;
	
	if((x2-Xmin)<0)
	l2=1;
	if((Xmax-x2)<0)
	r2=1;
	if((y2-Ymin)<0)
	b2=1;
	if((Ymax-y2)<0)
	t2=1;
	
	cout<<"TBRL1:"<<t1<<""<<b1<<""<<r1<<""<<l1<<endl;
	cout<<"TBRL2:"<<t2<<""<<b2<<""<<r2<<""<<l2<<endl;
	
	m=(y2-y1)/(x2-x1);
	y11=m*(x11-x1)+y1;
	cout<<"x11,y11: "<<x11<<","<<y11<<endl;
	y22=m*(x22-x2)+y2;
	cout<<"x22,y22: "<<x22<<","<<y22<<endl;
	
	glBegin(GL_LINES);
	glColor3f(0.0,1.0,1.0);
	glVertex2f(x11,y11);
	glVertex2f(x22,y22);
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
	draw();
	glutSwapBuffers();
}
int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Cohen Sutherland Line Clipping Algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
