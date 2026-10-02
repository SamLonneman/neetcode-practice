class Solution {
public:
    // Bucket sort
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        // Map each number to its frequency of appearance
        std::unordered_map<int, int> count;
        for (int num : nums)
        {
            count[num]++;
        }
        // Map each frequency to a list of numbers which appear at that frequency
        std::vector<std::vector<int>> freq(nums.size() + 1);
        for (auto p : count)
        {
            freq[p.second].push_back(p.first);
        }
        // Iterate backwards to get the numbers with the k greatest frequencies
        std::vector<int> result;
        for (int i = freq.size() - 1; i >= 0; i--)
        {
            for (int num : freq[i])
            {
                result.push_back(num);
                if (result.size() == k)
                {
                    return result;
                }
            }
        }
        return result;
    }
};