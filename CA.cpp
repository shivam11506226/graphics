#include<gl/glut.h>
#include<gl/glu.h>
#include<gl/gl.h>
void display()
{
	glBegin(GL_POINTS);
	glColor3f(1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	int r,x,y,p,h,k;
	r=200;
	h=500;
	k=500;
	x=0;
	y=r;
	p=1-r;
while(x<=y)
{	
	if(p<0)
	{
		x=x+1;
		y=y;
		p=p+2*x+3;
		glVertex2f(h+x,k+y);
		glVertex2f(h-x,k+y);
		glVertex2f(h-x,k-y);
		glVertex2f(h+x,k-y);
		glVertex2f(h+y,k+x);
		glVertex2f(h-y,k+x);
		glVertex2f(h-y,k-x);
		glVertex2f(h+y,k-x);
		
	}
	else
	{
		x=x+1;
		y=y-1;
		p=p+2*x-2*y+5;
		glVertex2f(h+x,k+y);
		glVertex2f(h-x,k+y);
		glVertex2f(h-x,k-y);
		glVertex2f(h+x,k-y);
		glVertex2f(h+y,k+x);
		glVertex2f(h-y,k+x);
		glVertex2f(h-y,k-x);
		glVertex2f(h+y,k-x);
	
	}
}
	glEnd();
	

	glBegin(GL_TRIANGLES);
	glVertex2f(500,700);
	glVertex2f(670,400);
	glVertex2f(330,400);
	
	glEnd();
	glFlush();

}
int main(int a,char** b)
{
	glutInit(&a,b);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(200,50);
	glutCreateWindow("");
	glOrtho(0,1000,0,1000,0,1000);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
