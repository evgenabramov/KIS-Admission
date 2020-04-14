#pragma once

#include "gtest/gtest.h"
#include "MyClass.h"

TEST(test, test1) {
  MyClass my_class;
  EXPECT_EQ(my_class.GetSize(), 0);
  my_class.SetSize(5);
  EXPECT_EQ(my_class.GetSize(), 5);
  EXPECT_NE(my_class.GetSize(), 0);
}