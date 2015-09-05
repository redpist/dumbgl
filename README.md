Dumb Graphic Library
====================

> A stupidly simple graphic library.

Basically a C/C++ _SDL2_ wrapper for educational purpose, only gives some primitives like opening a window or printing a single pixel.

Installation
------------

1. DumbGL depends of SDL2, you need to apt-get/brew install it.

2. Compile from master:

```bash
git clone https://github.com/redpist/dumbgl
cd dumbgl
make install
```

Usage
-----


### Compile your project with DumbGL

#### C

```bash
gcc main.c $(dumbgl-config) -o uber-cool-game
# OR
gcc main.c $(dumbgl-cflags) -o main.o
gcc main.o $(dumbgl-lib) -o uber-cool-game
```

#### C++

```bash
g++ main.cc $(dumbgl-config) -o uber-cool-game
# OR
g++ main.cc $(dumbgl-cflags) -o main.o
g++ main.o $(dumbgl-lib) -o uber-cool-game
```

### Main functions

#### Open

Open a new window and return and pointer to a `Scene` structure (needed by every other functions).

```c++
// C
DumbGLScene *DumbGLOpen(const char *title, const int width, const int height);
// C++
DumbGL::Scene *DumbGL::Open(const char *title, const int width, const int height);
```

#### Draw

Update the window content from your Scene.

```c++
// C
DumbGLEvent *DumbGLDraw(DumbGLScene *scene);
// C++
DumbGL::Event *DumbGL::Draw(DumbGL::Scene *scene);
```

#### SetPixel

Change the color of a pixel of your Scene.

```c++
// C
void DumbGLSetPixel(DumbGLScene *scene, int x, int y, int color);
// C++
void DumbGL::SetPixel(DumbGL::Scene *scene, int x, int y, int color);
```

#### GetPixel

Get the color of a pixel of your Scene.

```c++
// C
int DumbGLGetPixel(DumbGLScene *scene, int x, int y);
// C++
int DumbGL::GetPixel(DumbGL::Scene *scene, int x, int y);
```

#### Close

Close your window.

```c++
// C
void DumbGLClose(DumbGLScene *scene);
// C++
void DumbGL::Close(DumbGL::Scene *scene);
```

### Example

A very simple program opening a 800px/800px black filled window with a red pixel at (x, y) = (20, 20).

#### C

```c
  #include "dumbgl.h"

  int main()
  {
    DumbGLScene *scene;
    scene = DumbGLOpen("DumbGL Example", 800, 800);
    DumbGLSetPixel(scene, 20, 20, 0xff0000);
    while (1)
      DumbGLDraw(scene);
    DumbGLClose(scene);
    return 0;
  }
```

#### C++

```c++
  #include <dumbgl.h>

  int main()
  {
    DumbGL::Scene *scene;
    scene = DumbGL::Open("DumbGL Example", 800, 800);
    DumbGL::SetPixel(scene, 20, 20, 0xff0000);
    while (true)
      DumbGL::Draw(scene);
    DumbGL::Close(scene);
    return 0;
  }
```

Credits
-------

DumbGL was written by Jérémy Lecerf and is under the [MIT license](LICENSE.md).

[SDL2](https://www.libsdl.org/download-2.0.php) was released under the [zlib license](https://www.libsdl.org/license.php).
