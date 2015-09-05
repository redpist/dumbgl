#ifndef DUMBGL_H_
# define DUMBGL_H_

#include <stdint.h>

# ifdef __cplusplus
  struct SDL_Window;
  struct SDL_Renderer;
  struct SDL_Texture;
  union SDL_Event;
  typedef uint32_t Uint32;

  struct DumbGLScene {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Uint32 *pixels;
    SDL_Event *event;
    int width;
    int height;
  };
  typedef SDL_Event DumbGLEvent;
# else
  typedef struct DumbGLScene DumbGLScene;
  typedef struct DumbGLEvent DumbGLEvent;
# endif

# ifdef __cplusplus
  namespace DumbGL {
    typedef DumbGLEvent Event;
    typedef DumbGLScene Scene;

    Scene *Open(const char *title, const int width, const int height);
    Event *Draw(Scene *scene);
    Event *LastEvent(Scene *scene);
    void Fill(Scene *scene, int color);
    void SetPixel(Scene *scene, int x, int y, int color);
    int GetPixel(Scene *scene, int x, int );
    void Close(Scene *scene);
  }
# endif

# ifdef __cplusplus
  extern "C" {
# endif
    DumbGLScene *DumbGLOpen(const char *title, const int width, const int height);
    DumbGLEvent *DumbGLDraw(DumbGLScene *scene);
    DumbGLEvent *DumbGLLastEvent(DumbGLScene *scene);
    void DumbGLFill(DumbGLScene *scene, int color);
    void DumbGLSetPixel(DumbGLScene *scene, int x, int y, int color);
    int DumbGLGetPixel(DumbGLScene *scene, int x, int y);
    void DumbGLClose(DumbGLScene *scene);
# ifdef __cplusplus
}
# endif

#endif
