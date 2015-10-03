
#include "Init.h"
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
