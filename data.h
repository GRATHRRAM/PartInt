#ifndef DATA_H
#define DATA_H

#include <stdint.h>
#include <raylib.h>
#include <stdlib.h>

//Part is shorted Particle (Stores basic info about Particle. position, color)
typedef struct part {
  uint16_t x;
  uint16_t y;
  uint32_t mass;
  Color color;
} part;

typedef struct parts {
 size_t size;
 part *particle;
} parts;

void Data_AllocParts(parts Particles, size_t size);
void Data_FreeParts(parts Particles);
#endif //!DATA_H
