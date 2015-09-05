#include "dumbgl.h"
#include <string.h>
#include <SDL2/SDL.h>

namespace DumbGL {

  DumbGL::Scene *Open(const char *title, const int width, const int height) {
    SDL_Init(SDL_INIT_VIDEO);
    DumbGL::Scene *scene = new DumbGL::Scene();
    scene->width = width;
    scene->height = height;
    scene->event = new SDL_Event();
    scene->window = SDL_CreateWindow(title,
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    scene->renderer = SDL_CreateRenderer(scene->window, -1, 0);
    scene->texture = SDL_CreateTexture(scene->renderer,
      SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);
    scene->pixels = new Uint32[width * height];
    memset(scene->pixels, 0, width * height * sizeof(Uint32));
    return scene;
  }

  Event *Draw(DumbGL::Scene *scene) {
    if (scene->event->type == SDL_QUIT ||
        (scene->event->type == SDL_KEYUP &&
          scene->event->key.keysym.scancode == SDL_SCANCODE_ESCAPE)) {
      Close(scene);
      exit(0);
    }
    SDL_RenderClear(scene->renderer);
    SDL_RenderCopy(scene->renderer, scene->texture, NULL, NULL);
    SDL_RenderPresent(scene->renderer);
    SDL_UpdateTexture(scene->texture,
      NULL,
      scene->pixels,
      scene->width * sizeof(Uint32));
    SDL_WaitEvent(scene->event);
    return scene->event;
  }

  Event *LastEvent(DumbGL::Scene *scene) {
    return scene->event;
  }

  void SetPixel(DumbGL::Scene *scene, int x, int y, int color) {
    scene->pixels[y * scene->width + x] = color;
  }

  int GetPixel(DumbGL::Scene *scene, int x, int y) {
    return scene->pixels[y * scene->width + x];
  }

  void Close(DumbGL::Scene *scene) {
    delete[] scene->pixels;
    SDL_DestroyTexture(scene->texture);
    SDL_DestroyRenderer(scene->renderer);
    SDL_DestroyWindow(scene->window);
    delete scene->event;
    delete scene;
    SDL_Quit();
  }

}
