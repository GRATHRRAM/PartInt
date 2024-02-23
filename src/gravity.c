#define GRAVITY_IMPLEMENTATION
#include "strc.h"
#include <math.h>
#define G 0.5

void grav(Part *Part1, Part Part2);
Vector2 normalize(Vector2 v);

void grav(Part *Part1, Part Part2) {
    Vector2 fDirection = (Vector2){Part2.Position.x - Part1->Position.x, Part2.Position.y - Part1->Position.y};

    float dist = sqrt(fDirection.x * fDirection.x + fDirection.y * fDirection.y);

    if (dist < 200.0) {
        dist = 200.0;
    }

    float strength = (G * Part1->mass * Part2.mass) / (dist * dist);
    Vector2 nVec = normalize(fDirection);

    Vector2 force = (Vector2){nVec.x * strength, nVec.y * strength};

    Part1->Velocity.x += force.x * 5.0;
    Part1->Velocity.y += force.y * 5.0;
}

Vector2 normalize(Vector2 v) {
  float len = sqrt(v.x * v.x + v.y * v.y);
  return (Vector2){v.x / len, v.y / len};
}