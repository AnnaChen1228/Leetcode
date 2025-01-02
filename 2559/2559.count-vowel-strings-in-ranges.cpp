/*
 * @lc app=leetcode id=2559 lang=cpp
 *
 * [2559] Count Vowel Strings in Ranges
 */

// @lc code=start

#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> answer;
        set<char> vowels{'a','e','i','o','u'};
        vector<int> buf;
        buf.push_back(0);
        for(auto temp : words){
            if(vowels.count(temp[0]) && vowels.count(temp.back())){ //set.count()用來計算元素出現次數我要計算他是否出現在頭尾 temp.back()=temp[-1]
                buf.push_back(buf.back() + 1);  
            }
            else{
                buf.push_back(buf.back());
            }
        }
        for(auto temp: queries){
            answer.push_back(buf[temp[1]+1]-buf[temp[0]]);
        }
        return answer;
    }
};
// @lc code=end

