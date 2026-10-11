class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int front = 0;
        int back = numbers.size() - 1;
        while (numbers[front] + numbers[back] != target)
        {
            if (numbers[front] + numbers[back] < target)
            {
                front++;
            }
            else
            {
                back--;
            }
        }
        return {front + 1, back + 1};
    }
};