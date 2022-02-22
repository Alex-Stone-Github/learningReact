#ifndef WRAP_H
#define WRAP_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct wrap_context {
    SDL_Window* window;
    SDL_Renderer* renderer;
} wrap_context;

wrap_context wrap_init(unsigned int width, unsigned int height, const char* title);
void wrap_drawRect(wrap_context ctx, int x, int y, int width, int height);
void wrap_drawRectBorder(wrap_context ctx, int x, int y, int width, int height);
void wrap_drawPoint(wrap_context ctx, int x, int y);
void wrap_drawLine(wrap_context ctx, int x1, int y1, int x2, int y2);
void wrap_changeColor(wrap_context ctx, int r, int b, int g);
void wrap_updateDisplay(wrap_context ctx);
void wrap_quit(wrap_context ctx);

#endif // WRAP_H
