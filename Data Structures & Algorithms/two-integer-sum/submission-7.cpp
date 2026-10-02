class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complementIndex;
        for (int i = 0; i < nums.size(); i++)
        {
            if (complementIndex.contains(nums[i]))
            {
                return {complementIndex[nums[i]], i};
            }
            complementIndex[target - nums[i]] = i;
        }
        return {};
    }
};
