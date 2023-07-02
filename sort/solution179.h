#include "..\tool.h"

using namespace std;

class Solution {
public:
    static bool isBigger(int x, int y)
    {
        string s1 = to_string(x) + to_string(y);
        string s2 = to_string(y) + to_string(x);
        return s1 > s2;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), isBigger);
        if(nums[0] == 0)
            return "0";
        string res;
        for(auto& x: nums)
            res += to_string(x);

        return res;

    }

    void test()
    {
        vector<int> nums = {1,2,3};
        cout << largestNumber(nums) << endl;
    }
};