#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>
#include <numeric>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(0, nums.size() - 1, k, nums);
    }

    int quickSelect(int lo, int hi, int k, vector<int>& nums)
    {
        if (lo == hi) return nums[lo];

        int pivot = nums[hi];
        int i = lo - 1;
        for (int j = lo; j < hi; ++j)
        {
            if (nums[j] > pivot)
            {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[hi]);
        int partition = i + 1;

        if (k <= partition - lo)
        {
            return quickSelect(lo, partition - 1, k, nums);
        }
        else if (k == partition - lo + 1)
        {
            return nums[partition];
        }
        else
        {
            return quickSelect(partition + 1, hi, k - (partition - lo + 1), nums);
        }
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
    cout << nums[k - 1] << endl;

    // cout << sol.findKthLargest(nums, k) << endl;
}