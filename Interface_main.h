
#ifndef ITERFACE_MAIN_H
#define ITERFACE_MAIN_H



class Interface_main
{
 public:
  Interface_main()
    {
      m_game_loop = true;
      m_display = NULL;
      m_renderer = NULL;
    }
  ~Interface_main()
    {
      SDL_DestroyRenderer( m_renderer );
      SDL_DestroyWindow( m_display );
      SDL_Quit();
    }

  bool Init()
  {
    // Initializing_SDL2:
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) {
      std::cout << "!! Failed to initialize SDL : " << SDL_GetError() << " !!\n";  
      return false;
    }
    return true;
  }

  bool Make_display()
  {
    // SDL_Window:
    if( ! the_display.Make_display( m_display, "World Cylind", SDL_Point{ 720, 480 } ))
      return false;
    // SDL_Renderer:
    if( ! the_display.Make_renderer( m_renderer, m_display ))
      return false;

    the_display.Set_clearing_color(  m_renderer, SDL_Color{ 0, 0, 0, 255 } );
    SDL_SetWindowMinimumSize( m_display, 480, 320 );
    SDL_SetCursor ( SDL_CreateSystemCursor( SDL_SYSTEM_CURSOR_CROSSHAIR ));

    return true;
  }

  // --- Input Handling ---
  void Inputs()
  {
    SDL_Event event;
    while ( SDL_PollEvent( &event ))
      {
	switch (event.type) 
	  {
	    // --- QUIT ---
	  case SDL_QUIT : 
	    m_game_loop = false;
	    break;
	    // --- KEYBOARD ---
	  case SDL_KEYDOWN:
	    break;
	  case SDL_KEYUP:
	    break;
	    // --- MOUSE --- 
	  case SDL_MOUSEMOTION:
	    break;
	  case SDL_MOUSEBUTTONDOWN:
	    break;
	  case SDL_MOUSEBUTTONUP:
	    break;
	  case SDL_MOUSEWHEEL:
	    break;
	    // --- WINDOW ---
	  case SDL_WINDOWEVENT : 
	    switch (event.window.event)
	      {
	      case SDL_WINDOWEVENT_SIZE_CHANGED: 
		the_display.m_size.x = event.window.data1;// Width
		the_display.m_size.y = event.window.data2;// Height
		break;
	      case SDL_WINDOWEVENT_CLOSE: 
		event.type = SDL_QUIT;
		SDL_PushEvent(&event);
		break;
	      }//switch-end
	    break;
	  }//switch-end
      }//while-end
  }

  // --- Logic ---

  // --- Rendering ---
  void Render()
  {
    the_display.Clear( m_renderer );

    the_display.Present_on_screen( m_renderer );
  }


  bool m_game_loop;

  Interface_display the_display;

  SDL_Window* m_display;
  SDL_Renderer* m_renderer;
};



#endif
