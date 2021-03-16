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
// https://leetcode.com/problems/numbers-with-repeated-digits/
const int MOD = 1000000007;
class Solution {
public:
    int numDupDigitsAtMostN(int N)
    {
        if (N <= 10) return 0;
        
        int numDigits = 0;
        for (int k = N; k > 0; k /= 10) numDigits++;

        vector<int> digit(numDigits);
        for (int i = 0, k = N; i < numDigits; ++i, k /= 10)
        {
            digit[numDigits - i - 1] = k % 10;
        }

        int sumNoRepeated = 0;
        vector<int> numNoRepeated(numDigits - 1);
        for (int i = 0; i < numDigits - 1; ++i)
        {
            numNoRepeated[i] = i == 0 ? 9 : numNoRepeated[i - 1] * (10 - i);
            sumNoRepeated += numNoRepeated[i];
        }

        vector<int> numNoRepeatedLastDigit(numDigits, 0);
        int digitCount[10] = {0};
        bool repeated = false;
        for (int i = 0; i < numDigits; ++i)
        {
            numNoRepeatedLastDigit[i] = i == 0 ? 9 : numNoRepeatedLastDigit[i - 1] * (10 - i);
            if (!repeated)
            {
                int diff = 0;
                for (int j = digit[i] + 1; j < 10; ++j)
                {
                    diff += digitCount[j] == 0;
                }
                numNoRepeatedLastDigit[i] -= diff;
                digitCount[digit[i]]++;
                if (digitCount[digit[i]] > 1) repeated = true;
            }
            
        }
        return N - sumNoRepeated - numNoRepeatedLastDigit.back();
    }
};

int main()
{
    Solution sol;

    cout << sol.numDupDigitsAtMostN(1000) << endl;
}
