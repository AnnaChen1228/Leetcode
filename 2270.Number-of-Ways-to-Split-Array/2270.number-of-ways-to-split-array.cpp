/*
 * @lc app=leetcode id=2270 lang=cpp
 *
 * [2270] Number of Ways to Split Array
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        long long int left_sum = nums[0];
        long long int right_sum = 0;
        for (int i = 1 ; i<nums.size() ; i++){
            right_sum += nums[i];
        }
        for (int i=1; i<nums.size() ;i++){
            if (left_sum >= right_sum){
                ans += 1;
            }
            left_sum += nums[i];
            right_sum -= nums[i];
        }
        return ans;
    }
};
// @lc code=end

