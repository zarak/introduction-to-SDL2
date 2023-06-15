#include <iostream>

#include "glad/glad.h"
#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
  // Create a window data type
  SDL_Window *window = nullptr;

  // Typically we want error checking like this.
  // Not that tutorials often omit these detais.
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not be initialized" << SDL_GetError();
  } else {
    std::cout << "SDL video system is ready to go\n";
  }
  // Before we create our window, specify OpenGL version
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  window =
      SDL_CreateWindow("C++ SDL2 Window", 0, 0, 640, 480, SDL_WINDOW_OPENGL);

  // OpenGL graphics context
  SDL_GLContext context;
  context = SDL_GL_CreateContext(window);

  // Setup our function pointers
  gladLoadGLLoader(SDL_GL_GetProcAddress);

  // Infinite loop for our application
  bool gameIsRunning = true;
  while (gameIsRunning) {
    glViewport(0, 0, 640, 480);
    SDL_Event event;
    // Start our event loop
    while (SDL_PollEvent(&event)) {
      // Handle each specific event
      if (event.type == SDL_QUIT) {
        gameIsRunning = false;
      }

      if (event.type == SDL_MOUSEMOTION) {
        std::cout << "Mouse has been moved\n";
      }

      if (event.type == SDL_KEYDOWN) {
        std::cout << event.key.keysym.sym << " pressed\n";
      }

      if (event.key.keysym.sym == SDLK_q) {
        gameIsRunning = false;
      }

      const Uint8 *state = SDL_GetKeyboardState(NULL);
      if (state[SDL_SCANCODE_RIGHT]) {
        std::cout << "Right arrow key is pressed\n";
      }
    }

    // Where are we calling these functions from?
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    // Why did I need this?
    SDL_GL_SwapWindow(window);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
