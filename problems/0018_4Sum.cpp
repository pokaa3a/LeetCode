#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 3; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
            
            for (int j = i + 1; j < n - 2; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
                
                // two sum
                int lo = j + 1, hi = n - 1;
                while (lo < hi)
                {
                    int sum = nums[i] + nums[j] + nums[lo] + nums[hi];
                    
                    if (sum < target)
                    {
                        lo++;
                        while (lo < hi && nums[lo] == nums[lo - 1]) lo++;
                    }
                    else if (sum > target)
                    {
                        hi--;
                        while (lo < hi && nums[hi] == nums[hi + 1]) hi--;
                    }
                    else    // sum == target
                    {
                        ans.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        lo++;
                        while (lo < hi && nums[lo] == nums[lo - 1]) lo++;
                        hi--;
                        while (lo < hi && nums[hi] == nums[hi + 1]) hi--;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){

	int array[] = {0,0,0,0};
	vector<int> nums(array, array+4);

	int target = 0;

	Solution sol;
	vector<vector<int> > res = sol.fourSum(nums, target);

	for(int i=0; i<res.size(); i++){
		for(int j=0; j<res[i].size(); j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

}