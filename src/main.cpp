#include <iostream>

#include "MyClass.h"

int main() {
  std::cout << "Hello, World!" << std::endl;
  MyClass my_class;
  std::cout << "Current size: " << my_class.GetSize() << std::endl;
  return 0;
}
