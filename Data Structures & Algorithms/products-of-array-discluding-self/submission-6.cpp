class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Let prefix[i] contain the product of all elements left of i, obtained dynamically
        std::vector<int> prefix(nums.size());
        prefix[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        // Let suffix[i] contain the product of all elements right of i, obtained dynamically
        std::vector<int> suffix(nums.size());
        suffix[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        // Let output[i] be the product of prefix[i] and suffix[i]
        std::vector<int> output(nums.size());
        for (int i = 0; i < output.size(); i++)
        {
            output[i] = prefix[i] * suffix[i];
        }
        return output;
    }
};
