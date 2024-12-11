class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> ans(nums1.size());
        unordered_map<int, int> temp; 
        s.push(-1);
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int curr = nums2[i];
            while (s.size() != 1 && curr > s.top())
                s.pop();
            if (s.size() == 1) {
                temp[curr] = -1;
                s.push(curr);
            } else {
                temp[curr] = s.top();
                s.push(curr);
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            ans[i] = temp[nums1[i]];
        }
        return ans;
    }
};