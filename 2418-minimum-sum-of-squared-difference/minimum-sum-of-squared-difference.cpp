class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        vector<int> diff(nums1.size());
        long long total = 0;
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        long long k = (long long)k1 + k2;

        if (total <= k) return 0;

        int left = 0, right = mx;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long needed = 0;

            for (int d : diff) {
                needed += max(0, d - mid);
            }

            if (needed <= k)
                right = mid;
            else
                left = mid + 1;
        }

        int limit = left;
        long long used = 0;
        long long ans = 0;

        for (int d : diff) {
            int reduced = min(d, limit);
            used += d - reduced;
            ans += 1LL * reduced * reduced;
        }

        long long remaining = k - used;
        ans -= remaining * (2LL * limit - 1);

        return ans;
    }
};