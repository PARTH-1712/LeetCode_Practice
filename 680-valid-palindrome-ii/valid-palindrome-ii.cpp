class Solution {
public:
    bool checkPalindrome(string s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length()-1;
        while(l < r) {
            if(s[l] != s[r]) {
                return checkPalindrome(s, l+1, r) || checkPalindrome(s, l, r-1);
            }
            l++;
            r--;
        }
        return true;
    }
};