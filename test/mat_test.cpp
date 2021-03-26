#define CATCH_CONFIG_MAIN

#include <glm/mat2x2.hpp>
#include <glm/ext/vector_int1.hpp>
#include <glm/ext/scalar_common.hpp>
#include <iostream>
#include "catch.hpp"
#include "../src/math/mat2.hpp"
#include "../src/math/vec2.hpp"

using Mat2 = cglm::Mat2;
using Vec2 = cglm::Vec2;

bool floatCmp(float a, float b) {
  return std::fabs(a - b) < 1e-5;
}

TEST_CASE("Mat2 constructors and accessors") {
  {
    Mat2 mat;

    REQUIRE(mat.get_row(0) == Vec2());
    REQUIRE(mat.get_row(1) == Vec2());

    REQUIRE(mat.get_col(0) == Vec2());
    REQUIRE(mat.get_col(1) == Vec2());

    REQUIRE(mat.get_diag() == Vec2());
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
