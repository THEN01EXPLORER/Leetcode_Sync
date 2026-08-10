class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int l = 0;
        int right = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[l]) > abs(nums[right])) {
                ans[i] = nums[l] * nums[l];
                l++;
            } else {
                ans[i] = nums[right] * nums[right];
                right--;
            }
        }

        return ans;
    }
};