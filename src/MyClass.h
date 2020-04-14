#include <cstdlib>

class MyClass {
 public:
  size_t GetSize() const {
    return size_;
  }

  void SetSize(size_t size) {
    size_ = size;
  }

 private:
  size_t size_ = 0;
};