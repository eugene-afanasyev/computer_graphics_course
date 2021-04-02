#include "mat3.hpp"

using vec_type = cglm::Mat3::vec_type;

cglm::Mat3::Mat3() {
  rows_[0] = {1, 0, 0};
  rows_[1] = {0, 1, 0};
  rows_[2] = {0, 0, 1};
}

cglm::Mat3::Mat3(float v) {
  rows_[0].x = v;
  rows_[1].y = v;
  rows_[2].z = v;
}

cglm::Mat3::Mat3(const vec_type &diag_vec) {
  rows_[0].x = diag_vec.x;
  rows_[1].y = diag_vec.y;
  rows_[2].z = diag_vec.z;
}

cglm::Mat3::Mat3(float v0, float v1, float v2) {
  rows_[0].x = v0;
  rows_[1].y = v1;
  rows_[2].z = v2;
}

cglm::Mat3::Mat3(const vec_type& r0, const vec_type& r1, const vec_type& r2) {
  rows_[0] = r0;
  rows_[1] = r1;
  rows_[2] = r2;
}
