#include <vector>
int maxbits(vector<int>& nums) {
    int max = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if (max < nums[i])
            max = nums[i];
    }
    int res = 0;
    while (max != 0) {
        res++;
        max /= 10;
    }
    return res;
}

int getDigit(int x, int d) {
    return (int)((x / (Math.pow(10, d-1) % 10)));
}

/*
    nums：原数组
    start、end：数组内排序下标范围
    digit : 数组中最大的数的十进制位数。 （maxbits函数的返回值）
*/
void radixSort(vector<int>& nums, int start, int end, int digit) {
    const int radix = 10;
    int i = 0, j = 0;
    vector<int> bucket(end - start + 1);
    for (int m = 0; m <= digit; m++) {          //进出桶的次数
        vecotr<int> count(radix);
        for (i = start; i <= end; i++) {
            j = getDigit(nums[i], m);
            count[j]++;
        }
        for (i = 1; i < radix; i++) {
            count[i] = count[i] + count[i-1];
        }
        for (i = end; i >= start, i--) {
            j = getDigit(nums[i], m);
            bucket[count[j] - 1] = nums[i];
            count[j]--;
        }
        for (i = start; j = 0; i <= end; i++, j++) {
            nums[i] = bucket[j];
        }
    }     
}
