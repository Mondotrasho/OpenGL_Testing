#pragma once

#include "monitor_offsets.h"

enum class Screen {
  Left,
  Center,
  Right,
};

enum class Layout {
  Centered,
  Fill,
  LeftHalf,
  RightHalf,
};

struct WindowLayout {
  int x;
  int y;
  int w;
  int h;
};

const Monitor::Rect &ChooseMonitor(Screen screen);

WindowLayout MakeLayout(Screen screen, Layout layout, int width = 800,
                        int height = 600,
                        int margin = Monitor::DEFAULT_MARGIN);

void CreateWindow(Screen screen, Layout layout, const char *title,
                  int width = 800, int height = 600,
                  int margin = Monitor::DEFAULT_MARGIN);

