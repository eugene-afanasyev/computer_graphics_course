#include "vec3.hpp"

Vec3::Vec3() : x(0), y(0), z(0) {}

Vec3::Vec3(float value) : x(value), y(value), z(value) {}

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z)  {}

Vec3::Vec3(const Vec3 &src) {
  x = src.x;
  y = src.y;
  z = src.z;
}

Vec3::Vec3(Vec3 &&src) noexcept {
  x = src.x;
  y = src.y;
  z = src.z;
}

