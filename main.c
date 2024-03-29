#include <stdlib.h>
#include <raylib.h>
#include <time.h>
#include "src/strc.h"
#include "src/gravity.h"
#include <stdio.h>


#define Screen_Resolution_X 1000
#define Screen_Resolution_Y 800
#define Scale 2

void Random_Positions(Parts *prts);

int main(void) {
  InitWindow(Screen_Resolution_X, Screen_Resolution_Y, "PartInt - Exemple");
  SetTargetFPS(60);

  srand(time(NULL));

  Parts Particles;
  Particles.scale = Scale;
  Strc_AllocParts(&Particles, 100000);

  Random_Positions(&Particles);

  for(size_t i = 0; i < Particles.size; ++i) {
    Particles.particle[i].color = (Color){0,0,0,128};
    Particles.particle[i].mass = 1;
  }
  

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(GRAY);

            for(size_t prt = 0; prt < Particles.size; ++prt)
              DrawRectangleV(Particles.particle[prt].Position, (Vector2){Particles.scale, Particles.scale}, Particles.particle[prt].color);

        EndDrawing();
        Vector2 mouse_pos = GetMousePosition();
        Part mouse;
        mouse.mass = 100;
        mouse.Position = mouse_pos;
        //Grav_Applay2Point(mouse.x, mouse.y, 10, &Particles);
        //Grav_Applay2Point(Screen_Resolution_X /2, Screen_Resolution_Y/2, 10, &Particles);
        for(size_t i = 0; i < Particles.size; ++i) {
          grav(&Particles.particle[i], mouse);
        }
        //grav(&Particles.particle[0], Particles.particle[1]);
        //grav(&Particles.particle[1], Particles.particle[0]);

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
