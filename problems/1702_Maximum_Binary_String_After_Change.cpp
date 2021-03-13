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

// https://leetcode.com/problems/maximum-binary-string-after-change/
class Solution {
public:
    string maximumBinaryString(string binary)
    {
        // For the bits after the first zero, we can always move all 
        // the zeros together
        // e.g. 111101101001 -> 111100001111
        // and then convert the consecutive zeros "0000" to "1110"
        // so the final answer is 1111 1110 1111
        
        int n = binary.size();
        string ans = string(n, '1');
        int num_zeros = count(binary.begin(), binary.end(), '0');

        if (num_zeros == 0) return ans;

        int first_zero = binary.find('0');
        ans[first_zero + num_zeros - 1] = '0';
        return ans;
    }
};

int main()
{
    Solution sol;

    // string binary = "000110";
    string binary = "111101101001";
    cout << sol.maximumBinaryString(binary) << endl;
}
