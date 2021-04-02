#define CATCH_CONFIG_MAIN

#include <glm/mat2x2.hpp>
#include <glm/ext/vector_int1.hpp>
#include <glm/ext/scalar_common.hpp>
#include <iostream>
#include "catch.hpp"
#include "../src/math/mat2.hpp"
#include "../src/math/vec2.hpp"
#include "../src/math/mat3.hpp"
#include "../src/math/vec3.hpp"

using Mat2 = cglm::Mat2;
using Vec2 = cglm::Vec2;
using Mat3 = cglm::Mat3;
using Vec3 = cglm::Vec3;

bool floatCmp(float a, float b) {
  return std::fabs(a - b) < 1e-5;
}

TEST_CASE("Mat2 constructors and accessors") {
  {
    Mat2 mat;

    REQUIRE(mat.get_row(0) == Vec2(1, 0));
    REQUIRE(mat.get_row(1) == Vec2(0, 1));

    REQUIRE(mat.get_col(0) == Vec2(1, 0));
    REQUIRE(mat.get_col(1) == Vec2(0, 1));

    REQUIRE(mat.get_diag() == Vec2(1, 1));
  }
  {
    Mat2 mat(3.14f);

    REQUIRE(mat.get_row(0) == Vec2(3.14f, 0));
    REQUIRE(mat.get_row(1) == Vec2(0, 3.14f));

    REQUIRE(mat.get_col(0) == Vec2(3.14f, 0));
    REQUIRE(mat.get_col(1) == Vec2(0, 3.14f));

    REQUIRE(mat.get_diag() == Vec2(3.14f, 3.14f));
  }

  {
    Mat2 mat(Vec2(3.14f, 3.14f));

    REQUIRE(mat.get_row(0) == Vec2(3.14f, 0));
    REQUIRE(mat.get_row(1) == Vec2(0, 3.14f));

    REQUIRE(mat.get_col(0) == Vec2(3.14f, 0));
    REQUIRE(mat.get_col(1) == Vec2(0, 3.14f));

    REQUIRE(mat.get_diag() == Vec2(3.14f, 3.14f));
  }

  {
    Mat2 mat(3.14f, 3.14f);

    REQUIRE(mat.get_row(0) == Vec2(3.14f, 0));
    REQUIRE(mat.get_row(1) == Vec2(0, 3.14f));

    REQUIRE(mat.get_col(0) == Vec2(3.14f, 0));
    REQUIRE(mat.get_col(1) == Vec2(0, 3.14f));

    REQUIRE(mat.get_diag() == Vec2(3.14f, 3.14f));
  }

  {
    Mat2 dst_mat(3.14f, 3.14f);
    Mat2 mat(dst_mat);

    REQUIRE(mat.get_row(0) == Vec2(3.14f, 0));
    REQUIRE(mat.get_row(1) == Vec2(0, 3.14f));

    REQUIRE(mat.get_col(0) == Vec2(3.14f, 0));
    REQUIRE(mat.get_col(1) == Vec2(0, 3.14f));

    REQUIRE(mat.get_diag() == Vec2(3.14f, 3.14f));
  }

  {
    Mat2 mat({3, 10},
             {12.3f, 11.2f});

    REQUIRE(mat.get_row(0) == Vec2(3, 10));
    REQUIRE(mat.get_row(1) == Vec2(12.3f, 11.2f));

    REQUIRE(mat.get_col(0) == Vec2(3, 12.3f));
    REQUIRE(mat.get_col(1) == Vec2(10, 11.2f));

    REQUIRE(mat.get_diag() == Vec2(3, 11.2f));
  }
}

