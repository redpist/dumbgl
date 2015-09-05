#include <dumbgl.h>

int main(int argc, char ** argv)
{
  DumbGL::Scene *scene;
  scene = DumbGL::Open("DumbGL Test 0", 800, 800);
  DumbGL::SetPixel(scene, 20, 20, 0xff0000);
  DumbGL::GetPixel(scene, 20, 20);
  while (true)
    DumbGL::Draw(scene);
  DumbGL::Close(scene);
  return 0;
}