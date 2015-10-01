/* 
 * apt-cache search libsdl2
 * sudo apt-get install libglew-dev
 * sudo apt-get install libglm-dev
 * sudo apt-get install git
 *
 * http://headerphile.com/sdl2/sdl2-part-2-your-first-sdl2-application/
 *
 * g++ -std=c++11 -o test  *.cpp  -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf -lGL -lGLEW
 */

#include <GL/glew.h>

#define GLM_FORCE_CXX11 
#include <glm/glm.hpp>

#include "SDL2/SDL.h" // SDL.
#include "SDL2/SDL_opengl.h" // GL.
#include "SDL2/SDL_image.h" // SDL image.
#include "SDL2/SDL_ttf.h" // SDL TrueType Fonts.

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <math.h>

#include <iterator>
#include <algorithm>
#include <numeric> // some numeric algorthm.
#include <functional>



SDL_Window* display;
SDL_Renderer* renderer;

bool Make_display( std::string display_title, SDL_Point display_size )
{
  // Initializing_SDL2:
  if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) {
    std::cout << "!! Failed to initialize SDL : " << SDL_GetError() << " !!\n";  
    return false;
  }
  // Setting up the SDL_Window:
  display = SDL_CreateWindow( display_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				display_size.x, display_size.y, 0 );
  if ( display == NULL ) {
    std::cout << "!! Failed to create window : " << SDL_GetError() << " !!\n";  
    return false;
  }
  // Creating the SDL_Renderer:
  renderer = SDL_CreateRenderer( display, -1, SDL_RENDERER_ACCELERATED );
  if ( renderer == NULL ) {
    std::cout << "!! Failed to create renderer : " << SDL_GetError() << " !!\n";  
    return false;
  }
  return true;// All fine.
}

void Clear() {
  SDL_SetRenderDrawColor( renderer, 0, 40, 80, 255 );
  // Call at the beginning on every frame to clear the screen and make it ready for more:
  SDL_RenderClear( renderer );
}
void Present_on_screen() {
  // Takes what you have drawn to the screen using SDL_Render* and actually puts it on the screen:
  SDL_RenderPresent( renderer );
}
void Set_color( glm::uvec4 s_color = glm::uvec4()) {
  SDL_SetRenderDrawColor( renderer, s_color.x, s_color.y, s_color.z, s_color.w );
}



int main( int argc, char* args[] )
{
  std::string display_title = "Simple";
  SDL_Point display_size = { 720, 480 };

  if( ! Make_display( display_title, display_size ))
    return -1;// Error!

  bool loop = true;
  SDL_Event event;
  while ( loop )
    {
      // --- Input Handling ---
      while ( SDL_PollEvent( &event ))
	{
	  if ( event.type == SDL_QUIT )
	    loop = false;
	}

      // --- Logic ---




      // --- Rendering ---
      Clear();



      Present_on_screen();
      SDL_Delay( 16 );
    }

  // --- Quit SDL ---
  // SDL_DestroyTexture( SDL_Texture* texture );
  SDL_DestroyRenderer( renderer );
  SDL_DestroyWindow( display );
  SDL_Quit();
  return 1;
}

/* Open GL:
GLboolean   1+

GLbyte      8
GLubyte     8

GLshort     16
GLushort    16

GLint       32
GLuint      32

GLint64     64
GLuint64    64
*/

/* SDL:
Uint8
Uint16
Uint32

Sint32
*/
