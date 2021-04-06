#include "mat4.hpp"
#include "exception.hpp"

using vec_type = cglm::Vec4;

Mat4::Mat4() {
  rows_[0] = {1, 0, 0, 0};
  rows_[1] = {0, 1, 0, 0};
  rows_[2] = {0, 0, 1, 0};
  rows_[3] = {0, 0, 0, 1};
}

Mat4::Mat4(float v) {
  rows_[0] = {v, 0, 0, 0};
  rows_[1] = {0, v, 0, 0};
  rows_[2] = {0, 0, v, 0};
  rows_[3] = {0, 0, 0, v};
}

Mat4::Mat4(const vec_type &diag_vec) {
  rows_[0] = {diag_vec.x, 0, 0, 0};
  rows_[1] = {0, diag_vec.y, 0, 0};
  rows_[2] = {0, 0, diag_vec.z, 0};
  rows_[3] = {0, 0, 0, diag_vec.w};
}

Mat4::Mat4(float v0, float v1, float v2, float v3) {
  rows_[0] = {v0, 0, 0, 0};
  rows_[1] = {0, v1, 0, 0};
  rows_[2] = {0, 0, v2, 0};
  rows_[3] = {0, 0, 0, v3};
}

Mat4::Mat4(const vec_type &r0, const vec_type &r1, const vec_type &r2, const vec_type &r3) {
  rows_[0] = r0;
  rows_[1] = r1;
  rows_[2] = r2;
  rows_[3] = r3;
}

vec_type Mat4::get_row(uint32_t r) const {
  if (r < 0u || r > 3u)
    throw cglm::OutOfRangeException();
  else
    return rows_[r];
}

vec_type Mat4::get_col(uint32_t c) const {
  if (c < 0u || c > 3u)
    throw cglm::OutOfRangeException();
  else if (c == 0)
    return {rows_[0].x, rows_[1].x, rows_[2].x, rows_[3].x};
  else if (c == 1)
    return {rows_[0].y, rows_[1].y, rows_[2].y, rows_[3].y};
  else if (c == 2)
    return {rows_[0].z, rows_[1].z, rows_[2].z, rows_[3].z};
  else
    return {rows_[0].w, rows_[1].w, rows_[2].w, rows_[3].w};
}

vec_type Mat4::get_diag() const noexcept {
  return {rows_[0].x, rows_[1].y, rows_[2].z, rows_[3].w};
}

vec_type Mat4::operator[](unsigned int r) const {
  if (r < 0u || r > 3u)
    throw cglm::OutOfRangeException();
  else
    return rows_[r];
}
