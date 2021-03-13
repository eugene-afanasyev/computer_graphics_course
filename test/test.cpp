#define CATCH_CONFIG_MAIN

#define EPSILON 1e-5

#include "catch.hpp"
#include "../src/math/vec2.h"

#include <cmath>
#include <glm/geometric.hpp>
#include <glm/ext.hpp>
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

TEST_CASE("Vec2 length method") {
  {
    Vec2 custom_vec(1.23f, 32.1f);
    REQUIRE(floatCmp(32.12355677f, custom_vec.length()));

    Vec2 custom_vec1(11.3f);
    REQUIRE(floatCmp(15.980613f, custom_vec1.length()));
  }
  {
    REQUIRE(Vec2(0.0f).length() == 0.0f);
    REQUIRE(floatCmp(Vec2(1.0f).length(), sqrtf(2.0f)));
    REQUIRE(floatCmp(Vec2(3.0f, 4.0f).length(), 5.0f));
    REQUIRE(floatCmp(Vec2(3.0f, 0.0f).length(), 3.0f));
  }
}

TEST_CASE("Vec2 addition and subtraction") {
  {
    glm::vec2 glm_vec1(1.3f, 17.4f);
    glm::vec2 glm_vec2(17.5f, 9.4f);

    Vec2 custom_vec1(1.3f, 17.4f);
    Vec2 custom_vec2(17.5f, 9.4f);

    glm::vec2 glm_result_vec = glm_vec1 + glm_vec2;
    Vec2 custom_result_vec = custom_vec1 + custom_vec2;

    REQUIRE(glm_result_vec.x == custom_result_vec.x);
    REQUIRE(glm_result_vec.y == custom_result_vec.y);
  }

  {
    glm::vec2 glm_vec1(31231.1f, 38129.2f);
    glm::vec2 glm_vec2(0.4320f, 50.2f);

    Vec2 custom_vec1(31231.1f, 38129.2f);
    Vec2 custom_vec2(0.4320f, 50.2f);

    glm::vec2 glm_result_vec = glm_vec1 - glm_vec2;
    Vec2 custom_result_vec = custom_vec1 - custom_vec2;

    REQUIRE(glm_result_vec.x == custom_result_vec.x);
    REQUIRE(glm_result_vec.y == custom_result_vec.y);
  }
}

TEST_CASE("Vec2 assignment addition and subtraction") {
  {
    glm::vec2 glm_vec(31231.1f, 38129.2f);
    Vec2 custom_vec(31231.1f, 38129.2f);

    glm_vec += glm::vec2(94.8f, 4891.3f);
    custom_vec += Vec2(94.8f, 4891.3f);

    REQUIRE(floatCmp(glm_vec.x, custom_vec.x));
    REQUIRE(floatCmp(glm_vec.y, custom_vec.y));
  }

  {
    glm::vec2 glm_vec(13.1f, 38.2f);
    Vec2 custom_vec(13.1f, 38.2f);

    glm_vec -= glm::vec2(2.8f, 48.3f);
    custom_vec -= Vec2(2.8f, 48.3f);

    REQUIRE(floatCmp(glm_vec.x, custom_vec.x));
    REQUIRE(floatCmp(glm_vec.y, custom_vec.y));
  }
}

TEST_CASE("Vec2 assignment multiplication and division") {
  {
    glm::vec2 glm_vec(31231.1f, 38129.2f);
    Vec2 custom_vec(31231.1f, 38129.2f);

    glm_vec *= 3.3f;
    custom_vec *= 3.3f;

    REQUIRE(floatCmp(glm_vec.x, custom_vec.x));
    REQUIRE(floatCmp(glm_vec.y, custom_vec.y));
  }

  {
    glm::vec2 glm_vec(9417.122f);
    Vec2 custom_vec(9417.122f);

    glm_vec /= 23.4f;
    custom_vec /= 23.4f;

    REQUIRE(floatCmp(glm_vec.x, custom_vec.x));
    REQUIRE(floatCmp(glm_vec.y, custom_vec.y));
  }
}

TEST_CASE("Vec2 scalar multiplication") {
  Vec2 custom_vec1(11.1f, 32.2f);
  Vec2 custom_vec2(9.20f, 510.2f);

  float custom_cross_result = custom_vec1 * custom_vec2;
  REQUIRE(floatCmp(custom_cross_result, 16530.56f));
}

TEST_CASE("Vec2 multiplication and div on number") {
  {
    glm::vec2 glm_vec(12.4f, 32.1f);
    Vec2 custom_vec(12.4f, 32.1f);

    glm_vec = glm::operator*(glm_vec, {3});
    custom_vec = custom_vec * 3;

    REQUIRE(floatCmp(glm_vec.x, custom_vec.x));
    REQUIRE(floatCmp(glm_vec.y, custom_vec.y));
  }

  {
    glm::vec2 glm_vec(12.4f, 32.1f);
    Vec2 custom_vec(12.4f, 32.1f);

    glm_vec = glm::operator/(glm_vec, {2});
    custom_vec = custom_vec / 2;

    REQUIRE(floatCmp(glm_vec.x, custom_vec.x));
    REQUIRE(floatCmp(glm_vec.y, custom_vec.y));
  }
}

TEST_CASE("Vec2 normalization") {
  {
    glm::vec2 glm_vec(12.4f, 32.1f);
    Vec2 custom_vec(12.4f, 32.1f);

    glm_vec = glm::normalize(glm_vec);

    REQUIRE(floatCmp(glm_vec.x, custom_vec.normalize().x));
    REQUIRE(floatCmp(glm_vec.y, custom_vec.normalize().y));
  }

  {
    glm::vec2 glm_vec(134.443f);
    Vec2 custom_vec(134.443f);

    glm_vec = glm::normalize(glm_vec);

    REQUIRE(floatCmp(glm_vec.x, custom_vec.normalize().x));
    REQUIRE(floatCmp(glm_vec.y, custom_vec.normalize().y));
  }

  {
    glm::vec2 glm_vec(0.0f, 0.01f);
    Vec2 custom_vec(0.0f, 0.01f);

    glm_vec = glm::normalize(glm_vec);

    REQUIRE(floatCmp(glm_vec.x, custom_vec.normalize().x));
    REQUIRE(floatCmp(glm_vec.y, custom_vec.normalize().y));
  }
}