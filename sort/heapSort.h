#include <iostream>
#include <vector>

using namespace std;

void HeapSort(vector<int>& nums)
{
    for(int len = nums.size(); len > 1; len--)
    {
        for(int n = len/2-1; n >= 0; n--)
        {
            if(nums[n] < nums[2*n+1])
                swap(nums[n], nums[2*n+1]);
            if(2*n+2 < len && nums[n] < nums[2*n+2])
                swap(nums[n], nums[2*n+2]);
        }
        swap(nums[0], nums[len-1]);
    }
}

void TestHeapSort()
{
    vector<int> nums = {3,5,2,6,8,7};
    HeapSort(nums);
    for(auto x : nums)
        cout << x << " ";
    cout << endl;

}