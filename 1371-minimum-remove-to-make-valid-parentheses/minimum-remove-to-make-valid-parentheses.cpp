class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        unordered_set<int> rejects;
        string res(s.size(), 'x');

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                stk.push(i);
            }
            
            if(s[i] == ')') {
                if(!stk.empty() && s[stk.top()] == '(') stk.pop();
                else rejects.insert(i);
            }
        }

        while(!stk.empty()) {
            rejects.insert(stk.top()); stk.pop();
        }

        int j = 0; 
        for(int i = 0; i < s.size(); i++) {
            if(rejects.count(i) == 0) res[j++] = s[i];
        }

        return res.substr(0, s.size() - rejects.size());
    }
};