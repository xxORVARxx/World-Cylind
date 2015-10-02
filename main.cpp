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

#include "Interface_display.h"
#include "Interface_main.h"



int main( int argc, char* args[] )
{
  Interface_main interface;
  if ( ! interface.Init())
    return -1;
  if( ! interface.Make_display())
    return -1;



  while ( interface.m_game_loop )
    {
      interface.Inputs();
      interface.Render();
      SDL_Delay( 16 );
    }



  // --- Quit SDL ---
  // SDL_DestroyTexture( SDL_Texture* texture );

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
