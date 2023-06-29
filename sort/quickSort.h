#include <iostream>
#include <vector>

using namespace std;

void SubQuickSort(vector<int>&nums, int left, int right);

void QuickSort(vector<int>& nums)
{
    int len = nums.size();
    SubQuickSort(nums, 0, len-1);
    
}

void SubQuickSort(vector<int>&nums, int left, int right)
{
    if(left >= right)
        return;
    int i = left, j = right-1;
    while(true)
    {
        while(nums[i] < nums[right])
            i++;
        while(nums[j] > nums[right])
            j--;
        if(i > j)
            break;
        else
            swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[right]);
    SubQuickSort(nums, left, i-1);
    SubQuickSort(nums, i+1, right);
}

void TestQuickSort()
{
    vector<int> nums = {9,8,7,6,5,4,3,2,1};
    QuickSort(nums);
    for(auto x : nums)
        cout << x << " ";
    cout << endl;

}