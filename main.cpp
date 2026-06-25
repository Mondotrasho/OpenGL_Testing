#include "monitor_offsets.h"
#include "window_layout.h"
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

float x_pos = 0;
float y_pos = 0;
void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex2f(-0.5f + x_pos, -0.5f + y_pos);
  glVertex2f(0.5f + x_pos, 0.5f + y_pos);
  glVertex2f(0.0f + x_pos, 0.5f + y_pos);
  glEnd();

    std::cout << x_pos << " , " << y_pos << std::endl;
  glFlush();
}

// Parameters x and y are required for the glutKeyboardFunc
void processNormalKeys(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
    exit(0);
    break;
  }
}

void processSpecialKeys(int key, int xx, int yy) {

  switch (key) {
  case GLUT_KEY_LEFT:
      x_pos += -0.01f;
    break;
  case GLUT_KEY_RIGHT:
      x_pos += 0.01f;
    break;
  case GLUT_KEY_UP:
      y_pos += 0.01f;
    break;
  case GLUT_KEY_DOWN:
      y_pos += -0.01f;
    break;
  }
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  CreateWindow(Screen::Left, Layout::RightHalf, "Simple OpenGL Program", 800,
               600, Monitor::DEFAULT_MARGIN * 2);

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

  glutDisplayFunc(display);
  glutKeyboardFunc(processNormalKeys);
  glutSpecialFunc(processSpecialKeys);


	glutIdleFunc(display);
  glutMainLoop();

  return 0;
}
