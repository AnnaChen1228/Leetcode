/*
 * @lc app=leetcode id=2381 lang=cpp
 *
 * [2381] Shifting Letters II
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        string ans ="";
        vector<int> shift(s.length()+1,0);
        for(auto it = shifts.begin(); it!= shifts.end();++it){
            if((*it)[2]==1){
                shift[(*it)[0]]+=1;
                shift[(*it)[1]+1]-=1;
            }
            else if((*it)[2]==0){
                shift[(*it)[0]]-=1;
                shift[(*it)[1]+1]+=1;
            }
        }
        int buf = 0;
        int new_word = 0;
        int num = 0;
        for(auto it= shift.begin();it!=shift.end();++it){
            buf += *it;
            buf %= 26;
            new_word = s[num]+buf;
            if(new_word<97){
                new_word = 122-(96-new_word);
            }
            else if(new_word>122){
                new_word = new_word-123+97;
            }
            ans += char(new_word);
            num += 1;
        }
        return ans.erase(ans.size()-1);
    }
};
// @lc code=end

