#include "dumbgl.h"

using namespace DumbGL;

extern "C" {

  DumbGLScene *DumbGLOpen(const char *title, const int width, const int height) {
    return Open(title, width, height);
  }

  DumbGLEvent *DumbGLDraw(DumbGLScene *scene) {
    return Draw(scene);
  }

  DumbGLEvent *DumbGLLastEvent(DumbGLScene *scene) {
    return LastEvent(scene);
  }

  void DumbGLSetPixel(DumbGLScene *scene, int x, int y, int color) {
    SetPixel(scene, x, y, color);
  }

  int DumbGLGetPixel(DumbGLScene *scene, int x, int y) {
    return GetPixel(scene, x, y);
  }

  void DumbGLClose(DumbGLScene *scene) {
    Close(scene);
  }

}
