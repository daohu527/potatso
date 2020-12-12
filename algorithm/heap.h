#pragma once

#include <vector>

namespace potatso {
namespace algorithm {

constexpr static auto kFixedArrayUseDefault = static_cast<size_t>(-1);

template<typename T， size_t N = kFixedArrayUseDefault>
class FixedHeap {
 public:
  template<typename T>
  FixedHeap() : capacity_(N), size_(0) {}

  void Push(T value);

  T Pop();

 private:
  void Heapify();

  std::vector<T> arr_;
  size_t size_;
  const size_t capacity_;
};

void FixedHeap<T, N>::Heapify() {
  // Todo(zero): need implement
}

void FixedHeap<T, N>::Push(T value) {
  if (size_ < capacity_) {
    arr_.emplace_back(value);
    size_++;
  } else if (size_ == capacity_) {
    Pop();
    arr_.push_back(value);
  }
  Heapify();
}

T FixedHeap<T, N>::Pop() {
  if (size_ == 0) return T{};

  T value = arr_[0];
  size_--;
  if (size_ > 1) {
    std::swap(arr_[0], arr_[size_ - 1]);
    // If needed delete arr_[size_ - 1]?
    // Todo(zero): heapify
    Heapify();
  }

  return value;
}


}
}