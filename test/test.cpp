#define CATCH_CONFIG_MAIN

#define EPSILON 1e-5

#include "catch.hpp"
#include "../src/math/vec2.h"

#include <cmath>
#include <glm/ext/vector_float2.hpp>

bool floatCmp(float a, float b) {
  return std::fabs(a - b) < EPSILON;
}

TEST_CASE("Vec2 initialization") {
  {
    glm::vec2 glm_vec{};
    Vec2 custom_vec;

    REQUIRE(glm_vec.x == custom_vec.x);
    REQUIRE(glm_vec.y == custom_vec.y);
  }

  {
    glm::vec2 glm_vec(1.1f);
    Vec2 custom_vec(1.1f);

    REQUIRE(glm_vec.x == custom_vec.x);
    REQUIRE(glm_vec.y == custom_vec.y);
  }

  {
    glm::vec2 glm_vec(3.14f, 1.77f);
    Vec2 custom_vec(3.14f, 1.77f);

    REQUIRE(glm_vec.x == custom_vec.x);
    REQUIRE(glm_vec.y == custom_vec.y);
  }
}

TEST_CASE("Vec2 copy and move constructors") {
  {
    Vec2 dst_vec(1.1f, 3.14f);
    Vec2 src_vec(dst_vec);

    REQUIRE(src_vec.x == dst_vec.x);
    REQUIRE(src_vec.y == dst_vec.y);
  }

  {
    Vec2 dst_vec(0.01f);
    Vec2 src_vec(dst_vec);

    REQUIRE(src_vec.x == dst_vec.x);
    REQUIRE(src_vec.y == dst_vec.y);
  }

  {
    Vec2 vec(std::move(Vec2(1.14f, 3.28f)));

    REQUIRE(floatCmp(vec.x, 1.14f));
    REQUIRE(floatCmp(vec.y, 3.28f));
  }
}

TEST_CASE("Vec2 comparison") {
  {
    Vec2 vec_0(1.14f, 3.14f);
    Vec2 vec_1(1.14f, 3.14f);

    REQUIRE(vec_0 == vec_1);
  }

  {
    REQUIRE(Vec2(1.1f) == Vec2(1.1f));
    REQUIRE(Vec2() == Vec2());
    REQUIRE(Vec2(0.0f) == Vec2(0.0f));
    REQUIRE(Vec2(1.21f, 14.4f) == Vec2(1.21f, 14.4f));
  }

  {
    Vec2 vec_0(1.14f, 3.14f);
    Vec2 vec_1(1.14f, 3.13f);

    REQUIRE(vec_0 != vec_1);
  }

  {
    REQUIRE(Vec2(33333.3f) != Vec2(1.1f));
    REQUIRE(Vec2() != Vec2(1.1f));
    REQUIRE(Vec2(11.21f, 14.4f) != Vec2(33.1f, 50.2f));
  }
}