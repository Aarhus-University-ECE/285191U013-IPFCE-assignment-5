#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

extern "C" {
#include "circle.h"
#include "jolly_jumper.h"
}

TEST_CASE("five_circles", "[circle]") {
  circle circles[5];
  five_circles(circles);
  for (int i = 0; i < 5; ++i) {
    REQUIRE(circles[i].p.x == i);
    REQUIRE(circles[i].p.y == i);
    REQUIRE(circles[i].r == i);
    // REQUIRE(circles[i].p.x == i && circles[i].p.y == i && circles[i].r == i);
  }
  REQUIRE(true);
}

TEST_CASE("circle_is_valid", "[circle]") {

  circle c1;
  c1.r = 1;
  c1.p = (point) {0, 0};

  REQUIRE(circle_is_valid(&c1));

  circle c2;
  c2.r = 0;
  c2.p = (point) {0, 0};

  REQUIRE(!circle_is_valid(&c2));

  circle c3;
  c3.r = -2;
  c3.p = (point) {1, -3};

  REQUIRE(!circle_is_valid(&c3));
}


TEST_CASE("translate", "[circle]") {

  circle c1;
  c1.r = 1;
  c1.p = (point) {0, 0};

  const point p1 = {.x = 1, .y = 1};

  translate(&c1, &p1);

  // REQUIRE(c1.p.x == 1 && c1.p.y == 1 && c1.r == 1);
  REQUIRE(c1.p.x == 1);
  REQUIRE(c1.p.y == 1);
  REQUIRE(c1.r == 1);


  circle c2;
  c2.r = 7;
  c2.p = (point) {-1,3};

  const point p2 = {.x = -1, .y = -5};

  translate(&c2, &p2);

  // REQUIRE(c2.p.x == -2 && c2.p.y == -2 && c2.r == 7);
  REQUIRE(c2.p.x == -2);
  REQUIRE(c2.p.y == -2);
  REQUIRE(c2.r == 7);
}



TEST_CASE("is_jolly_jumper", "[jolly_jumper]") {

  {
    int seq[] = {1, 4, 2, 3};
    int n = sizeof(seq) / sizeof(seq[0]);
    REQUIRE(is_jolly_jumper(seq, n));
  }

  {
    int seq[] = {11, 7, 4, 2, 1, 6};
    int n = sizeof(seq) / sizeof(seq[0]);
    REQUIRE(is_jolly_jumper(seq, n));
  }

  {
    int seq[] = {1, 4, 2, -1, 6};
    int n = sizeof(seq) / sizeof(seq[0]);
    REQUIRE(!is_jolly_jumper(seq, n));
  }
}
