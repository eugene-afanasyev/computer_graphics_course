#ifndef COMPUTER_GRAPHICS_COURSE_SRC_MATH_MAT3_HPP_
#define COMPUTER_GRAPHICS_COURSE_SRC_MATH_MAT3_HPP_

#include <array>
#include "vec3.hpp"

namespace cglm {

class Mat3 {
 public:
  using vec_type = cglm::Vec3;
  using vec_array = std::array<vec_type, 3>;

  //  -- Constructors --
  Mat3();
  explicit Mat3(float v);
  explicit Mat3(vec_type const& diag_vec);
  Mat3(float, float, float);
  Mat3(const vec_type& r0, const vec_type& r1, const vec_type& v2);

 private:
  vec_array rows_;
};

}  // namespace cglm

#endif //COMPUTER_GRAPHICS_COURSE_SRC_MATH_MAT3_HPP_
