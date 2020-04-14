#include <iostream>

#include "Picture.h"

int main() {
  size_t num_rows = 0;
  size_t num_columns = 0;

  std::cout << "Input first picture (format: [NUM_ROWS] [NUM_COLUMNS] [VALUES]): " << std::endl;
  std::cin >> num_rows >> num_columns;

  Picture first_picture(num_rows, num_columns);
  std::cin >> first_picture;

  std::cout << "Input second picture (format: [NUM_ROWS] [NUM_COLUMNS] [VALUES]): " << std::endl;
  std::cin >> num_rows >> num_columns;

  Picture second_picture(num_rows, num_columns);
  std::cin >> second_picture;

  while (true) {

    std::cout << "Do you want the accurate location? [Y/n]" << std::endl;
    char answer;
    std::cin >> answer;

    if (answer == 'Y' || answer == 'y') {
      std::optional<Position> location = first_picture.FindAccurateLocationOf(second_picture);
      if (location) {
        std::cout << *location << std::endl;
      } else {
        std::cout << "Not found" << std::endl;
      }
      break;
    } else if (answer == 'N' || answer == 'n') {
      std::optional<Direction> direction = first_picture.FindDirectionOf(second_picture);
      if (direction) {
        std::cout << *direction << std::endl;
      } else {
        std::cout << "Not found" << std::endl;
      }
      break;
    } else {
      std::cout << "Undefined letter" << std::endl;
    }
  }

  return 0;
}
