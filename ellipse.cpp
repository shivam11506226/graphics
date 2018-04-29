#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include<stdio.h>
void drawEllipse(int r1,int r2,int h,int k)
{
	glBegin(GL_POINTS);
	glColor3f(1.2,0.5,1.7);
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

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,0.0,100.0);
	
}
 int j=50;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
drawEllipse(30,40,50,50);
drawEllipse(20,30,50,50);
	glutSwapBuffers();
}
int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(100,100);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Circle Drawing Algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop(); 
	return 0;
  }
