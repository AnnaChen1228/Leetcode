/*
 * @lc app=leetcode id=1930 lang=cpp
 *
 * [1930] Unique Length-3 Palindromic Subsequences
 */

// @lc code=start
#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        int next_site =0;
        string test = "";
        set<string> temp;
        set<char> start;
        for(int i = 0 ;i < s.length() ; i++){
            if(start.find(s[i])==start.end()){
                next_site = s.rfind(s[i],s.length());
                if (next_site!=string::npos && next_site-i>=2){
                    set<char> buf(s.begin()+i+1, s.begin()+next_site);
                    for(auto it = buf.begin(); it!=buf.end(); ++it){
                        test = s[i]+string(1,*it)+s[next_site];
                        if(temp.find(test)==temp.end()){
                            temp.insert(test);
                            ans += 1;
                        }
                    }
                } 
                start.insert(s[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution solution;
    
    // 測試案例 1
    string s1 = "aabca";
    cout << "Test case 1: " << s1 << endl;
    cout << "Result 1: " << solution.countPalindromicSubsequence(s1) << endl;
    // 預期輸出: 3 (回文子序列: "aba", "aaa", "aca")
    
    // 測試案例 2
    string s2 = "adc";
    cout << "\nTest case 2: " << s2 << endl;
    cout << "Result 2: " << solution.countPalindromicSubsequence(s2) << endl;
    // 預期輸出: 0 (沒有長度為3的回文子序列)
    
    // 測試案例 3
    string s3 = "bbcbaba";
    cout << "\nTest case 3: " << s3 << endl;
    cout << "Result 3: " << solution.countPalindromicSubsequence(s3) << endl;
    // 預期輸出: 4
    
    // 可以添加更多測試案例
    
    return 0;
}