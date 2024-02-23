#include <stdlib.h>
#include <raylib.h>
#include <time.h>
#include "src/strc.h"
#include "src/gravity.h"


#define Screen_Resolution_X 1000
#define Screen_Resolution_Y 800
#define Scale 20

void Random_Positions(Parts *prts);

int main(void) {
  InitWindow(Screen_Resolution_X, Screen_Resolution_Y, "PartInt - Exemple");
  SetTargetFPS(60);

  srand(time(NULL));

  Parts Particles;
  Particles.scale = Scale;
  Strc_AllocParts(&Particles, 2); 

  Random_Positions(&Particles);

  for(size_t i = 0; i < Particles.size; ++i) {
    Particles.particle[i].color = (Color){0,0,0,60};
    Particles.particle[i].mass = 1000000;
  }

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(LIGHTGRAY);

            for(size_t prt = 0; prt < Particles.size; ++prt)
              DrawRectangleV(Particles.particle[prt].Position, (Vector2){Particles.scale, Particles.scale}, Particles.particle[prt].color);

        EndDrawing();
        Vector2 mouse = GetMousePosition();
        //Grav_Applay2Point(mouse.x, mouse.y, 10, &Particles);
        //Grav_Applay2Point(Screen_Resolution_X /2, Screen_Resolution_Y/2, 10, &Particles);
        grav(&Particles.particle[0], Particles.particle[1]);
        Strc_MoveParts(&Particles, (Vector2){Screen_Resolution_X, Screen_Resolution_Y});
    }

  CloseWindow();
  Strc_FreeParts(&Particles);
  return 0;
}

void Random_Positions(Parts *prts) {
  for(size_t i = 0; i < prts->size; ++i) {
    prts->particle[i].Position.x = rand() % Screen_Resolution_X;
    prts->particle[i].Position.y = rand() % Screen_Resolution_Y;
  }
}