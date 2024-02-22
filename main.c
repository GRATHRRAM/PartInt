#include <stdlib.h>
#include <raylib.h>
#include <time.h>
#include "src/data.h"

//debug
#include <stdio.h>
//!debug

#define Screen_Resolution_X 500
#define Screen_Resolution_Y 800

void Random_Positions(Parts prts);

int main(void) {
  InitWindow(Screen_Resolution_X, Screen_Resolution_Y, "PartInt - Exemple");
  SetTargetFPS(60);

  srand(time(NULL));

  Parts Particles = {0};
  Data_AllocParts(Particles, 100); 

  for(size_t i = 0; i < Particles.size; ++i) {
    Particles.particle[i].color = (Color){0,0,0,255};
    Particles.particle[i].mass = 1;
  }

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(LIGHTGRAY);

            for(size_t prt = 0; prt < Particles.size; ++prt) {
              DrawPixel(Particles.particle[prt].x,
              Particles.particle[prt].y,
              Particles.particle[prt].color);
              //DrawCircle(0,0,110,BLACK);
            }

        EndDrawing();
    }

  CloseWindow();
  Data_FreeParts(Particles);
  return 0;
}

void Random_Positions(Parts prts) {
  for(size_t i = 0; i < prts.size; ++i) {
    prts.particle[i].x = rand() % Screen_Resolution_X;
    prts.particle[i].y = rand() % Screen_Resolution_Y;
  }
}