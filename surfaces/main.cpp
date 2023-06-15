#include <iostream>

#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
  // Create a window data type
  SDL_Window *window = nullptr;

  // Grab the window surface
  SDL_Surface *screen;

  // Typically we want error checking like this.
  // Not that tutorials often omit these detais.
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not be initialized" << SDL_GetError();
  } else {
    std::cout << "SDL video system is ready to go\n";
  }

  window =
      SDL_CreateWindow("C++ SDL2 Window", 20, 20, 640, 480, SDL_WINDOW_SHOWN);

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  screen = SDL_GetWindowSurface(window);

  // Infinite loop for our application
  bool gameIsRunning = true;
  while (gameIsRunning) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    // SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Event event;
    // Start our event loop
    while (SDL_PollEvent(&event)) {
      // Handle each specific event
      if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_q) {
        gameIsRunning = false;
      }

      if (event.button.button == SDL_BUTTON_LEFT) {
        std::cout << "Left mouse was pressed\n";

        // SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255,
        // 255)); SDL_UpdateWindowSurface(window);

        SDL_LockSurface(screen);
        // SDL_memset(screen->pixels, 255, screen->h * screen->pitch);
        SDL_FillRect(screen, NULL, 0);

        SDL_UnlockSurface(screen);

        SDL_UpdateWindowSurface(window);
      }
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
