#include<windows.h>
#include<gl/glut.h>
#include<math.h>
#include<stdio.h>

void de(int rx,int ry,int k,int h)
{
	glBegin(GL_POINTS);
	glColor3f(1.0,0.0,0.0);
	double x0=0;
	double y0=ry;
	double p0,p1;
	p0=(ry*ry)-((rx*rx)*ry)+((rx*rx)/4);
	int a=2*(ry*ry)*x0;
	int b=2*(rx*rx)*y0;
	while(a<b)
	{
		if(p0<0)
		{
			x0=x0+1;
			glVertex2d(x0+1,y0);
			p0=p0+((2*(ry*ry)*x0)+(2*(ry*ry)))+(ry*ry);
			
				
		}
	else
		{
			x0++;
			y0--;
			
			glVertex2d(x0,y0);
				
		   p0=p0+((2*(ry*ry)*x0)+(2*(ry*ry)))+(ry*ry)-((2*(rx*rx)*y0)-(2*(rx*rx)));
		}
		
	}
	
	p1=(ry*ry)*((x0+(1/2))*(x0+(1/2)))+(((rx*rx)*(y0-1)*(y0-1)-(rx*rx)*(ry*ry)));
	while(y0!=0)
	{
		if(p1>1)
		{
			y0=y0-1;
				glVertex2d(x0,y0);
				p1=p1-(2*(rx*rx)*y0)-(2*(rx*rx))+(rx*rx);
		}
		else
		{
			x0++;
			y0--;
				glVertex2d(x0,y0);
			
			p1=p1-((2*(ry*ry)*x0)+(2*(ry*ry)))-((2*(rx*rx)*y0)-(2*(rx*rx)))+(rx*rx);
		}
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
	
de(10,5,50,50);
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
