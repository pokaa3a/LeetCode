class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, 0, nums.size() - 1, k);
    }
    int helper(vector<int>& nums, int lo, int hi, int k) {
        if (lo == hi) return nums[lo];
        int pivot = nums[hi];
        
        int i = lo - 1;
        for (int j = lo; j < hi; j++) {
            if (nums[j] > pivot) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[hi]);
        int partition = i + 1;
        
        if (k <= partition - lo) {
            return helper(nums, lo, partition - 1, k);
        } else if (k == partition - lo + 1) {
            return nums[partition];
        } else {
            return helper(nums, partition + 1, hi, k - (partition - lo + 1));
        }
    }
};