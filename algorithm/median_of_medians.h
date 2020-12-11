#pragma once

#include <vector>
#include <cstdlib>
#include <assert.h>

namespace potatso {
namespace algorithm {

unsigned int RandomPivot(const std::vector<int> &arr, unsigned int left, 
    unsigned int right) {
  assert(left < right);
  if (right - left == 1) return left;

  return std::rand() % (right - left) + left;
}

unsigned int Partition(std::vector<int> &arr, unsigned int left, 
    unsigned int right, unsigned int pivot_index) {
  assert(left < right);
  assert(pivot_index >= left && pivot_index < right);

  int pivot_value = arr[pivot_index];
  std::swap(arr[pivot_index], arr[right - 1]);
  unsigned int cur_index = left;
  for (unsigned int i = left; i < right - 1; i++) {
    if (arr[i] < pivot_value) {
      std::swap(arr[i], arr[cur_index]);
      cur_index++;
    }
  }

  std::swap(arr[right-1], arr[cur_index]);
  
  return cur_index;
}  

unsigned int Select(std::vector<int> &arr, unsigned int left, 
    unsigned int right, unsigned int k) {
  assert(left < right);
  assert(k > left && k <= right);

  while(left < right) {
    unsigned int pivot_index = RandomPivot(arr, left, right);
    unsigned int median_index = Partition(arr, left, right, pivot_index);
    if (median_index == k - 1) {
      return median_index;
    } else if (median_index < k - 1) {
      // Select(arr, median_index + 1, right, k - median_index - 1);
      left = median_index + 1;
      // todo(zero): how to deal with absolute length
    //   k = k - median_index - 1;
    } else {
      // Select(arr, left, median_index, k)
      right = median_index;
    }
  }
  
  return 0;
}

unsigned int MedianOfMedians(std::vector<int> &arr, unsigned int k) {
  assert(k <= arr.size());
  return Select(arr, 0, arr.size(), k);
}


}  // namespace algorithm
}  // namespace potatso