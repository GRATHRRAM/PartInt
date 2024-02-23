#define STRC_IMPLEMENTATION

#include <stdlib.h>
#include <stdint.h>
#include <raylib.h>


typedef struct Part {
  Vector2 Position;
  Vector2 Velocity;
  uint32_t mass;
  Color color;
} Part;

typedef struct Parts {
 size_t size;
 uint16_t scale;
 Part *particle;
} Parts;

uint8_t Strc_AllocParts(Parts *Particles, size_t size);
void Strc_FreeParts(Parts *Particles);

void Strc_MoveParts(Parts *Particles, Vector2 ScreenBorders);

uint8_t Strc_AllocParts(Parts *Particles, size_t size) {
    Particles->particle = (Part*) calloc(size, sizeof(Part));
    if(Particles->particle == NULL) return 1;
    Particles->size = size;
    return 0;
}

void Strc_FreeParts(Parts *Particles) {
    free(Particles->particle);
    Particles->size = 0;
}

void Strc_MoveParts(Parts *Particles, Vector2 ScreenBorders) {
  for(size_t i = 0; i < Particles->size; ++i) {
    Particles->particle[i].Position.x += Particles->particle[i].Velocity.x; 
    Particles->particle[i].Position.y += Particles->particle[i].Velocity.y; 

    if (Particles->particle[i].Position.x - Particles->scale <= 0) Particles->particle[i].Velocity.x *= -1;
    if (Particles->particle[i].Position.x + Particles->scale >= ScreenBorders.x) Particles->particle[i].Velocity.x *= -1;
    if (Particles->particle[i].Position.y - Particles->scale <= 0) Particles->particle[i].Velocity.y *= -1;
    if (Particles->particle[i].Position.y + Particles->scale >= ScreenBorders.y) Particles->particle[i].Velocity.y *= -1;
  }
}
