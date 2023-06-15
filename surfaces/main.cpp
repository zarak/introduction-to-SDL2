#include <iostream>

#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
  // Create a window data type
  SDL_Window *window = nullptr;

  // Grab the window surface
  SDL_Surface *screen = nullptr;

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

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  screen = SDL_GetWindowSurface(window);

  // Infinite loop for our application
  bool gameIsRunning = true;
  while (gameIsRunning) {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Event event;
    // Start our event loop
    while (SDL_PollEvent(&event)) {
      // Handle each specific event
      if (event.type == SDL_QUIT) {
        gameIsRunning = false;
      } else if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {
          std::cout << "Left mouse was pressed\n";

          SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
          SDL_FillRect(screen, NULL, 0);
        }
      }
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
