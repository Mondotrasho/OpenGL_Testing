#include "monitor_offsets.h"
#include "window_layout.h"
#include <GL/gl.h>
#include <GL/glut.h>

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex2f(-0.5f, -0.5f);
  glVertex2f(0.5f, 0.5f);
  glVertex2f(0.0f, 0.5f);
  glEnd();

  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  CreateWindow(Screen::Center, Layout::RightHalf, "Simple OpenGL Program", 800,
               600, Monitor::DEFAULT_MARGIN * 2);

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
