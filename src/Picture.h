#include <vector>
#include <optional>
#include <string>

#include "KMPSearcher.h"

enum class Direction {
  North, South, East, West, Northeast, Southeast, Southwest, Northwest
};

std::ostream& operator<<(std::ostream& out, const Direction& direction) {
  switch (direction) {
    case Direction::North:out << "North";
      break;
    case Direction::South:out << "South";
      break;
    case Direction::West:out << "West";
      break;
    case Direction::East:out << "East";
      break;
    case Direction::Northwest:out << "Northwest";
      break;
    case Direction::Northeast:out << "Northeast";
      break;
    case Direction::Southwest:out << "Southwest";
      break;
    case Direction::Southeast:out << "Southeast";
      break;
  }
  return out;
}

struct Position {
  Position(size_t row, size_t column) : row_(row), column_(column) {}

  bool operator==(const Position& other) const {
    return (row_ == other.row_ && column_ == other.column_);
  }

  friend std::ostream& operator<<(std::ostream& out, const Position& position);

  size_t row_;
  size_t column_;
};

std::ostream& operator<<(std::ostream& out, const Position& position) {
  out << position.row_ << " " << position.column_;
  return out;
}

class Picture {
 public:
  Picture(size_t num_rows, size_t num_columns) : num_rows_(num_rows), num_columns_(num_columns) {
    values_.assign(num_rows_, std::vector<size_t>(num_columns_));
  }

  Picture(size_t num_rows, size_t num_columns, const std::vector<std::vector<size_t>>& values) : Picture(num_rows, num_columns) {
    for (size_t row = 0; row < num_rows; ++row) {
      values_[row] = values[row];
    }
  }

  std::optional<Position> FindAccurateLocationOf(const Picture& other) const {
    for (size_t row = 0; row < num_rows_; ++row) {
      for (size_t column = 0; column < num_columns_; ++column) {
        if (CheckLocation(row, column, other)) {
          return Position(row, column);
        }
      }
    }
    return std::nullopt;
  }

  std::optional<Direction> FindDirectionOf(const Picture& other) const {
    if (num_rows_ < other.num_rows_ || num_columns_ < other.num_columns_) {
      return std::nullopt;
    }

    if (CheckLocation(0, 0, other)) {
      return Direction::Northwest;
    } else if (CheckLocation(0, num_columns_ - other.num_columns_, other)) {
      return Direction::Northeast;
    } else if (CheckLocation(num_rows_ - other.num_rows_, 0, other)) {
      return Direction::Southwest;
    } else if (CheckLocation(num_rows_ - other.num_rows_, num_columns_ - other.num_columns_, other)) {
      return Direction::Southeast;
    }

    for (size_t column = 1; column < num_columns_ - other.num_columns_; ++column) {
      if (CheckLocation(0, column, other)) {
        return Direction::North;
      } else if (CheckLocation(num_rows_ - other.num_rows_, column, other)) {
        return Direction::South;
      }
    }

    for (size_t row = 1; row < num_rows_ - other.num_rows_; ++row) {
      if (CheckLocation(row, 0, other)) {
        return Direction::West;
      } else if (CheckLocation(row, num_columns_ - other.num_columns_, other)) {
        return Direction::East;
      }
    }

    return std::nullopt;
  }

  friend std::istream& operator>>(std::istream& in, Picture& picture);

 private:
  static bool CheckLine(const std::vector<size_t>::const_iterator& first,
                        const std::vector<size_t>::const_iterator& second,
                        size_t size) {
    for (size_t index = 0; index < size; ++index) {
      if (*(first + index) != *(second + index)) {
        return false;
      }
    }
    return true;
  }

  bool CheckLocation(size_t row, size_t column, const Picture& other) const {
    for (size_t second_row = 0; second_row < other.num_rows_; ++second_row) {
      if (!CheckLine(values_[row + second_row].cbegin() + column,
                     other.values_[second_row].cbegin(), other.num_columns_)) {
        return false;
      }
    }
    return true;
  }

  size_t num_rows_;
  size_t num_columns_;
  std::vector<std::vector<size_t>> values_;
};

std::istream& operator>>(std::istream& in, Picture& picture) {
  for (auto& row : picture.values_) {
    for (auto& value : row) {
      in >> value;
    }
  }
  return in;
}
