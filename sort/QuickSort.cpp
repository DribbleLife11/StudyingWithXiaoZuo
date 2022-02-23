/**
    荷兰国旗问题：
        给一个数组arr，和一个数num，将数组中小于num的数全部放在左边，把数组中等于num的数放在中间，把数组中大于num的数放在右边。
    分三个区域：
    
        ++++++++++++++++++++++++++++++++++++++++++++++
        +   <区  |    =区   |   ···待定··· |    >区   +
        ++++++++++++++++++++++++++++++++++++++++++++++
         ^
         |
         |
         i
         
         
        1.小于区域：[i] < num, [i]和<区下一个交换，<区右扩，i++
        2.等于区域：[i] == num, i++
        3.大于区域：[i] > num, [i]和>区前一个交换，>区左扩，i不变
    停止条件是当下标i进入大于区域时循环停止。
    
/
#include <vector>
vector<int> partition(vector<int>& nums, int l, int r) {
	int less = l - 1;	//<区域边界
	int more = r;		//>区域边界
	while (l < more) {
		if (nums[l] < nums[r]) {
			swap(nums[++less], nums[l++]);
		}
		else if (nums[l] > nums[r]) {
			swap(nums[--more], nums[l]);
		}
		else {
			l++;
		}
	}
	swap(nums[more], nums[r]);
	return { less + 1, more };
}

void quickSort(vector<int> nums, int l, int r) {
	if (l < r) {
		swap(nums[l + rand() % (r - l + 1)], nums[r]);
		vector<int> p = partition(nums, l, r);
		quickSort(nums, l, p[0] - 1);
		quickSort(nums, p[1] + 1, r);
	}
}

void quickSort(vector<int> nums) {
	if (nums.empty() || (int)nums.size() < 2) {
		return;
	}
	quickSort(nums, 0, (int)nums.size() - 1);
}
