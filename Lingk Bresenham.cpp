#include <GL/glut.h> 
#include<math.h>
#include<iostream>
using namespace std;
void circle(int x0,int y0,float x,float y)
{
	glBegin(GL_POINTS);
	glColor3f(1,0,0); 
	glVertex2f((x0+x)/1000,(y0+y)/1000);
	glVertex2f((x0+y)/1000,(y0+x)/1000);
	glVertex2f((x0+y)/1000,(y0-x)/1000);
	glVertex2f((x0+x)/1000,(y0-y)/1000);	
	glVertex2f((x0-x)/1000,(y0-y)/1000);
	glVertex2f((x0-y)/1000,(y0-x)/1000);
	glVertex2f((x0-y)/1000,(y0+x)/1000);
	glVertex2f((x0-x)/1000,(y0+y)/1000);
	glEnd();
}

void bresenham(float x0,float y0,float r)
{
	float d,x,y;
	x=0;
	y=r;
	d=3-2*r;
	while(x<=y){
		circle(x0,y0,x,y);
		if(d<0)
			d+=4*x+6;
		else{
			d+=4*(x-y)+10;
			y--;
		}
		x++;
	}
}

void display(void){
	float x0,y0,r;
	cout<<"Masukkan titik koordinat dan radius :"<<endl;
	cin>>x0>>y0>>r;
	bresenham(x0,y0,r);
	glFlush(); 
}

int main(int argc, char **argv) { 
    glutInit(&argc, argv); 
  	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA); 
    glutInitWindowPosition(200,200); 
    glutInitWindowSize(400,400); 
    glutCreateWindow("Lingkaran Bresenham"); 
    glutDisplayFunc(display);
    glutMainLoop(); 
}


