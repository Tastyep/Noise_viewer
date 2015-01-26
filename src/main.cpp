extern "C"
{
#include "Perlin.h"
}
#include "Render.hpp"

#define WIDTH 1600
#define HEIGHT 900

int main(int argc, char *argv[])
{
  Render	render(WIDTH, HEIGHT);

  setSeed(0);
  initPerm();
  render.run();
  return 0;
}
