#include <cmath>
#include "vec2.hpp"

Vec2::Vec2() : x(0.0f), y(0.0f) {}

Vec2::Vec2(float value) : x(value), y(value) {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec2::Vec2(const Vec2 &src) {
  x = src.x;
  y = src.y;
}

Vec2::Vec2(Vec2 &&src)  noexcept {
  x = src.x;
  y = src.y;
}

bool Vec2::operator==(const Vec2 &src) const {
  return x == src.x && y == src.y;
}

bool Vec2::operator!=(const Vec2 &src) const {
  return !(*this == src);
}

Vec2 Vec2::operator+(const Vec2 &src) const {
  return Vec2(x + src.x, y + src.y);
}

Vec2 Vec2::operator-(const Vec2 &src) const {
  return Vec2(x - src.x, y - src.y);
}

float Vec2::length() const {
  return sqrtf(powf(x, 2) + powf(y, 2));
}

float Vec2::operator*(const Vec2 &src) const {
  return x * src.x + y * src.y;
}

Vec2 Vec2::operator*(float value) const {
  return {x * value, y * value};
}

Vec2 Vec2::operator/(float value) const {
  return {x / value, y / value};
}

Vec2& Vec2::operator=(const Vec2 &src) = default;

Vec2 &Vec2::operator+=(const Vec2 &src) {
  x += src.x;
  y += src.y;
  return *this;
}

Vec2 &Vec2::operator-=(const Vec2 &src) {
  x -= src.x;
  y -= src.y;
  return *this;
}

Vec2 &Vec2::operator*=(float value) {
  x *= value;
  y *= value;
  return *this;
}

Vec2 &Vec2::operator/=(float value) {
  x /= value;
  y /= value;
  return *this;
}

Vec2 Vec2::normalize() const {
  float inv_length = 1.0f / length();
  return Vec2(*this) * inv_length;
}
