#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize)
    {
        if (s.size() < minSize) return 0;
        
        unordered_map<char, int> letterCount;
        unordered_map<string, int> occurence;

        int ans = 0;
        for (int i = 0; i < minSize; ++i)
        {
            letterCount[s[i]]++;
        }
        if (letterCount.size() <= maxLetters)
        {
            occurence[s.substr(0, minSize)]++;
            ans = 1;
        }

        for (int i = minSize; i < s.size(); ++i)
        {
            letterCount[s[i]]++;
            letterCount[s[i - minSize]]--;
            if (letterCount[s[i - minSize]] == 0) letterCount.erase(s[i - minSize]);
            if (letterCount.size() <= maxLetters)
            {
                occurence[s.substr(i - minSize + 1, minSize)]++;
                ans = max(ans, occurence[s.substr(i - minSize + 1, minSize)]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // string s = "aababcaab";
    // int maxLetters = 2;
    // int minSize = 3;
    // int maxSize = 4;

    // string s = "aaaa";
    // int maxLetters = 1;
    // int minSize = 3;
    // int maxSize = 3;

    // string s = "aabcabcab";
    // int maxLetters = 2;
    // int minSize = 2;
    // int maxSize = 3;

    string s = "abcde";
    int maxLetters = 2;
    int minSize = 3;
    int maxSize = 3;

    cout << sol.maxFreq(s, maxLetters, minSize, maxSize) << endl;
}
