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
class SparseVector {
public:
    map<int, int> _vec;  // idx -> val
    SparseVector(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                _vec[i] = nums[i];
            }
        }
    }
    
    map<int, int> getData()
    {
        return _vec;
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec)
    {
        auto _it = _vec.begin();
        auto vecMap = vec.getData();
        auto it = vecMap.begin();

        int ans = 0;
        while (_it != _vec.end() && it != vecMap.end())
        {
            int idx1 = _it->first;
            int idx2 = it->first;
            int val1 = _it->second;
            int val2 = it->second;

            if (idx1 == idx2)
            {
                ans += val1 * val2;
                _it++;
                it++;
            }
            else if (idx1 > idx2)
            {
                it++;
            }
            else if (idx1 < idx2)
            {
                _it++;
            }
        }
        return ans;
    }
};

int main()
{
    // vector<int> nums1 = {1,0,0,2,3};
    // vector<int> nums2 = {0,3,0,4,0};
    
    // vector<int> nums1 = {0,1,0,0,0};
    // vector<int> nums2 = {0,0,0,0,2};

    vector<int> nums1 = {0,1,0,0,2,0,0};
    vector<int> nums2 = {1,0,0,0,3,0,4};

    SparseVector v1(nums1);
    SparseVector v2(nums2);
    int ans = v1.dotProduct(v2);

    cout << ans << endl;
}
