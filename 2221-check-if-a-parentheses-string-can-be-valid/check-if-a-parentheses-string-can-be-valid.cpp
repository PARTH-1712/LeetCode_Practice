class Solution {
public:
    bool canBeValid(string s, string locked) {

   int n=s.size();
   if(n&1) return false;
   int mini=0,maxi=0;

   for(int i=0;i<n; i++){
    if(locked[i]=='0'){
        mini--;maxi++;
    }
    else if(s[i]=='('){
        maxi++;mini++;
    }
    else{
        mini--;maxi--;
    }
    if(maxi<0) return false;
    if(mini<0) mini=0;
   }     

return (mini==0);
    }
};