TEST_CASE("Mat2 binary arithmetic operations") {
  {
    glm::mat2 glm_mat1({1, 2},
                      {3, 4});
    glm::mat2 glm_mat2({1, 2},
                       {3, 4});

    Mat2 mat1({1, 2},
             {3, 4});

    Mat2 mat2({1, 2},
             {3, 4});

    glm::mat2 glm_mat_result = glm_mat1 + glm_mat2;
    Mat2 mat_result = mat1 + mat2;

    REQUIRE(glm_mat_result[0].x == mat_result[0].x);
    REQUIRE(glm_mat_result[0].y == mat_result[0].y);
    REQUIRE(glm_mat_result[1].x == mat_result[1].x);
    REQUIRE(glm_mat_result[1].y == mat_result[1].y);
  }

  {
    glm::mat2 glm_mat1({1, 3.13f},
                       {11.1f, 4});
    glm::mat2 glm_mat2({1, 2},
                       {3.13f, 2.2f});

    Mat2 mat1({1, 3.13f},
              {11.1f, 4});

    Mat2 mat2({1, 2},
              {3.13f, 2.2f});

    glm::mat2 glm_mat_result = glm_mat1 - glm_mat2;
    Mat2 mat_result = mat1 - mat2;

    REQUIRE(glm_mat_result[0].x == mat_result[0].x);
    REQUIRE(glm_mat_result[0].y == mat_result[0].y);
    REQUIRE(glm_mat_result[1].x == mat_result[1].x);
    REQUIRE(glm_mat_result[1].y == mat_result[1].y);
  }
}

TEST_CASE("Mat2 multiplication") {
  {
    glm::mat2 glm_mat =
      glm::mat2({3, 12}, {1, 14}) *
      glm::mat2({123, 13.2f}, {33, 4.4f});

    Mat2 mat =
      Mat2{{3, 1}, {12, 14}} *
      Mat2{{123, 33}, {13.2f, 4.4f}};

    REQUIRE(floatCmp(glm_mat[0].x, mat[0].x));
    REQUIRE(floatCmp(glm_mat[1].x, mat[0].y));
    REQUIRE(floatCmp(glm_mat[0].y, mat[1].x));
    REQUIRE(floatCmp(glm_mat[1].y, mat[1].y));
  }
}

TEST_CASE("Mat2 multiplication on a number") {
  Mat2 mat =
    Mat2({3.14, 32.2f}, {100.1f, 1.11f}) * 10;

  REQUIRE(floatCmp(31.4f, mat[0].x));
  REQUIRE(floatCmp(322.0f, mat[0].y));
  REQUIRE(floatCmp(1001.0f, mat[1].x));
  REQUIRE(floatCmp(11.1f, mat[1].y));
}

TEST_CASE("Mat2 division on a number") {
  Mat2 mat =
    Mat2({3.14, 32.2f}, {100.1f, 1.11f}) / 10;

  REQUIRE(floatCmp(0.314f, mat[0].x));
  REQUIRE(floatCmp(3.220f, mat[0].y));
  REQUIRE(floatCmp(10.01f, mat[1].x));
  REQUIRE(floatCmp(0.111f, mat[1].y));
}

TEST_CASE("Mat2 sum and subtraction on a number") {
  {
    Mat2 mat = Mat2({10.14f, 10},
                    {14.3f, 12.2f}) + 10;

    REQUIRE(floatCmp(20.14f, mat[0].x));
    REQUIRE(floatCmp(20, mat[0].y));
    REQUIRE(floatCmp(24.3f, mat[1].x));
    REQUIRE(floatCmp(22.2f, mat[1].y));
  }

  {
    Mat2 mat = Mat2({10.14f, 10},
                    {14.3f, 12.2f}) - 5;

    REQUIRE(floatCmp(5.14f, mat[0].x));
    REQUIRE(floatCmp(5, mat[0].y));
    REQUIRE(floatCmp(9.3f, mat[1].x));
    REQUIRE(floatCmp(7.2f, mat[1].y));
  }
}

TEST_CASE("Mat2 multiplication on a Vec2") {
  Mat2 mat({9, 12.2},
           {23.3, 48});

  Vec2 vec(132, 22);

  Vec2 result = mat * vec;

  REQUIRE(floatCmp(result.x, 1456.4f));
  REQUIRE(floatCmp(result.y, 4131.5996f));
}

