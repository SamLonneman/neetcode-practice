class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix(nums.size(), 1);
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i - 1] * nums[i];
        }
        std::vector<int> suffix(nums.size(), 1);
        suffix[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i];
        }
        std::vector<int> output(nums.size());
        output[0] = suffix[1];
        output[nums.size() - 1] = prefix[nums.size() - 2];
        for (int i = 1; i < output.size() - 1; i++)
        {
            output[i] = prefix[i - 1] * suffix[i + 1];
        }
        return output;
    }
};
