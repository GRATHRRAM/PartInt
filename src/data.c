#define DATA_IMPLEMENTATION

#include <stdlib.h>
#include <stdint.h>
#include <raylib.h>

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

uint8_t Data_AllocParts(Parts Particles, size_t size) {
    Particles.particle = (Part*) calloc(size, sizeof(Part));
    if(Particles.particle == NULL) return 1;
    Particles.size = size;
    return 0;
}

void Data_FreeParts(Parts Particles) {
    free(Particles.particle);
    Particles.particle = 0;
}