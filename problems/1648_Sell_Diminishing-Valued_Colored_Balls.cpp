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
typedef long long ll;
const int MOD = 1000000007;
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders)
    {
        unordered_map<int, int> mp; // number of balls, number of colors
        for (auto inv : inventory)
        {
            mp[inv]++;
        }

        auto comp = [](const pair<ll, ll>& a, const pair<ll, ll>& b)
        {
            return a.first < b.first;
        };
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(comp)> pq(comp);
        pq.push(make_pair(0, 0));

        for (auto x : mp)
        {
            pq.push(make_pair(x.first, x.second));
        }

        int rem = orders;
        long long ans = 0;
        while (rem)
        {
            auto cur = pq.top();
            pq.pop();

            auto next = pq.top();
            pq.pop();

            if ((cur.first - next.first) * cur.second <= rem)
            {
                long long add = cur.second * (cur.first + next.first + 1) * (cur.first - next.first) / 2;
                ans = (ans + add) % MOD;
                rem -= cur.second * (cur.first - next.first);
                pq.push(make_pair(next.first, next.second + cur.second));
            }
            else
            {
                int move = rem / cur.second;
                int r = rem % cur.second;

                long long add = cur.second * (cur.first - move + 1 + cur.first) * move / 2;
                ans = (ans + add) % MOD;
                
                add = r * (cur.first - move);
                ans = (ans + add) % MOD;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // vector<int> inventory = {2,5};
    // int orders = 4;

    // vector<int> inventory = {3,5};
    // int orders = 6;

    vector<int> inventory = {2,8,4,10,6};
    int orders = 20;

    cout << sol.maxProfit(inventory, orders) << endl;
}
