class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Convert the vector to a hash set
        std::unordered_set<int> numsSet(nums.begin(), nums.end());

        // For each number in the set
        int maxSequenceLength = 0;
        for (int num : numsSet)
        {
            // Skip if its predecessor is in the list (i.e. it is not the start of a sequence)
            if (numsSet.contains(num - 1))
            {
                continue;
            }

            // For each sequence starter, count the length of the sequence
            int current = num;
            while (numsSet.contains(++current));
            maxSequenceLength = std::max(maxSequenceLength, current - num);
        }

        //Return the max sequence length
        return maxSequenceLength;
    }
};