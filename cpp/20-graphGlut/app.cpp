#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

void setup(){
	int argc = 1;
	char *argv[1]={(char*)"Something"};
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(800,600);
	glutCreateWindow("Hello World");
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRectf(-0.99f,0.99f, 0.99f, -0.99f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex3f (0.25, 0.25, 0.0);
		glVertex3f (0.75, 0.25, 0.0);
		glVertex3f (0.75, 0.75, 0.0);
		glVertex3f (0.25, 0.75, 0.0);
		glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
		glVertex2f(-0.90, -0.90);
		glVertex2f(0.90, 0.90);
	glEnd();

	glFlush();
	glutSwapBuffers();
}
int main(){

	setup();
	glutDisplayFunc(display);
	glutMainLoop();
return 0;
}
