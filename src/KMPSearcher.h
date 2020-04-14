#include <iostream>
#include <string>
#include <vector>

// Example: searcher.Search(haystack, std::back_inserter(matches));

class KMPSearcher {
 public:
  explicit KMPSearcher(const std::vector<size_t>& needle)
      : needle_(needle), prefix_function_(0) {
    needle_prefix_function_.push_back(0);
    for (size_t index = 1; index < needle.size(); ++index) {
      FindPrefixFunction(needle[index]);
      needle_prefix_function_.push_back(prefix_function_);
    }
    prefix_function_ = 0;
  }

  template <typename OutputIterator>
  void Search(const std::vector<size_t>& haystack, OutputIterator out) {
    for (size_t index = 0; index < haystack.size(); ++index) {
      FindPrefixFunction(haystack[index]);
      if (prefix_function_ == needle_.size()) {
        *out = index - prefix_function_ + 1;
        out++;
      }
    }
  }

 private:
  void FindPrefixFunction(const size_t& symbol) {
    while (prefix_function_ > 0 && needle_[prefix_function_] != symbol) {
      prefix_function_ = needle_prefix_function_[prefix_function_ - 1];
    }
    if (needle_[prefix_function_] == symbol) {
      prefix_function_++;
    }
  }

  std::vector<size_t> needle_;
  size_t prefix_function_;
  std::vector<size_t> needle_prefix_function_;
};