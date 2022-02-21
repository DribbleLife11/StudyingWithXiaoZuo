#include "heapCtl.hpp"
#include <vector>

void heapSort(vector<int>& nums) {
    int numSize(nums.size());
    if (nums.empty() || numSize < 2) return;
    
    for (int i = 0; i < numSize; i++) {
        heapInsert(nums, i);
    }
    int heapSize(nums.size());
    swap(nums[0], nums[--heapSize]);
    while (heapSize > 0) {
        heapify(0, heapSize);
        swap(nums[0], nums[--heapSize]);
    }
}
  
