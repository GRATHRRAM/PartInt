#include <stdlib.h>
#include <raylib.h>

#define Screen_Resolution_X 500
#define Screen_Resolution_Y 800

int main(void) {
  InitWindow(Screen_Resolution_X, Screen_Resolution_Y, "PartInt - Exemple");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);

            

        EndDrawing();
    }
    CloseWindow();
  return 0;
}
