#
# @lc app=leetcode id=1930 lang=python
#
# [1930] Unique Length-3 Palindromic Subsequences
#

# @lc code=start
class Solution(object):
    def countPalindromicSubsequence(self, s):
        ans = 0
        temp = []
        end = len(s)
        start = []
        for i in range(len(s)):
            if s[i] not in start:
                next_i = s.rfind(s[i],i,end)
                if next_i != -1 and next_i-i>=2:
                    mid = set(list(s[i+1:next_i]))
                    for j in mid:
                        buf = s[i]+j+s[next_i]
                        if buf not in temp:
                            temp.append(buf)
                            ans+=1
                start.append(s[i])
        return ans
        """
        :type s: str
        :rtype: int
        """
        
# @lc code=end
test = Solution()
print(test.countPalindromicSubsequence("bbcbaba"))