TEST_CASE("Mat2 inverse matrix") {
  {
    Mat2 inverted_mat = Mat2({10, 14}, {12.2, 2}).GetInverse();
    glm::mat2 glm_inverted_mat = glm::inverse(glm::mat2({10, 14}, {12.2, 2}));

    REQUIRE(floatCmp(glm_inverted_mat[0].x, inverted_mat[0].x));
    REQUIRE(floatCmp(glm_inverted_mat[0].y, inverted_mat[0].y));
    REQUIRE(floatCmp(glm_inverted_mat[1].x, inverted_mat[1].x));
    REQUIRE(floatCmp(glm_inverted_mat[1].y, inverted_mat[1].y));
  }

  {
    Mat2 inverted_mat = Mat2({22.2, 12.4}, {11.9, 43.4}).GetInverse();
    glm::mat2 glm_inverted_mat = glm::inverse(glm::mat2({22.2, 12.4}, {11.9, 43.4}));

    REQUIRE(floatCmp(glm_inverted_mat[0].x, inverted_mat[0].x));
    REQUIRE(floatCmp(glm_inverted_mat[0].y, inverted_mat[0].y));
    REQUIRE(floatCmp(glm_inverted_mat[1].x, inverted_mat[1].x));
    REQUIRE(floatCmp(glm_inverted_mat[1].y, inverted_mat[1].y));
  }
}

TEST_CASE("Mat2 transpose") {
  {
    Mat2 mat({10, 12}, {14, 22});
    glm::mat2 glm_mat({10, 12}, {14, 22});

    mat = mat.GetTransposed();
    glm_mat = glm::transpose(glm_mat);

    REQUIRE(floatCmp(glm_mat[0].x, mat[0].x));
    REQUIRE(floatCmp(glm_mat[0].y, mat[0].y));
    REQUIRE(floatCmp(glm_mat[1].x, mat[1].x));
    REQUIRE(floatCmp(glm_mat[1].y, mat[1].y));
  }

  {
    Mat2 mat({23.31, 2}, {94.1, 54});
    glm::mat2 glm_mat({23.31, 2}, {94.1, 54});

    mat = mat.GetTransposed();
    glm_mat = glm::transpose(glm_mat);

    REQUIRE(floatCmp(glm_mat[0].x, mat[0].x));
    REQUIRE(floatCmp(glm_mat[0].y, mat[0].y));
    REQUIRE(floatCmp(glm_mat[1].x, mat[1].x));
    REQUIRE(floatCmp(glm_mat[1].y, mat[1].y));
  }
}

TEST_CASE("Mat2 comparison") {
  {
    Mat2 mat0;
    Mat2 mat1(0);

    REQUIRE(mat0 != mat1);
  }

  {
    Mat2 mat0({10, 22}, {3.31, 97.2});
    Mat2 mat1({10, 22}, {3.31, 97.2});

    REQUIRE(mat0 == mat1);
  }

  {
    Mat2 mat0(10);
    Mat2 mat1(10);

    REQUIRE(mat0 == mat1);
  }

  {
    Mat2 mat0;
    Mat2 mat1(10);

    REQUIRE(mat0 != mat1);
  }
}

/// Mat3 test section

