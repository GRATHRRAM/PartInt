#ifndef STRC_H
#define STRC_H

#include <stdint.h>
#include <raylib.h>
#include <stdlib.h>

//Part is shorted Particle (Stores basic info about Particle. position, color)
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

void Strc_MoveParts_Center(Parts *Particles, Vector2 ScreenBorders, Vector2 Center);

#endif //!DATA_H
