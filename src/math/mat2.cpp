#include "mat2.hpp"
#include "exception.hpp"

using Mat2 = cglm::Mat2;

Mat2::Mat2(float v) {
  rows_[0].x = v;
  rows_[1].y = v;
}

Mat2::Mat2(float v0, float v1) {
  rows_[0].x = v0;
  rows_[1].y = v1;
}

Mat2::Mat2(const Mat2::vec_type &diag_vec) {
  rows_[0].x = diag_vec.x;
  rows_[1].y = diag_vec.y;
}

Mat2::vec_type cglm::Mat2::get_row(uint32_t r) const {
  if (r < 0u || r > 1u)
    throw cglm::OutOfRangeException();
  else
    return rows_[r];
}

Mat2::vec_type cglm::Mat2::get_col(uint32_t c) const {
  if (c < 0u || c > 1u)
    throw cglm::OutOfRangeException();
  else
    if (c == 0)
      return {rows_[0].x, rows_[1].x};
    else
      return {rows_[0].y, rows_[1].y};
}

Mat2::vec_type cglm::Mat2::get_diag() const noexcept {
  return {rows_[0].x, rows_[1].y};
}

cglm::Mat2::Mat2(const cglm::Vec2 &r0, const cglm::Vec2 &r1) {
  rows_[0] = r0;
  rows_[1] = r1;
}

Mat2 cglm::Mat2::operator+(const Mat2 &src) const {
  return Mat2(
      rows_[0] + src.get_row(0),
      rows_[1] + src.get_row(1));
}

Mat2 cglm::Mat2::operator-(const Mat2 &src) const {
  return Mat2(
    rows_[0] - src.get_row(0),
    rows_[1] - src.get_row(1));
}

Mat2::vec_type cglm::Mat2::operator[](unsigned int r) const {
  if (0u > r || r > 1u)
    throw cglm::OutOfRangeException();
  else
    return rows_[r];
}

Mat2 cglm::Mat2::operator*(const Mat2 &src) const {
  Vec2 row0(rows_[0].x * src[0].x + rows_[0].y * src[1].x,
            rows_[0].x * src[0].y + rows_[0].y * src[1].y);

  Vec2 row1(rows_[1].x * src[0].x + rows_[1].y * src[1].x,
            rows_[1].x * src[0].y + rows_[1].y * src[1].y);

  return {row0, row1};
}