TEST_CASE("Mat3 constructors and accessors") {
  {
    Mat3 mat;

    REQUIRE(mat[0] == Vec3(1, 0, 0));
    REQUIRE(mat[1] == Vec3(0, 1, 0));
    REQUIRE(mat[2] == Vec3(0, 0, 1));

    REQUIRE(mat.get_row(0) == Vec3(1, 0, 0));
    REQUIRE(mat.get_row(1) == Vec3(0, 1, 0));
    REQUIRE(mat.get_row(2) == Vec3(0, 0, 1));

    REQUIRE(mat.get_col(0) == Vec3(1, 0, 0));
    REQUIRE(mat.get_col(1) == Vec3(0, 1, 0));
    REQUIRE(mat.get_col(2) == Vec3(0, 0, 1));

    REQUIRE(mat.get_diag() == Vec3(1, 1, 1));
  }

  {
    Mat3 mat(1.14);

    REQUIRE(mat[0] == Vec3(1.14, 0, 0));
    REQUIRE(mat[1] == Vec3(0, 1.14, 0));
    REQUIRE(mat[2] == Vec3(0, 0, 1.14));

    REQUIRE(mat.get_row(0) == Vec3(1.14, 0, 0));
    REQUIRE(mat.get_row(1) == Vec3(0, 1.14, 0));
    REQUIRE(mat.get_row(2) == Vec3(0, 0, 1.14));

    REQUIRE(mat.get_col(0) == Vec3(1.14, 0, 0));
    REQUIRE(mat.get_col(1) == Vec3(0, 1.14, 0));
    REQUIRE(mat.get_col(2) == Vec3(0, 0, 1.14));

    REQUIRE(mat.get_diag() == Vec3(1.14, 1.14, 1.14));
  }

  {
    Mat3 mat(Vec3(1.14, 12.22, 99.3));

    REQUIRE(mat[0] == Vec3(1.14, 0, 0));
    REQUIRE(mat[1] == Vec3(0, 12.22, 0));
    REQUIRE(mat[2] == Vec3(0, 0, 99.3));

    REQUIRE(mat.get_row(0) == Vec3(1.14, 0, 0));
    REQUIRE(mat.get_row(1) == Vec3(0, 12.22, 0));
    REQUIRE(mat.get_row(2) == Vec3(0, 0, 99.3));

    REQUIRE(mat.get_col(0) == Vec3(1.14, 0, 0));
    REQUIRE(mat.get_col(1) == Vec3(0, 12.22, 0));
    REQUIRE(mat.get_col(2) == Vec3(0, 0, 99.3));

    REQUIRE(mat.get_diag() == Vec3(1.14, 12.22, 99.3));
  }

  {
    Mat3 mat(1.14, 12.22, 99.3);

    REQUIRE(mat[0] == Vec3(1.14, 0, 0));
    REQUIRE(mat[1] == Vec3(0, 12.22, 0));
    REQUIRE(mat[2] == Vec3(0, 0, 99.3));

    REQUIRE(mat.get_row(0) == Vec3(1.14, 0, 0));
    REQUIRE(mat.get_row(1) == Vec3(0, 12.22, 0));
    REQUIRE(mat.get_row(2) == Vec3(0, 0, 99.3));

    REQUIRE(mat.get_col(0) == Vec3(1.14, 0, 0));
    REQUIRE(mat.get_col(1) == Vec3(0, 12.22, 0));
    REQUIRE(mat.get_col(2) == Vec3(0, 0, 99.3));

    REQUIRE(mat.get_diag() == Vec3(1.14, 12.22, 99.3));
  }

  {
    Mat3 mat(
      {1.14, 0, 0},
      {0, 12.22, 0},
      {0, 0, 99.3});

    REQUIRE(mat[0] == Vec3(1.14, 0, 0));
    REQUIRE(mat[1] == Vec3(0, 12.22, 0));
    REQUIRE(mat[2] == Vec3(0, 0, 99.3));

    REQUIRE(mat.get_row(0) == Vec3(1.14, 0, 0));
    REQUIRE(mat.get_row(1) == Vec3(0, 12.22, 0));
    REQUIRE(mat.get_row(2) == Vec3(0, 0, 99.3));

    REQUIRE(mat.get_col(0) == Vec3(1.14, 0, 0));
    REQUIRE(mat.get_col(1) == Vec3(0, 12.22, 0));
    REQUIRE(mat.get_col(2) == Vec3(0, 0, 99.3));

    REQUIRE(mat.get_diag() == Vec3(1.14, 12.22, 99.3));
  }
}
