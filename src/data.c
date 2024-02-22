#define DATA_IMPLEMENTATION

#include <stdlib.h>
#include <stdint.h>
#include <raylib.h>

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

uint8_t Data_AllocParts(parts Particles, size_t size);
void Data_FreeParts(parts Particles);

uint8_t Data_AllocParts(parts Particles, size_t size) {
    Particles.particle = (part*) calloc(size, sizeof(part));
    if(Particles.particle == NULL) return 1;
    Particles.size = size;
    return 0;
}

void Data_FreeParts(parts Particles) {
    free(Particles.particle);
    Particles.particle = 0;
}