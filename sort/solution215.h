#include "..\tool.h"

using namespace std;

// 基于堆排序
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();

        for(int i = len/2-1; i >= 0; i--)
        {
            adjust(nums, len, i);
        }

        for(int j = 1; j<k; j++)
        {
            swap(nums[0], nums[--len]);
            adjust(nums, len, 0);
        }

        return nums[0];
    }

    void adjust(vector<int>& heap, int len, int index)
    {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int maxInd = index;

        if(left < len && heap[left] > heap[maxInd])
            maxInd = left;
        if(right < len && heap[right] > heap[maxInd])
            maxInd = right;

        if(maxInd != index)
        {
            swap(heap[index], heap[maxInd]);
            adjust(heap, len, maxInd);
        }
    }

    void test()
    {
        vector<int> nums = {3,2,3,1,2,4,5,5,6};
        int k = 4;
        cout << findKthLargest(nums, k) << endl;
    }

};

// 基于选择排序 超时！！
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int maxInd;
        for(int i=0; i<k; i++)
        {
            maxInd = i;
            for(int j=i; j<nums.size(); j++)
            {
                if(nums[j] > nums[maxInd])
                    maxInd = j;
            }
            swap(nums[i], nums[maxInd]);
        }
        return nums[k-1];
    }

    void test()
    {

    }
};