class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            // Number already seen
            if (mp.count(nums[i])) {

                // Check distance
                if (i - mp[nums[i]] <= k)
                    return true;
            }

            // Update latest index
            mp[nums[i]] = i;
        }

        return false;
    }
};