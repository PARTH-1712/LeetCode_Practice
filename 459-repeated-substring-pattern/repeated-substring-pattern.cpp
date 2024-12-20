class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        vector<int> lps = calculateLPS(s);
        int len = lps[n - 1];
        return len > 0 && n % (n - len) == 0;
    }

    vector<int> calculateLPS(const string& s) {
        int n = s.length();
        vector<int> lps(n, 0);
        int length = 0;
        int i = 1;
        
        while (i < n) {
            if (s[i] == s[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps;
    }
};
