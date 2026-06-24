#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "monitor_offsets.h"

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.0, 0.5);
	glEnd();
	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	
	// Position on center monitor
	glutInitWindowPosition(Monitor::CENTER_X + 100, Monitor::DEV_OFFSET_Y);

	glutCreateWindow("Simple OpenGL Program");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
