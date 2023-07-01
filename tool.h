#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

void print_iv(std::vector<int>& nums)
{
    for(auto x : nums)
        std::cout << x << " ";
    std::cout << std::endl;
}

void print_ivv(std::vector<std::vector<int>>& nums)
{
    for(auto x : nums)
        print_iv(x);
}