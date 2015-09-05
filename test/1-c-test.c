#include "dumbgl.h"

int main(int argc, char ** argv)
{
  DumbGLScene *scene;
  scene = DumbGLOpen("DumbGL Test 1", 800, 800);
  DumbGLSetPixel(scene, 20, 20, 0xff0000);
  DumbGLGetPixel(scene, 20, 20);
  while (1)
    DumbGLDraw(scene);
  DumbGLClose(scene);
  return 0;
}