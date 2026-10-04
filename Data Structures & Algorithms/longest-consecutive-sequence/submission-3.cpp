class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Convert the vector to a hash set
        std::unordered_set<int> numsSet(nums.begin(), nums.end());

        // Initialize another set to track which numbers have been evaluated already
        std::unordered_set<int> seen;

        // Use the hashset to determine the length of each sequence, only eaching each number once.
        int maxSequenceLength = 0;
        for (int num : numsSet)
        {
            // If this number has already been seen, then we already know how long its sequence is
            if (seen.contains(num))
            {
                continue;
            }

            // Find the start of the sequence
            int current = num;
            while (numsSet.contains(current))
            {
                seen.insert(current--);
            }
            int start = current + 1;

            // Find the end of the sequence
            current = num + 1;
            while (numsSet.contains(current))
            {
                seen.insert(current++);
            }
            int end = current - 1;

            // Calculate the length of the sequence from the start and end
            maxSequenceLength = std::max(maxSequenceLength, end - start + 1);
        }

        // Return the resulting maximum sequence length
        return maxSequenceLength;
    }
};