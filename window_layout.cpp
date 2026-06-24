#include "window_layout.h"

#include <GL/glut.h>

const Monitor::Rect &ChooseMonitor(Screen screen) {
  switch (screen) {
  case Screen::Left:
    return Monitor::LEFT;
  case Screen::Center:
    return Monitor::CENTER;
  case Screen::Right:
    return Monitor::RIGHT;
  }

  return Monitor::CENTER;
}

static WindowLayout Inset(Monitor::Rect r, int margin) {
  return {
      r.x + margin,
      r.y + margin,
      r.w - margin * 2,
      r.h - margin * 2,
  };
}

static Monitor::Rect WithoutTaskbar(Monitor::Rect r) {
  return {
      r.x,
      r.y,
      r.w,
      r.h - Monitor::TASKBAR_HEIGHT,
  };
}

static Monitor::Rect LeftHalf(Monitor::Rect r) {
  return {
      r.x,
      r.y,
      r.w / 2,
      r.h,
  };
}

static Monitor::Rect RightHalf(Monitor::Rect r) {
  return {
      r.x + r.w / 2,
      r.y,
      r.w / 2,
      r.h,
  };
}

static WindowLayout Centered(Monitor::Rect r, int width, int height) {
  return {
      r.x + (r.w - width) / 2,
      r.y + (r.h - height) / 2,
      width,
      height,
  };
}

WindowLayout MakeLayout(Screen screen, Layout layout, int width, int height,
                        int margin) {
  const Monitor::Rect monitor = WithoutTaskbar(ChooseMonitor(screen));

  switch (layout) {
  case Layout::Centered:
    return Centered(monitor, width, height);

  case Layout::Fill:
    return Inset(monitor, margin);

  case Layout::LeftHalf:
    return Inset(LeftHalf(monitor), margin);

  case Layout::RightHalf:
    return Inset(RightHalf(monitor), margin);
  }

  return Centered(monitor, width, height);
}

void CreateWindow(Screen screen, Layout layout, const char *title, int width,
                  int height, int margin) {
  const WindowLayout outer = MakeLayout(screen, layout, width, height, margin);

  const int client_w =
      outer.w - Monitor::WINDOW_BORDER_LEFT - Monitor::WINDOW_BORDER_RIGHT;

  const int client_h =
      outer.h - Monitor::WINDOW_TITLEBAR_HEIGHT - Monitor::WINDOW_BORDER_BOTTOM;

  glutInitWindowSize(client_w, client_h);
  glutInitWindowPosition(outer.x, outer.y);
  glutCreateWindow(title);
}

