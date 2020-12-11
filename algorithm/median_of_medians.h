#pragma once

#include <vector>

namespace potatso {
namespace algorithm {

unsigned int MedianOfMedians(const std::vector<int> &arr, unsigned int left, 
    unsigned int right, unsigned int k) {
  unsigned int pivot_index = RandomPivot(arr);
  unsigned int median_index = Partition(arr, left, right, pivot_index);
  if (median_index == k) 
    return median_index;
  else if (median_index < k)
    return MedianOfMedians(arr, median_index, right, k - median_index);
  else if (median_index > k)
    return MedianOfMedians(arr, left, median_index, k);
}

void Pivot(const std::vector<int> &arr, unsigned int k) {
  
}

unsigned int RandomPivot(const std::vector<int> &arr, unsigned int left, 
    unsigned int right) {
  return rand() % (right - left) + left;
}

unsigned int Partition(std::vector<int> &arr, unsigned int left, 
    unsigned int right, unsigned int pivot_index) {
  int pivot_value = arr[pivot_index];
  std::swap(arr[pivot_index], arr[right]);
  unsigned int cur_index = left;
  for (unsigned int i = left; i < right; i++) {
    if (arr[i] < pivot_value) {
      std::swap(arr[i], arr[cur_index]);
      cur_index++;
    }
  }

  std::swap(arr[right], arr[cur_index]);
  
  return cur_index;
}


}  // namespace algorithm
}  // namespace potatso