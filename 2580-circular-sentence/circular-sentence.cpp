class Solution {
public:
    bool isCircularSentence(string s) {
        if(s[0] != s.back())
            return false;
        for(int i = 0; i < s.size(); ++i) {
            while(i < s.size() && s[i] != ' ')
                ++i;
            if(i < s.size() && s[i - 1] != s[i + 1])
                return false;
        }
        return true;
    }
};