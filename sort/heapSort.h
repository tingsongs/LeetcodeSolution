#include <iostream>
#include <vector>

using namespace std;

void adjust(vector<int>& heap, int len, int index)
{
    int left = 2*index+1, right = 2*index+2;

    int maxId = index;

    if(left < len && heap[len] > heap[maxId])
        maxId = left;
    if(right < len && heap[right] > heap[maxId])
        maxId = right;
    
    if(maxId != index)
    {
        swap(heap[maxId], heap[index]);
        adjust(heap, len, maxId);
    }
}

void HeapSort(vector<int>& nums)
{
    int len = nums.size();
    for(int n = len/2-1; n>=0; n--)
    {
        adjust(nums, len, n);
    }

    while(len >= 2)
    {
        swap(nums[0], nums[len-1]);
        adjust(nums, --len, 0);
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