#include <vector>

//O(logN)
void heapInsert(vector<int>& nums, int index) {
    while (nums[index] > nums[(index - 1) / 2]) {
        swap(nums[index], nums[(index - 1) /2]);
        index = (index - 1) / 2;
} 

//O(logN)
void heapify(vector<int>& nums, int index, int heapSize) {
    int left = index * 2 + 1;       //左孩子下标
    while (left < heapSize) {       //当有孩子时
        int largest = left + 1 < heapSize && nums[left] < nums[left + 1] ? left + 1 : left;     //两个孩子哪个值最大，就把谁的下标给largest
        
        largest = nums[largest] > nums[index] ? largest : index;        //父节点和最大的孩子进行值的比较，哪个大就把谁的下标给largest
        if (largest == index)   break;
        
        swap(nums[largest], nums[index]);
        index = largest;
        left = index * 2 + 1;
        
}
