class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Convert the vector to a hash set
        std::unordered_set<int> numsSet(nums.begin(), nums.end());

        // For each number in the set
        int maxSequenceLength = 0;
        for (int num : numsSet)
        {
            // If its predecessor is not in the list (i.e. it is the start of a sequence)
            if (!numsSet.contains(num - 1))
            {
                // Count the length of the sequence and update the max if applicable
                int length = 0;
                while (numsSet.contains(num + length))
                {
                    length++;
                }
                maxSequenceLength = std::max(maxSequenceLength, length);
            }
        }

        //Return the max sequence length
        return maxSequenceLength;
    }
};