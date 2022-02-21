#include <vector>

void merge(vector<int>& nums, int l, int mid, int r) {
	vector<int> helper(r - l + 1);
	int i = 0;
	int p1 = l;
	int p2 = mid + 1;
	while (p1 <= mid && p2 <= r) {
		helper[i++] = nums[p1] <= nums[p2] ? nums[p1++] : nums[p2++];
	}
	while (p1 <= mid) {
		helper[i++] = nums[p1++];
	}
	while (p2 <= r) {
		helper[i++] = nums[p2++];
	}
	for (int i = 0; i < helper.size(); i++) {
		nums[l + i] = helper[i];
	}
}


void process(vector<int>& nums, int l, int r) {
	if (l == r) return;

	int mid = l + ((r - l) >> 1);
	process(nums, l, mid);
	process(nums, mid + 1, r);
	merge(nums, l, mid, r);
}

void mergeSort(vector<int>& nums) {
	if (nums.empty() || nums.size() < 2) {
		return;
	}

	process(nums, 0, nums.size() - 1);
}


