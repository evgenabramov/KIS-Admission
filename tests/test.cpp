#pragma once

#include "gtest/gtest.h"
#include "Picture.h"

TEST(AccurateLocation, test1) {
  Picture picture1(3, 3, {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}});
  Picture picture2(2,2, {{0, 1}, {3, 4}});

  std::optional<Position> location = picture1.FindAccurateLocationOf(picture2);
  ASSERT_NE(location, std::nullopt);
  ASSERT_EQ(*location, Position(0, 0));
}

TEST(AccurateLocation, test2) {
  Picture picture1(3, 3, {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}});
  Picture picture2(2,2, {{4, 5}, {7, 8}});

  std::optional<Position> location = picture1.FindAccurateLocationOf(picture2);
  ASSERT_NE(location, std::nullopt);
  ASSERT_EQ(*location, Position(1, 1));
}

TEST(AccurateLocation, TestNotFound) {
  Picture picture1(3, 3, {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}});
  Picture picture2(2,2, {{0, 2}, {3, 4}});

  std::optional<Position> location = picture1.FindAccurateLocationOf(picture2);
  ASSERT_EQ(location, std::nullopt);
}

TEST(Direction, test1) {
  Picture picture1(3, 3, {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}});
  Picture picture2(2,2, {{4, 5}, {7, 8}});

  std::optional<Direction> direction = picture1.FindDirectionOf(picture2);
  ASSERT_NE(direction, std::nullopt);
  ASSERT_EQ(*direction, Direction::Southeast);
}

TEST(Direction, test2) {
  Picture picture1(4, 3, {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11}});
  Picture picture2(2,2, {{3, 4}, {6, 7}});

  std::optional<Direction> direction = picture1.FindDirectionOf(picture2);
  ASSERT_NE(direction, std::nullopt);
  ASSERT_EQ(*direction, Direction::West);
}

TEST(Direction, TestNotFound) {
  Picture picture1(4, 3, {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11}});
  Picture picture2(2,2, {{3, 4}, {5, 7}});

  std::optional<Direction> direction = picture1.FindDirectionOf(picture2);
  ASSERT_EQ(direction, std::nullopt);
}
