#ifndef DATA_H
#define DATA_H

#include <stdint.h>
#include <raylib.h>
#include <stdlib.h>

//Part is shorted Particle (Stores basic info about Particle. position, color)
typedef struct Part {
  uint16_t x;
  uint16_t y;
  uint32_t mass;
  Color color;
} Part;

typedef struct Parts {
 size_t size;
 Part *particle;
} Parts;

uint8_t Data_AllocParts(Parts Particles, size_t size);
void Data_FreeParts(Parts Particles);

#endif //!DATA_H
