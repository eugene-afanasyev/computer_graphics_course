#define CATCH_CONFIG_MAIN

#include <glm/mat2x2.hpp>
#include <iostream>
#include "catch.hpp"
#include "../src/math/mat2.hpp"
#include "../src/math/vec2.hpp"

using Mat2 = cglm::Mat2;
using Vec2 = cglm::Vec2;

bool floatCmp(float a, float b) {
  return std::fabs(a - b) < 1e-7;
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
//    glm::mat2 glm_mat =
//      glm::mat2({3, 1}, {12, 14}) *
//      glm::mat2({123, 33}, {13.2f, 4.4f});

    Mat2 mat =
      Mat2{{3, 1}, {12, 14}} *
      Mat2{{123, 33}, {13.2f, 4.4f}};

    REQUIRE(floatCmp(382.2, mat[0].x));
    REQUIRE(floatCmp(103.4, mat[0].y));
    REQUIRE(floatCmp(1660.8, mat[1].x));
    REQUIRE(floatCmp(457.6, mat[1].y));
  }
}
