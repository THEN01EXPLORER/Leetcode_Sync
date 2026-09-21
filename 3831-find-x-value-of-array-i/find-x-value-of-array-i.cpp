class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int val = num % k;
            vector<long long> next_dp(k, 0);

            // Subarray starting at the current element
            next_dp[val] += 1;

            // Extend subarrays ending at the previous element
            for (int rem = 0; rem < k; ++rem) {
                if (dp[rem] > 0) {
                    next_dp[(rem * val) % k] += dp[rem];
                }
            }

            dp = move(next_dp);
            for (int rem = 0; rem < k; ++rem) {
                ans[rem] += dp[rem];
            }
        }

        return ans;
    }
};