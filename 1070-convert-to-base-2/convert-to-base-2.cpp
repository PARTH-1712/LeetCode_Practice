class Solution {
public:
    string baseNeg2(int x) {
        if(x==0) return "0";
        if(x==1) return "1";
        string str="";
        while(x){
            int rem=x%(-2);
            x=x/-2;
            if (rem<0){
                rem=rem+2;
                x++;
            }
            str=to_string(rem)+str;
            
        }
        return str;
    }
};