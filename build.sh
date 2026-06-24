#!/usr/bin/env bash
g++ $(find . -name '*.cpp') -std=c++20 -Wall -Wextra -o /tmp/nvim_run -lglut -lGLU -lGL &&
/tmp/nvim_run
