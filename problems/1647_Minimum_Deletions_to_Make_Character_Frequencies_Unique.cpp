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
    int minDeletions(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
        {
            freq[c]++;
        }
        unordered_set<int> unique_freq;
        int ans = 0;
        for (auto f : freq)
        {
            int count = f.second;
            while (count > 0 && unique_freq.find(count) != unique_freq.end())
            {
                count--;
                ans++;
            }

            if (count > 0)
            {
                unique_freq.insert(count);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "aab";
    // string s = "aaabbbcc";
    // string s = "ceabaacb";
    // string s = "accdcdadddbaadbc";

    cout << sol.minDeletions(s) << endl;
}
