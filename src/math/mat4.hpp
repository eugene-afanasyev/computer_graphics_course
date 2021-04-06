#ifndef COMPUTER_GRAPHICS_COURSE_SRC_MATH_MAT4_HPP_
#define COMPUTER_GRAPHICS_COURSE_SRC_MATH_MAT4_HPP_

#include <array>
#include "vec4.hpp"

class Mat4 {
 public:
  using vec_type = cglm::Vec4;
  using vec_array = std::array<vec_type, 4>;

  //  -- Constructors --
  Mat4();
  explicit Mat4(float v);
  explicit Mat4(vec_type const& diag_vec);
  Mat4(float, float, float, float);
  Mat4(const vec_type& r0, const vec_type& r1,
       const vec_type& r2, const vec_type& r3);

  // -- Accessors --
  vec_type get_row(uint32_t r) const;
  vec_type get_col(uint32_t c) const;
  vec_type get_diag() const noexcept;
  vec_type operator[](unsigned r) const;

 private:
  vec_array rows_;
};

#endif //COMPUTER_GRAPHICS_COURSE_SRC_MATH_MAT4_HPP_
