#include "..\tool.h"

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())
            return 0;
        int L = 0;
        int R = nums.size()-1;
        while(L < R)
        {
            if(nums[L] == val)
                swap(nums[L], nums[R--]);
            else
                L++;
        }
        return nums[R]==val ? R : R+1;
    }

    void test()
    {

    }
};