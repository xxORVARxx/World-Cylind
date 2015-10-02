
#ifndef ITERFACE_DISPLAY_H
#define ITERFACE_DISPLAY_H



class Interface_display
{
 public:
 Interface_display() : m_clear_color(SDL_Color{0,40,80,255}) {}

  bool Make_display( SDL_Window* (&display), std::string s_title = "xxORVARxx", SDL_Point s_size = SDL_Point{480,320} )
  {
    m_title = s_title;
    m_size = s_size;
    // Setting up the SDL_Window:
    display = SDL_CreateWindow( m_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				m_size.x, m_size.y, SDL_WINDOW_RESIZABLE );
    if ( display == NULL ) {
      std::cout << "!! Failed to create window : " << SDL_GetError() << " !!\n";  
      return false;
    }
    return true;// All fine.
  }

  bool Make_renderer( SDL_Renderer* (&renderer), SDL_Window* display )
  {
    // Creating the SDL_Renderer:
    renderer = SDL_CreateRenderer( display, -1, SDL_RENDERER_ACCELERATED );
    if ( renderer == NULL ) {
      std::cout << "!! Failed to create renderer : " << SDL_GetError() << " !!\n";  
      return false;
    }
    return true;// All fine.
  }

  void Clear( SDL_Renderer* renderer ) 
  {
    SDL_SetRenderDrawColor( renderer, m_clear_color.r, m_clear_color.g, m_clear_color.b, m_clear_color.a );
    // Call at the beginning on every frame to clear the screen and make it ready for more:
    SDL_RenderClear( renderer );
  }
  void Present_on_screen( SDL_Renderer* renderer ) 
  {
    // Takes what you have drawn to the screen using SDL_Render* and actually puts it on the screen:
    SDL_RenderPresent( renderer );
  }

  void Set_clearing_color( SDL_Renderer* renderer, SDL_Color s_color )
  {
    m_clear_color = s_color;
    SDL_SetRenderDrawColor( renderer, s_color.r, s_color.g, s_color.b, s_color.a );
  }
  void Set_draw_color( SDL_Renderer* renderer, SDL_Color s_color )
  {
    SDL_SetRenderDrawColor( renderer, s_color.r, s_color.g, s_color.b, s_color.a );
  }

  std::string m_title;
  SDL_Point m_size;
  SDL_Color m_clear_color;
};



#endif
