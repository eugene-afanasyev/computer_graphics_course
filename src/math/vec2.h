#ifndef COMPUTER_GRAPHICS_COURSE_SRC_MATH_VEC2_H_
#define COMPUTER_GRAPHICS_COURSE_SRC_MATH_VEC2_H_

#include <memory>

class Vec2 {
 public:
  Vec2();
  explicit Vec2(float);
  Vec2(float, float);

  Vec2(const Vec2&);
  Vec2(Vec2 &&);

  ~Vec2() = default;

  void operator=(const Vec2 &);
  bool operator==(const Vec2 &);
  bool operator!=(const Vec2 &);

  Vec2 operator+(const Vec2 &) const;
  Vec2 operator-(const Vec2 &) const;
  Vec2 operator*(const Vec2 &) const;  // scalar multiplication

  Vec2 operator*(float) const;  // multiplication with number
  Vec2 operator/(float) const;

  Vec2& operator+=(const Vec2 &);
  Vec2& operator-=(const Vec2 &);
  Vec2& operator*=(const Vec2 &);

  Vec2& operator*=(float);
  Vec2& operator/=(float);

  float length() const;

  Vec2 Normalize() const;

  float x, y;
};

#endif  //COMPUTER_GRAPHICS_COURSE_SRC_MATH_VEC2_H_

