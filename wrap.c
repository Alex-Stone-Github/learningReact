#include "wrap.h"

wrap_context wrap_init(unsigned int width, unsigned int height, const char* title) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Failed to initialize SDL2: %s\n", SDL_GetError());
    }
    wrap_context ctx;
    SDL_CreateWindowAndRenderer(
            width,
            height,
            0,
            &ctx.window,
            &ctx.renderer
            );
    return ctx;
}
void wrap_drawLine(wrap_context ctx, int x1, int y1, int x2, int y2) {
    SDL_RenderDrawLine(ctx.renderer, x1, y1, x2, y2);
}
void wrap_drawRect(wrap_context ctx, int x, int y, int width, int height) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    SDL_RenderFillRect(ctx.renderer, &rect);
}
void wrap_drawRectBorder(wrap_context ctx, int x, int y, int width, int height) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    SDL_RenderDrawRect(ctx.renderer, &rect);
}
void wrap_drawPoint(wrap_context ctx, int x, int y) {
    SDL_RenderDrawPoint(ctx.renderer, x, y);
}
void wrap_changeColor(wrap_context ctx, int r, int b, int g) {
    SDL_SetRenderDrawColor(ctx.renderer, r, g, b, SDL_ALPHA_OPAQUE);
}
void wrap_updateDisplay(wrap_context ctx) {
    SDL_RenderPresent(ctx.renderer);
}
void wrap_quit(wrap_context ctx) {
    SDL_DestroyRenderer(ctx.renderer);
    SDL_DestroyWindow(ctx.window);
}
