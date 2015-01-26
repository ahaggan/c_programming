//Some functions taken from Neill_sdl.c with minor changes

#include "ashley_sdl.h"


void Neill_SDL_Init(SDL_Simplewin *sw)
{


   if (SDL_Init(SDL_INIT_VIDEO) != 0) {
      fprintf(stderr, "\nUnable to initialize SDL:  %s\n", SDL_GetError());
      SDL_Quit();
      exit(1);
   } 

   sw->finished = 0;
   
   sw->win= SDL_CreateWindow("Turtle",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          WINDOW_WIDTH, WINDOW_HEIGHT,
                          SDL_WINDOW_SHOWN);
   if(sw->win == NULL){
      fprintf(stderr, "\nUnable to initialize SDL Window:  %s\n", SDL_GetError());
      SDL_Quit();
      exit(1);
   }

   sw->renderer = SDL_CreateRenderer(sw->win, -1, 0);
   if(sw->renderer == NULL){
      fprintf(stderr, "\nUnable to initialize SDL Renderer:  %s\n", SDL_GetError());
      SDL_Quit();
      exit(1);
   }

   // Set screen to black
   Neill_SDL_SetDrawColour(sw, 0, 0, 0);
   SDL_RenderClear(sw->renderer);
   SDL_RenderPresent(sw->renderer);

}
void Neill_SDL_RenderDrawCircle(SDL_Renderer *rend, int cx, int cy, int r)
{

   double dx, dy;
   dx = floor(sqrt((2.0 * r ) ));
   SDL_RenderDrawLine(rend, cx-dx, cy+r, cx+dx, cy+r);
   SDL_RenderDrawLine(rend, cx-dx, cy-r, cx+dx, cy-r);
   for (dy = 1; dy <= r; dy += 1.0) {
        dx = floor(sqrt((2.0 * r * dy) - (dy * dy)));
        SDL_RenderDrawPoint(rend, cx+dx, cy+r-dy);
        SDL_RenderDrawPoint(rend, cx+dx, cy-r+dy);
        SDL_RenderDrawPoint(rend, cx-dx, cy+r-dy);
        SDL_RenderDrawPoint(rend, cx-dx, cy-r+dy);
   }

}
void draw_turtle(Prog *program){
    SDL_Simplewin sw;
    
    double startx, starty, endx, endy;
    Neill_SDL_Init(&sw);
    program->coordinate = &program->start_coordinate;
    do{
        //Checks the program still contains instruction to draw, otherwise the loop waits for the user to stop it.
        
        if(program->coordinate->next != NULL){ 
            startx = program->coordinate->current_x;
            
            starty = program->coordinate->current_y;
            
            program->coordinate = program->coordinate->next;
            endx = program->coordinate->current_x;
            
            endy = program->coordinate->current_y;
           
            Neill_SDL_SetDrawColour(&sw, 255, 255, 255);
            //printf("\nStart x: %lf", startx);
            //printf("\nStart y: %lf", starty);
            //printf("\nEnd x: %lf", endx);
            //printf("\nEnd y: %lf", endy);
            SDL_RenderDrawLine(sw.renderer, startx, starty, endx, endy);
            // Sleep for a short time
            SDL_Delay(MILLISECONDDELAY);

           
          

          
            // Update window - no graphics appear on some devices until this is finished
            SDL_RenderPresent(sw.renderer);
            SDL_UpdateWindowSurface(sw.win);
        }
      
      // Has anyone pressed ESC or killed the SDL window ?
      // Must be called frequently - it's the only way of escaping 
      Neill_SDL_Events(&sw);

   }while(!sw.finished);
}
// Gobble all events & ignore most
void Neill_SDL_Events(SDL_Simplewin *sw)
{
   SDL_Event event;
   while(SDL_PollEvent(&event)) 
   {      
       switch (event.type){
          case SDL_QUIT:
          case SDL_MOUSEBUTTONDOWN:
       case SDL_KEYDOWN:
         sw->finished = 1;
       }
    }
}


// Trivial wrapper to avoid complexities of renderer & alpha channels
void Neill_SDL_SetDrawColour(SDL_Simplewin *sw, Uint8 r, Uint8 g, Uint8 b)
{

   SDL_SetRenderDrawColor(sw->renderer, r, g, b, SDL_ALPHA_OPAQUE);

}
