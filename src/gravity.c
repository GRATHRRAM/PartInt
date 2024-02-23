#define GRAVITY_IMPLEMENTATION
#include "strc.h"
#include <math.h>

void Grav_Applay2Point(uint16_t PointX, uint16_t PointY, float mass, Parts *Particles);
float getDist(Vector2 pos,Vector2 otherPos);
Vector2 getNormal(Vector2 pos,Vector2 otherPos);

void Grav_Applay2Point(uint16_t PointX, uint16_t PointY, float mass, Parts *Particles) {
    for(size_t i = 0; i < Particles->size; ++i) { 
        float dist = fmax(getDist(Particles->particle[i].Position, (Vector2){PointX, PointY}), 1);
        Vector2 normal = getNormal(Particles->particle[i].Position, (Vector2){PointX, PointY});

        Particles->particle[i].Velocity.x -= (normal.x/dist) * 0.99;
        Particles->particle[i].Velocity.y -= (normal.y/dist) * 0.99;
    }
}

float getDist(Vector2 pos,Vector2 otherPos) {
    const float dx = pos.x - otherPos.x;
    const float dy = pos.y - otherPos.y;
    return sqrt((dx*dx) + (dy*dy));
}

Vector2 getNormal(Vector2 pos, Vector2 otherPos) {
    float dist = getDist(pos,otherPos);
    const float dx = pos.x - otherPos.x;
    const float dy = pos.y - otherPos.y;
    Vector2 normal = (Vector2){dx*(1/dist), dy*(1/dist)};
    return normal;
}