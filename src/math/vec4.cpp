#include "vec4.hpp"

Vec4::Vec4() : x(0), y(0), z(0), w(0) {}

Vec4::Vec4(float value) : x(value), y(value), z(value), w(value) {}

Vec4::Vec4(float x, float y, float z, float w) :  x(x), y(y), z(z), w(w) {}

Vec4::Vec4(const Vec4 &src) {
  x = src.x;
  y = src.y;
  z = src.z;
  w = src.w;
}

Vec4::Vec4(Vec4 &&src) noexcept {
  x = src.x;
  y = src.y;
  z = src.z;
  w = src.w;
}

bool Vec4::operator==(const Vec4 &other) const {
  return (
    x == other.x &&
    y == other.y &&
    z == other.z &&
    w == other.w);
}

bool Vec4::operator!=(const Vec4 &other) const {
  return (
    x != other.x ||
    y != other.y ||
    z != other.z ||
    w != other.w);
}

Vec4 Vec4::operator+(const Vec4 &src) const {
  return {x + src.x, y + src.y, z + src.z, w + src.w};
}

Vec4 Vec4::operator-(const Vec4 &src) const {
  return {x - src.x, y - src.y, z - src.z, w - src.w};
}

Vec4 Vec4::operator*(float v) const {
  return {x * v, y * v, z * v, w * v};
}

Vec4 Vec4::operator/(float v) const {
  return {x / v, y / v, z / v, w / v};
}

Vec4 &Vec4::operator+=(const Vec4 &src) {
  x += src.x;
  y += src.y;
  z += src.z;
  w += src.w;
  return *this;
}

Vec4 &Vec4::operator-=(const Vec4 &src) {
  x -= src.x;
  y -= src.y;
  z -= src.z;
  w -= src.w;
  return *this;
}

Vec4 &Vec4::operator=(const Vec4 &src) = default;
