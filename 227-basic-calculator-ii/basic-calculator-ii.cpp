class Solution {
public:
    int calculate(string s) {
        int i=0, ans = 0;
        long long int curr = 0;
        char curr_op = '+';
        s += '+';

        stack<int> st;

        while(i<s.size()) {
            if(isdigit(s[i])) {
                while(isdigit(s[i]) && i<s.size()) {
                    curr = curr * 10 + s[i] - '0';
                    i++;
                }
                i--;
                if(curr_op == '+') {
                    st.push(curr);
                } else if(curr_op == '-') {
                    st.push(-curr);
                } else if(curr_op == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top*curr);
                } else if(curr_op == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top/curr);
                }
            } else if (s[i] != ' ') {
                curr_op = s[i];
            }
            curr = 0;
            i++;
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;

    }
};