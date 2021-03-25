#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../src/math/mat2.hpp"
#include "../src/math/vec2.hpp"

using Mat2 = cglm::Mat2;
using Vec2 = cglm::Vec2;

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
}


