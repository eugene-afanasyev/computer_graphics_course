#include "vec2.h"

Vec2::Vec2() : x(0.0f), y(0.0f) {}

Vec2::Vec2(float value) : x(value), y(value) {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec2::Vec2(const Vec2 &src) {
  x = src.x;
  y = src.y;
}

Vec2::Vec2(Vec2 &&src) {
  x = src.x;
  y = src.y;
}
