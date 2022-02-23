#include <vector>
void insertionSort(vector<int>& nums) {

	for (int i = 1; i < nums.size(); i++) {
		for (int j = i - 1; j >= 0 && nums[j] > nums[j + 1]; j--) {
			swap(nums[j], nums[j + 1]);
		}
	}
}
