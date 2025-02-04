class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mvp;
        int ans = 0;
        for(auto c : s)
        {
            if(mvp[c])
            {
                ans +=2;
                mvp[c] = 0;
            }
            else
            {
                mvp[c]++;
            }
        }

        if(s.size()%2 == 0 && ans == s.size())   return ans;

        return ans+1;
    }
};