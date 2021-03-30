#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        int sLen = s.size(), pLen = p.size();
        vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));
        // dp[i][j] = true if first i characters of s and first j characters of p match
        dp[0][0] = true;
        
        
        for (int i = 0; i <= sLen; ++i)
        {
            for (int j = 1; j <= pLen; ++j)
            {
                bool match = i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                
                
                if (j + 1 <= pLen && p[j] == '*')
                {
                    bool case1 = dp[i][j - 1];                  // X* -> zero element
                    bool case2 = i > 0 && match && dp[i - 1][j + 1];     // X* -> multiple elements
                    dp[i][j + 1] = case1 || case2;
                    j++;
                }
                else
                {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && match;
                }
            }
        }
        return dp[sLen][pLen];
    }
};

// class Solution {
// public:
// bool isMatch(string s, string p) {
//     return dfs(s, p);
// }
// private:
//     bool dfs(string s, string p) {
//          if (p.length() == 0) {
//          if (s.length() == 0) return true;
//          else return false;
//     }

//     if (p.length() > 1 && p[1] == '*') {
//          if (p[0] == '.') {	// '.*'
//              for (int i = 0; i <= s.length(); ++i) {
//                  if (dfs(s.substr(i), p.substr(2))) return true;
//              }
//              return false;
//          } else {			// '{c}*'
//              char c = p[0];
//              if (dfs(s.substr(0), p.substr(2))) return true;
//              for (int i = 0; s[i] == c; ++i) {
//                 if (dfs(s.substr(i + 1), p.substr(2))) return true;
//              }
//              return false;
//          }
//      }
//          if (s.length() < 1) return false;
//          if (p[0] == '.') {
//              return dfs(s.substr(1), p.substr(1));
//          } 
//          // p[0] == 'a' to 'z'
//          return p[0] == s[0] && dfs(s.substr(1), p.substr(1));
//      }
// };

int main() {
	string s = "mississippi";
	string p = "mis*is*p*";
	Solution sol;
	cout << sol.isMatch(s, p) << endl;
}