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
