#define GRAVITY_IMPLEMENTATION
#include "strc.h"
#include <math.h>
#define G 6.674e-11

void grav(Part *Part1, Part Part2);
Vector2 normalize(Vector2 v);

void grav(Part *Part1, Part Part2) {
    Vector2 forceDirection = (Vector2){Part1->Position.x - Part2.Position.x, Part1->Position.y - Part2.Position.y};

    float distanceSquared = forceDirection.x * forceDirection.x + forceDirection.y * forceDirection.y;
    float distance = sqrt(distanceSquared);

    // Unikamy dzielenia przez zero
    if (distance < 1.0f) {
        distance = 1.0f;
    }

    // Obliczanie siły grawitacyjnej zgodnie z prawem powszechnego ciążenia Newtona
    float strength = (G * Part1->mass * Part2.mass) / (distanceSquared);
    Vector2 force = (Vector2){normalize(forceDirection).x * strength, normalize(forceDirection).y * strength};
    
    Part1->Velocity.x += force.x;
    Part1->Velocity.y += force.y;
}

Vector2 normalize(Vector2 v) {
  float len = sqrt(v.x * v.x + v.y * v.y); // obliczenie odeglosci
  return (Vector2){v.x / len, v.y / len}; // vector do normalizacji
}