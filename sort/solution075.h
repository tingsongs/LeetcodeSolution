#include "..\tool.h"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int cur = 0;
        while(cur <= right)
        {
            if(nums[cur] == 0)
                swap(nums[cur], nums[left++]);
            else if(nums[cur] == 2)
                swap(nums[cur], nums[right--]);
            else
                cur++;
            if(cur < left)
                cur = left;
        }
    }

    void test()
    {
        vector<int> nums = {0};
        sortColors(nums);
        print_iv(nums);
    }
};