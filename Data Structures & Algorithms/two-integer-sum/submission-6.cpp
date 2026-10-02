class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> partnerIndex;
        for (int i = 0; i < nums.size(); i++)
        {
            if (partnerIndex.contains(nums[i]))
            {
                return {partnerIndex[nums[i]], i};
            }
            partnerIndex[target - nums[i]] = i;
        }
        return {0, 0};
    }
};
