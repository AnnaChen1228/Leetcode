#
# @lc app=leetcode id=2559 lang=python
#
# [2559] Count Vowel Strings in Ranges
#

# @lc code=start
class Solution(object):
    def vowelStrings(self, words, queries):
        vowels = ('a','e','i','o','u')
        answer = []
        temp_words = [0]
        for i in range(len(words)):
            if words[i][0] in vowels and words[i][-1] in vowels:
                temp_words.append(1+temp_words[i])
            else:
                temp_words.append(temp_words[i])
        for test in queries:
            temp = temp_words[test[-1]+1]-temp_words[test[0]]
            answer.append(temp)
        return answer
        
# @lc code=end
test = Solution()
words= ["aba","bcb","ece","aa","e"]

queries = [[0,2],[1,4],[1,1]]
print(test.vowelStrings(words, queries))