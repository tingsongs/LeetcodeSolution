#include <iostream>
#include <vector>

using namespace std;

void SubMergeSort(vector<int>& nums, int left, int right)
{
    if(left >= right-1)
        return;

    int mid = (left + right) / 2;
    SubMergeSort(nums, left, mid);
    SubMergeSort(nums, mid, right);

    vector<int> tmp(right-left, 0);
    int i = left, j = mid, k=0;
    while(i < mid && j < right)
        tmp[k++] = (nums[i] < nums[j]) ? nums[i++] : nums[j++];

    while(i < mid && j >= right)
        tmp[k++] = nums[i++];

    while(i >= mid && j < right)
        tmp[k++] = nums[j++];

    for(i=0; i<tmp.size(); i++)
        nums[left+i] = tmp[i];

}

void MergeSort(vector<int>& nums)
{
    if(nums.size()<2)
        return;
    SubMergeSort(nums, 0, nums.size());
}

void TestMergeSort()
{
    vector<int> nums = {3,5,2,6,8,7};
    MergeSort(nums);
    for(auto x : nums)
        cout << x << " ";
    cout << endl;

}