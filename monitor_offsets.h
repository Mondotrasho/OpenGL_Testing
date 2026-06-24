// monitor_offsets.h
#pragma once

namespace Monitor {

struct Rect {
  int x;
  int y;
  int w;
  int h;
};

constexpr int DESKTOP_HEIGHT = 1440;

constexpr int centered_y(int h) {
  return (DESKTOP_HEIGHT - h) / 2;
}

constexpr Rect monitor(int x, int w, int h) {
  return {x, centered_y(h), w, h};
}

constexpr Rect LEFT   = monitor(0,    1920, 1080); // Windows monitor 3
constexpr Rect CENTER = monitor(1920, 3440, 1440); // Windows monitor 1
constexpr Rect RIGHT  = monitor(5360, 2560, 1440); // Windows monitor 2

constexpr int TASKBAR_HEIGHT = 40;
constexpr int DEFAULT_MARGIN = 40;

constexpr int WINDOW_TITLEBAR_HEIGHT = 31;

constexpr int WINDOW_BORDER_LEFT = 0;
constexpr int WINDOW_BORDER_RIGHT = 0;
constexpr int WINDOW_BORDER_BOTTOM = 0;

} // namespace Monitor
