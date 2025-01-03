#
# @lc app=leetcode id=2270 lang=python
#
# [2270] Number of Ways to Split Array
#

# @lc code=start
class Solution(object):
    def waysToSplitArray(self, nums):
        ans = 0 #記錄
        left = [nums[0]]
        right = nums [1:]
        left_sum = sum(left)
        right_sum = sum(right)
        for i in range(len(nums)-1):
            if left_sum >= right_sum:
                ans += 1
            left_sum += right[i]
            right_sum -= right[i]
        return ans
        """
        :type nums: List[int]
        :rtype: int
        """
        
# @lc code=end

test = Solution()
print(test.waysToSplitArray([2,3,1,0]))