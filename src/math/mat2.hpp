#ifndef COMPUTER_GRAPHICS_COURSE_SRC_MATH_MAT2_HPP_
#define COMPUTER_GRAPHICS_COURSE_SRC_MATH_MAT2_HPP_

#include <array>
#include "vec2.hpp"

namespace cglm {

class Mat2 {
 public:
  using vec_type = cglm::Vec2;
  using vec_array = std::array<vec_type, 2>;

  // -- Constructors --
  Mat2() = default;
  explicit Mat2(float);
  explicit Mat2(vec_type const& diag_vec);
  Mat2(float, float);
  Mat2(const Vec2& r1, const Vec2& r2);

  Mat2(const Mat2&) = default;

  // -- Access --
  vec_type get_row(uint32_t r) const;  // access row
  vec_type get_col(uint32_t c) const;  // access column
  vec_type get_diag() const noexcept;
  vec_type operator[](unsigned r) const;

  // -- Binary arithmetic operations --
  Mat2 operator+(const Mat2&) const;
  Mat2 operator-(const Mat2&) const;
  Mat2 operator*(const Mat2&) const;
  Mat2 operator*(float) const;

 private:
  vec_array rows_;
};

}  // cglm

#endif //COMPUTER_GRAPHICS_COURSE_SRC_MATH_MAT2_HPP_
