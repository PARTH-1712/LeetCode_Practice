class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<pair<int, int>> numbersWithIndices;
        for (int i = 0; i < numbers.size(); i++) {
            numbersWithIndices.push_back({numbers[i], i});
        }
        sort(numbersWithIndices.begin(), numbersWithIndices.end());
        
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbersWithIndices[left].first + numbersWithIndices[right].first;
            if (sum == target) {
                return {numbersWithIndices[left].second, numbersWithIndices[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {}; 
    }
};