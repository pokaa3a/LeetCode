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
    struct Data
    {
        vector<int> val;
        int day;
        Data(int d, int k) : day(d), val(k + 1) {}
    };

    int ans = 0;
    int maxValue(vector<vector<int>>& events, int k)
    {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b){
            return a[1] != b[1] ? a[1] < b[1] : a[0] < b[0];
        });

        vector<Data> dp;

        for (auto& event : events)
        {
            int startDay = event[0], endDay = event[1], val = event[2];

            if (dp.size() == 0)
            {
                Data x = Data(endDay, k);
                x.val[1] = val;
                dp.push_back(x);
            }
            else
            {
                int i = BS(dp, startDay);

                if (dp.back().day == endDay)
                {
                    if (i == -1)
                    {
                        dp.back().val[1] = max(dp.back().val[1], val);
                    }
                    else
                    {
                        for (int j = 1; j <= k; ++j)
                        {
                            if (j > 1 && dp[i].val[j - 1] == 0) break;
                            dp.back().val[j] = max(dp.back().val[j], dp[i].val[j - 1] + val);
                        }
                    }
                }
                else
                {
                    Data x = dp.back();
                    x.day = endDay;
                    if (i == -1)
                    {
                        x.val[1] = max(dp.back().val[1], val);
                    }
                    else
                    {
                        for (int j = 1; j <= k; ++j)
                        {
                            if (j > 1 && dp[i].val[j - 1] == 0) break;
                            x.val[j] = max(dp.back().val[j], dp[i].val[j - 1] + val);
                        }
                    }
                    dp.push_back(x);
                }
            }
            // printDP(dp);
        }

        int ans = *max_element(dp.back().val.begin(), dp.back().val.end());

        return ans;
    }

    void printDP(vector<Data>& dp)
    {
        cout << "[Print DP]" << endl;
        for (auto data : dp)
        {
            cout << "===========" << endl;
            cout << "end day: " << data.day << endl;
            for (int i = 0; i < data.val.size(); ++i)
            {
                cout << "  " << i << ": " << data.val[i] << endl;
            }
        }
    }

    int BS(vector<Data>& dp, int d)
    {
        // find largest i, s.t. dp[i].day < d
        
        int lo = 0, hi = dp.size() - 1;

        while (lo < hi)
        {
            int mi = lo + (hi - lo + 1) / 2;

            if (dp[mi].day < d)
            {
                lo = mi;
            }
            else
            {
                hi = mi - 1;
            }
        }

        if (dp[lo].day >= d) return -1;

        return lo;
    }
};


/*
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k)
    {
        sort(events.begin(), events.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });

        vector<vector<int>> prev = {{0, 0}}, cur = {{0, 0}};    // day, val

        for (int i = 0; i < k; ++i)
        {
            for (auto& e : events)
            {
                int startDay = e[0], endDay = e[1], val = e[2];
                auto it = lower_bound(prev.begin(), prev.end(), vector<int>{startDay, val});
                it = std::prev(it);
                int cand = (*it)[1] + val;

                if (prev.back()[0] == endDay) prev.back()[1] = max(prev.back()[1], cand);
                else if (cand > prev.back()[1]) prev.push_back({endDay, cand});
            }
            prev = cur;
            cur = {{0, 0}};
        }
        return prev.back()[1];
    }
};
*/

int main()
{
    Solution sol;

    // vector<vector<int>> events = {{1,2,4}, {3,4,3}, {2,3,1}};
    // vector<vector<int>> events = {{1,2,4}, {3,4,3}, {2,3,10}};
    vector<vector<int>> events = {{1,1,1}, {2,2,2}, {3,3,3}, {4,4,4}};
    // vector<vector<int>> events = {{1,3,4}, {2,4,1}, {1,1,4}, {3,5,1}, {2,5,5}};
    int k = 3;

    cout << sol.maxValue(events, k) << endl;
}
