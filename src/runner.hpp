#pragma once

#include "raylib.h"

extern struct Runner {
  private:
    int run();
    int mainloop();

    friend int main(int argc, char* argv[]);
} runner;

struct GracefulExit {};
