#
# @lc app=leetcode id=2381 lang=python
#
# [2381] Shifting Letters II
#

# @lc code=start
class Solution(object):
    def shiftingLetters(self, s, shifts):
        temp_s = list(s)
        shift = [0]*(len(temp_s)+1)
        ans = ""
        for i in shifts:
            if i[2] == 1: # forward
                shift[i[0]] += 1
                shift[i[1]+1] -= 1
            elif i[2] == 0 : #backward
                shift[i[0]] -= 1
                shift[i[1]+1] += 1
        num = 0 
        buf = 0 
        for i in range(len(shift)-1):
            buf += shift[i]
            buf %= 26
            num = ord(temp_s[i])+buf
            if num<97:
                num = 122-(96-num)
            elif num>122:
                num = num-123+97
            ans += chr(num)
        if(len(ans)<len(s)):
            ans += s[3:]
        print(ans)
        return str(ans)
        """
        :type s: str
        :type shifts: List[List[int]]
        :rtype: str
        """
        
# @lc code=end

test = Solution()
s = "abc"
shifts =[[0,1,0],[1,2,1],[0,2,1]]
test.shiftingLetters(s,shifts)