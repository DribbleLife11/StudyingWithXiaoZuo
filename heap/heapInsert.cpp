#include <vector>
void heapInsert(vector<int>& nums, int index) {
    while (nums[index] > nums[(index - 1) / 2]) {
        swap(nums[index], nums[(index - 1) /2]);
        index = (index - 1) / 2;
} 
